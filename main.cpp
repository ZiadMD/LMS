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
        lib.push_back(make_shared<BookNode>(titles[i], authors[i], genres[i], 100+i, quantities[i]))
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
    while (true)
    {
        int choice;
        cout << string(15, '=') << endl
             << "1. Display Library" << endl
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
            case 1:
                library.display();
                break;
            case 2:

        }


        if (choice == 1)library.display();
            // Add
        else if (choice == 2)
        {
            int number, id;
            cout << "How many books u want to add: ";
            check_not_neg(number);


            for (int i = 0; i < number; i++)
            {
                // random val for id
                cout << "Enter book ("<<i+1<<") ID: ";
                cin >> id;

                while (id < 0 || library.searchByID(id))
                {
                    if (id < 0)
                        cout << "ID must be positive. Enter again: ";
                    else
                        cout << "ID already exists. Enter a unique ID: ";
                    cin >> id;
                }


                auto tempBook = make_shared<BookNode>(id);
                library.push_back(tempBook);
            }
        }
            // Search
        else if (choice == 3)
        {
            int id;
            cout << "Enter book id: ";
            cin>>id;
            while (id < 0)
            {
                if (id < 0)
                    cout << "Invalid number\n"
                         << "Enter book id: ";
                cin >> id;
            }

            shared_ptr<BookNode> book = library.searchByID(id);
            if (book)
            {
                book->printBookInfo();
            }
            else
            {
                cout << "Book not found." << endl;
            }
        }
            // Sorting
        else if (choice == 4)
        {
            string sorting;
            int type, order;
            bool ascending;

            cout << "1. Selection Sort (selection)" << endl;
            cout << "2. Merge Sort (merge)" << endl;
            cout << "Enter sorting type: ";
            cin >> sorting;
            sorting = (sorting == "1" ? "selection" : sorting == "2" ? "merge" : "selection");
            cout<<"Sort with:\n" << "1. ID\n" << "2. Book Name\n" << "3. Author Name\n" << "4. Genre\n" << "5. Quantity" << endl;
            cout << "Enter : ";
            cin >> type;
            cout<< "1.Ascending\n2.Descending\nEnter: ";
            cin>> order;
            ascending = (order == 1) ? true : false;

            if (type == 1)
                library.sort([&](shared_ptr<BookNode> a, shared_ptr<BookNode> b) { return ascending ? a->getId() > b->getId() : a->getId() < b->getId(); }, sorting);
            else if (type == 2)
                library.sort([&](shared_ptr<BookNode> a, shared_ptr<BookNode> b) { return ascending ? a->getBookName() > b->getBookName() : a->getBookName() < b->getBookName(); }, sorting);
            else if (type == 3)
                library.sort([&](shared_ptr<BookNode> a, shared_ptr<BookNode> b) { return ascending ? a->getAuthorName() > b->getAuthorName() : a->getAuthorName() < b->getAuthorName(); }, sorting);
            else if (type == 4)
                library.sort([&](shared_ptr<BookNode> a, shared_ptr<BookNode> b) { return ascending ? a->getBookGenre() > b->getBookGenre() : a->getBookGenre() < b->getBookGenre(); }, sorting);
            else if (type == 5)
                library.sort([&](shared_ptr<BookNode> a, shared_ptr<BookNode> b) { return ascending ? a->getQuantity() > b->getQuantity() : a->getQuantity() < b->getQuantity(); }, sorting);
        }
            // Deleting
        else if (choice == 5)
        {
            int id;
            cout << "Enter book id: ";
            cin>>id;
            while (id < 0)
            {
                if (id < 0)
                    cout << "Invalid number\n"
                         << "Enter book id: ";
                cin >> id;
            }
            library.DeleteBook(id);
        }
            // Exit
        else if (choice == 6)
        {
            cout << "Goodbye!" << endl;
            break;
        }
    }
}
