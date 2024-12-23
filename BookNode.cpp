#include "BookNode.h"

int BookNode::maxNameLength = 0;
int BookNode::maxAuthorLength = 0;
int BookNode::maxGenreLength = 0;
int BookNode::maxIdLength = 0;
int BookNode::maxQuantityLength = 0;

// Utility to update static max lengths
void BookNode::updateMaxLengths() {
    maxNameLength = max(maxNameLength, calculateLength(bookName));
    maxAuthorLength = max(maxAuthorLength, calculateLength(authorName));
    maxGenreLength = max(maxGenreLength, calculateLength(bookGenre));
    maxIdLength = max(maxIdLength, calculateLength(id));
    maxQuantityLength = max(maxQuantityLength, calculateLength(quantity));
}

// Simplified length calculation
int BookNode::calculateLength(const string &field) const {
    return static_cast<int>(field.length());
}

int BookNode::calculateLength(int field) const {
    return static_cast<int>(to_string(field).length());
}

// Constructors
BookNode::BookNode(const string &bookName, const string &authorName, const string &genre, int id, int quantity)
        : bookName(bookName), authorName(authorName), bookGenre(genre), id(id), quantity(quantity), next(nullptr), prev(nullptr) {
    updateMaxLengths();
}

BookNode::BookNode() : next(nullptr), prev(nullptr) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    cout << "Enter book name: ";
    getline(cin, bookName);
    cout << "Enter author name: ";
    getline(cin, authorName);
    cout << "Enter genre: ";
    getline(cin, bookGenre);
    cout<< "Enter ID: ";
    cin>>id;
    cout << "Enter quantity: ";
    cin >> quantity;

    updateMaxLengths();
}

// Getters
const string &BookNode::getBookName() const { return bookName; }
const string &BookNode::getAuthorName() const { return authorName; }
const string &BookNode::getBookGenre() const { return bookGenre; }
int BookNode::getQuantity() const { return quantity; }
int BookNode::getId() const { return id; }

// Formatting calculations
int BookNode::getNamePadding() const { return maxNameLength; }
int BookNode::getAuthorPadding() const { return maxAuthorLength; }
int BookNode::getGenrePadding() const { return maxGenreLength; }
int BookNode::getIdPadding() const { return maxIdLength; }
int BookNode::getQuantityPadding() const { return maxQuantityLength; }

// Setters
void BookNode::setBookName(const string &bookName) { this->bookName = bookName; }
void BookNode::setAuthorName(const string &authorName) { this->authorName = authorName; }
void BookNode::setBookGenre(const string &genre) { this->bookGenre = genre; }

void BookNode::setQuantity(int quantity) {
    if (quantity >= 0) {
        this->quantity = quantity;
    } else {
        cout << "Invalid quantity: must be non-negative." << endl;
    }
}

void BookNode::increaseQuantity() { quantity++; }

void BookNode::decreaseQuantity() {
    if (quantity > 0) {
        quantity--;
    } else {
        cout << "No books left in the library." << endl;
    }
}

// Print book info
void BookNode::printBookInfo() const {
    cout << "Book Information:" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << bookName << endl;
    cout << "Author: " << authorName << endl;
    cout << "Genre: " << bookGenre << endl;
    cout << "Quantity: " << quantity << endl;
}