#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

struct Review {
    string name;
    string comment;
    int rating;
};

struct Book {
    int id;
    string title;
    string author;
    vector<Review> reviews;

    void display_reviews() {
        if (reviews.empty()) {
            cout << "[!] This book doens't have any review yet!" << endl;
        } else {
            cout << left << setw(15) << "Name"
                     << setw(40) << "Comment"
                     << setw(6) << "Rating" << endl;
            for (size_t i = 0; i < reviews.size(); i++) {
                cout << left << setw(15) << reviews.at(i).name
                            << setw(40) << reviews.at(i).comment
                            << setw(6) << reviews.at(i).rating << endl;
            }
        }              
    }
};

struct Library {
    string name;
    vector<Book> books;

    // functions to perform opertions on books
    void add_book(Book book) {
        books.push_back(book);
        cout << "Book added successfully" << endl;
    }
    void display_books() {
        cout << left << setw(5) << "ID"
                     << setw(30) << "Name"
                     << setw(20) << "Author" << endl;
        for (size_t i = 0; i < books.size(); i++) {
            cout << left << setw(5) << books.at(i).id
                         << setw(30) << books.at(i).title
                         << setw(20) << books.at(i).author << endl;
        }
    }
    void view_book_review_by_id(int id) {
        // implement this
        bool found = false;
        for (size_t i = 0; i < books.size(); i++) {
            if (books.at(i).id == id) {
                books.at(i).display_reviews();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found" << endl;
        }
    }
 };

int main() {
    system("cls");

    // Book book;
    // book.id = 1;
    // book.title = "Harry Potter";
    // book.author = "J. K. Rowling";
    // book.display_reviews();

    // book.reviews.push_back({"Kun", "This book is good", 4});
    // book.reviews.push_back({"Ang", "So good", 5});
    // book.display_reviews();

    Library lib;
    int next_id = 1;

    while (true) {
        cout << "======== [[ Library System ]] ========" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Update book" << endl;
        cout << "3. Delete book" << endl;
        cout << "4. Display books" << endl;
        cout << "5. View book reviews" << endl;
        cout << "6. Search book by title" << endl;
        cout << "7. Review book" << endl;
        cout << "0. Exit program" << endl;

        int option;
        cout << "[-] Choose an option: ";
        cin >> option;
        if (option == 0) {
            cout << "Exting....";
            return 0;
        }

        switch (option) {
            case 1: {
                int id = next_id++;
                string title, author;

                cin.ignore();
                cout << "[+] Input book title: ";
                getline(cin, title);

                cout << "[+] Input book author: ";
                getline(cin, author);

                lib.add_book({id, title, author});
                break;
            }
            case 2: {
                break;
            }   
            case 3: {
                break;
            }
            case 4: {
                lib.display_books();
                break;
            }
            case 5: {

                int id;
                cout << "[+] Enter book id: ";
                cin >> id;

                lib.view_book_review_by_id(id);

                break;
            }
            case 6: {
                break;
            } 
            default: {
                cout << "Invalid option" << endl;
                cout << "Try again!" << endl;
            }       
        }

    }

}