#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    std::string name;
    std::string author;
    int yearOfPub;
    bool available;

public:
    Book(std::string book_name, std::string book_author, int year, bool isAvailable)
        : name(book_name), author(book_author), yearOfPub(year), available(isAvailable) {}

    void get_info() const {
        std::cout << "Book Name: " << name << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Year of Publication: " << yearOfPub << std::endl;
        std::cout << "Available: " << (available ? "Yes" : "No") << std::endl;
    }

    void toggleAvailability() {
        available = !available;
    }

    const std::string& getName() const {
        return name;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    Library() {
        books = {
            Book("Call of Cthulhu", "Howard Lovecraft", 1928, true),
            Book("Crime and Punishment", "Fedor Dostoevsky", 1866, true),
            Book("Thus Spoke Zarathustra", "Friedrich Nietzsche", 1892, true),
            Book("Divine Comedy", "Dante Alighieri", 1321, true),
            Book("Norwegian Wood", "Haruki Murakami", 1981, true),
        };
    }

    void displayBooks() const {
        for (size_t i = 0; i < books.size(); ++i) {
            std::cout << "Book #" << i + 1 << std::endl;
            books[i].get_info();
            std::cout << "---------------------" << std::endl;
        }
    }

    void addBook(const Book& newBook) {
        books.push_back(newBook);
    }

    Book* findBookByName(const std::string& name) {
        for (auto& book : books) {
            if (book.getName() == name) {
                return &book;
            }
        }
        return nullptr;
    }
};

int main() {
    string function;
    string name;
    Library myLibrary;
    myLibrary.displayBooks();

    cout << "What do you want to do?" << endl;
    cout << "/add = add book" << endl;
    cout << "/ret = return or take a book" << endl;
    cin >> function;

    if (function == "/add") {
        std::string name, author;
        int year;
        bool available = true;

        std::cout << "Enter the book name: ";
        std::cin >> name;
        std::cout << "Enter the author name: ";
        std::cin >> author;
        std::cout << "Enter the year of publication: ";
        std::cin >> year;

        Book newBook(name, author, year, available);
        myLibrary.addBook(newBook);
    }
    else if (function == "/ret") {
        cout << "Name of the book? ";
        cin >> name;
        Book* foundBook = myLibrary.findBookByName(name);
        if (foundBook) {
            foundBook->toggleAvailability();
            cout << "Book availability changed." << endl;
        }
        else {
            cout << "Book not found." << endl;
        }
    }
    else {
        std::cout << "Invalid command." << std::endl;
    }

    return 0;
}
