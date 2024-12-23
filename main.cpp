#include <iostream>
#include "LibraryManagementSystem.h"


void init_load(LibraryManagementSystem& lib) {
    string titles[] = {
            "The Great Gatsby", "To Kill a Mockingbird", "1984", "Pride and Prejudice",
            "The Catcher in the Rye", "Moby-Dick", "The Lord of the Rings", "The Hobbit",
            "The Chronicles of Narnia", "War and Peace", "Crime and Punishment", "Brave New World",
            "The Alchemist", "The Odyssey", "Jane Eyre", "The Divine Comedy",
            "Wuthering Heights", "Frankenstein", "Dracula", "The Adventures of Sherlock Holmes",
            "The Kite Runner", "Les Miserables", "Anna Karenina", "Don Quixote"
    };

    string authors[] = {
            "F. Scott Fitzgerald", "Harper Lee", "George Orwell", "Jane Austen",
            "J.D. Salinger", "Herman Melville", "J.R.R. Tolkien", "J.R.R. Tolkien",
            "C.S. Lewis", "Leo Tolstoy", "Fyodor Dostoevsky", "Aldous Huxley",
            "Paulo Coelho", "Homer", "Charlotte Bronte", "Dante Alighieri",
            "Emily Bronte", "Mary Shelley", "Bram Stoker", "Arthur Conan Doyle",
            "Khaled Hosseini", "Victor Hugo", "Leo Tolstoy", "Miguel de Cervantes"
    };

    string genres[] = {
            "Fiction", "Fiction", "Dystopian", "Romance",
            "Fiction", "Adventure", "Fantasy", "Fantasy",
            "Fantasy", "Historical", "Philosophical", "Dystopian",
            "Adventure", "Epic", "Romance", "Epic",
            "Romance", "Horror", "Horror", "Mystery",
            "Fiction", "Historical", "Romance", "Adventure"
    };

    int quantities[] = {
            5, 3, 7, 4,
            6, 8, 9, 10,
            11, 12, 7, 5,
            8, 6, 4, 9,
            3, 10, 6, 8,
            7, 11, 5, 9
    };

    for (int i = 0; i < 23; ++i) {
        lib.push_back(make_shared<BookNode>(titles[i], authors[i], genres[i], 100+i, quantities[i]));
    }
}

void check_not_neg(int& number){
    cin>>number;

    while (number < 0)
    {
        if (number < 0)
            cout << "Number Must be Positive\n"
                 << "Enter number again: ";
        cin >> number;
    }
}

int main() {
    LibraryManagementSystem library;

    init_load(library);

    cout << "Welcome to the Library Management System!" << endl;
    while (true) {
        int choice;
        cout << "1. Display Library" << endl
             << "2. Add Book" << endl
             << "3. Search" << endl
             << "4. Sort Library" << endl
             << "5. Delete Book" << endl
             << "6. Exit" << endl
             << string(15, '=') << endl
             << "Enter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice) {
            case 1: {
                library.display();
                break;
            }
            case 2: {
                shared_ptr<BookNode> NewBook = make_shared<BookNode>();
                system("cls");
                cout << "Book Created!\n";
                int n;
                cout << "Enter Adding type (1. Push Back, 2. Push Front, 3. Insert): ";
                cin >> n;
                switch (n) {
                    case 1:
                        library.push_back(NewBook);
                        break;
                    case 2:
                        library.push_front(NewBook);
                        break;
                    case 3:
                        int index;
                        cout << "Enter index: ";
                        check_not_neg(index);
                        library.insert(NewBook, index);
                        break;
                    default:
                        cout << "\tInvalid choice!\n";
                        break;
                }
                break;
            }
            case 3 : {
                cout << "Enter book ID: ";
                int id;
                check_not_neg(id);
                shared_ptr<BookNode> book;
                book = library.searchByID(id);
                if (book) {
                    book->printBookInfo();
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            }
            case 4: {
                int type, order, algorithm;
                string algorithm_name;
                bool ascending;
                cout << "Enter sorting type (1. ID, 2. Title, 3. Author, 4. Genre, 5. Quantity): ";
                cin >> type;
                while (type < 1 || type > 5) {
                    if (type < 1 || type > 5)
                        cout << "Invalid choice\n"
                             << "Enter sorting type (1. ID, 2. Title, 3. Author, 4. Genre, 5. Quantity): ";
                    cin >> type;
                }

                cout << "Enter sorting order (1. Ascending, 2. Descending): ";
                cin >> order;
                while (order < 1 || order > 2) {
                    if (order < 1 || order > 2)
                        cout << "Invalid choice\n"
                             << "Enter sorting order (1. Ascending, 2. Descending): ";
                    cin >> order;
                }
                ascending = (order == 1) ? true : false;

                cout << "Enter sorting algorithm (1. Selection, 2. Merge): ";
                cin >> algorithm;
                while (algorithm < 1 || algorithm > 2) {
                    if (algorithm < 1 || algorithm > 2)
                        cout << "Invalid choice\n"
                             << "Enter sorting algorithm (1. Selection, 2. Merge): ";
                    cin >> algorithm;
                }
                algorithm_name = (algorithm == 1) ? "selection" : "merge";

                auto sortFunction = [&](shared_ptr<BookNode> a, shared_ptr<BookNode> b) {
                    switch (type) {
                        case 1 : return (ascending ? a->getId() > b->getId() : a->getId() < b->getId());
                        case 2 : return (ascending ? a->getBookName() > b->getBookName() : a->getBookName() < b->getBookName());
                        case 3 : return (ascending ? a->getAuthorName() > b->getAuthorName() : a->getAuthorName() < b->getAuthorName());
                        case 4 : return (ascending ? a->getBookGenre() > b->getBookGenre() : a->getBookGenre() < b->getBookGenre());
                        case 5 : return (ascending ? a->getQuantity() > b->getQuantity() : a->getQuantity() < b->getQuantity());
                        default: return false;
                    }
                };

                library.sort(sortFunction, algorithm_name);
                break;
            }
            case 5: {
                int id;
                cout << "Enter book ID to delete: ";
                check_not_neg(id);
                library.deleteBook(id);
                break;
            }
            case 6: {
                cout << "Exiting the program..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice\n";
                break;
            }
        }
    }
}

