#include <iostream>
#include <string>
#include <vector>
using namespace std;
    
//класс с книгами
class book {
protected:
    std::string name;
    std::string author;
    int yearOfPub;
    bool available;
    //параметры книг

public:
    //конструктор
    book(std::string book_name, std::string book_author, int year, bool isAvailable)
        : name(book_name), author(book_author), yearOfPub(year), available(isAvailable) {}
    
    void get_info() {
        //вызов информаций о книге
        std::cout << "Book Name: " << name << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Year of Publication: " << yearOfPub << std::endl;
        std::cout << "Available: " << (available ? "Yes" : "No") << std::endl;
    }

   
};
class library{
private:
    std::vector<book> PackOfBooks{
        book("Call of Cthulhu", "Howard Lovecraft", 1928, true),
        book("Crime and Punishment", "Fedor Dostoevsky", 1866, true),
        book("Thus Spoke Zarathustra", "FFriedrich Nietzsche", 1892, true),
        book("Divine Comedy", "Dante Alighieri", 1321, true),
        book("Norwegian Wood", " Haruki Murakami", 1981, true),
    };
public:
    void display_books() {
        for (size_t i = 0; i < PackOfBooks.size(); ++i) {
            std::cout << "Book #" << i + 1 << std::endl;
            PackOfBooks[i].get_info();
            std::cout << "---------------------" << std::endl;
        }
    }
    void add_book(const book& newBook) {
        PackOfBooks.push_back(newBook);
    }

 
};


int main() {
    string na, ga;
    string function;
    library myLibrary;
    myLibrary.display_books();
    cout << "What do you want to do? \n/add = add book \n/ret = return the book \n/take = take a book";
    cin >> function;
    switch (function[1]) {
    case '/add':
    {
        std::string name, author;
        int year;
        bool available;
        
        std::cout << "Enter the book name: ";
        std::cin >> name;
        std::cout << "Enter the author name: ";
        std::cin >> author;
        std::cout << "Enter the year of publication: ";
        std::cin >> year;
        available = true;

      
        book newBook(name, author, year, available);
        myLibrary.add_book(newBook);
    }
    break;
    case '/ret':
        cout << "Name of the book?";
        cin >> na;
      
      
        break;
    case 'take':
        cout << "Name of the book?";
        cin >> ga;
        break;
    default:
        std::cout << "Invalid command." << std::endl;
        break;
    }
    return 0;
}
