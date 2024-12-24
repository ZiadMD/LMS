#include <iostream>
#include "LibraryManagementSystem.h"


void init_load(LibraryManagementSystem& library) {
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
        library.push_back(make_shared<BookNode>(titles[i], authors[i], genres[i], 100 + i, quantities[i]));
    }
}

int getValidInput(const string& prompt, int min, int max) {
    int choice;
    do {
        cout << prompt;
        cin >> choice;
        if (choice < min || choice > max) {
            cout << "Invalid Input! Please try again.\n";
        }
    } while (choice < min || choice > max);
    return choice;
}

void handelAdding(LibraryManagementSystem& library){
    shared_ptr<BookNode> NewBook = make_shared<BookNode>();
    system("cls");
    cout << "Book Created!\n";
    int addType = getValidInput("Enter Adding type (1. Push Back, 2. Push Front, 3. Insert): ", 1, 3);

    if (addType == 1) library.push_back(NewBook);
    else if (addType == 2) library.push_front(NewBook);
    else if (addType == 3) library.insert(NewBook, getValidInput("Enter Index: ", 0, INT_MAX));

}

void handelSearching(LibraryManagementSystem& library){
    int id = getValidInput("Enter book ID: ", 0, INT_MAX);
    shared_ptr<BookNode> book = library.searchByID(id);

    if (book) book->printBookInfo();
    else cout << "Book not found." << endl;
}

void handelSorting(LibraryManagementSystem& library){
    int type = getValidInput("Enter sorting type (1. ID, 2. Title, 3. Author, 4. Genre, 5. Quantity): ", 1, 5);
    int order = getValidInput("Enter sorting order (1. Ascending, 2. Descending): ", 1, 2);
    int algorithm = getValidInput("Enter sorting algorithm (1. Selection, 2. Merge): ", 1, 2);
    string algorithm_name = (algorithm == 1) ? "selection" : "merge";

    auto sortFunction = [&](shared_ptr<BookNode> a, shared_ptr<BookNode> b) {
        switch (type) {
            case 1 : return ((order == 1) ? a->getId() > b->getId() : a->getId() < b->getId());
            case 2 : return ((order == 1) ? a->getBookName() > b->getBookName() : a->getBookName() < b->getBookName());
            case 3 : return ((order == 1) ? a->getAuthorName() > b->getAuthorName() : a->getAuthorName() < b->getAuthorName());
            case 4 : return ((order == 1) ? a->getBookGenre() > b->getBookGenre() : a->getBookGenre() < b->getBookGenre());
            case 5 : return ((order == 1) ? a->getQuantity() > b->getQuantity() : a->getQuantity() < b->getQuantity());
            default: return false;
        }
    };

    library.sort(sortFunction, algorithm_name);
}

void handelDeleting(LibraryManagementSystem& library) {
    int id = getValidInput("Enter book Index: ", 0, INT_MAX);
    library.remove(id);
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
             << "6. Clear Library" << endl
             << "7. Exit" << endl
             << string(15, '=') << endl
             << "Enter your choice: ";
        cin >> choice;
        system("cls");

        if(choice == 1) library.display();
        else if (choice == 2) handelAdding(library);
        else if (choice == 3) handelSearching(library);
        else if (choice == 4) handelSorting(library);
        else if (choice == 5) handelDeleting(library);
        else if (choice == 6) library.clear();
        else if (choice == 7) break;
        else cout << "\tInvalid choice!\n";
    }
    return 1;
}

