#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Book {
    int id;
    string title;
    bool issued;
};

vector<Book> books;

// Load books from file
void loadBooks() {
    ifstream file("books.txt");
    if (!file) return;

    Book b;
    while (file >> b.id >> b.title >> b.issued) {
        books.push_back(b);
    }
    file.close();
}

// Save books to file
void saveBooks() {
    ofstream file("books.txt");

    for (Book b : books) {
        file << b.id << " " << b.title << " " << b.issued << endl;
    }

    file.close();
}

// Add book
void addBook() {
    Book b;

    cout << "Enter Book ID: ";
    cin >> b.id;

    cout << "Enter Book Title (no spaces): ";
    cin >> b.title;

    b.issued = false;

    books.push_back(b);

    saveBooks();

    cout << "Book added successfully!\n";
}

// Issue book
void issueBook() {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;

    for (auto &b : books) {
        if (b.id == id) {
            if (!b.issued) {
                b.issued = true;
                cout << "Book issued successfully!\n";
            } else {
                cout << "Book already issued.\n";
            }
            saveBooks();
            return;
        }
    }

    cout << "Book not found.\n";
}

// Return book
void returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    for (auto &b : books) {
        if (b.id == id) {
            if (b.issued) {
                b.issued = false;
                cout << "Book returned successfully!\n";
            } else {
                cout << "Book was not issued.\n";
            }
            saveBooks();
            return;
        }
    }

    cout << "Book not found.\n";
}

// Show available books
void showBooks() {
    cout << "\nAvailable Books:\n";

    for (Book b : books) {
        if (!b.issued) {
            cout << "ID: " << b.id << "  Title: " << b.title << endl;
        }
    }
}

int main() {

    loadBooks();

    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Show Available Books\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: issueBook(); break;
            case 3: returnBook(); break;
            case 4: showBooks(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}