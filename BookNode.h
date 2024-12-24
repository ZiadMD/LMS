#ifndef LMS_BOOKNODE_H
#define LMS_BOOKNODE_H
#include <iostream>
#include <memory>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

class BookNode {
private:
    string bookName;
    string authorName;
    string bookGenre;
    int id; // Unique ID
    int quantity;

    static int maxNameLength, maxAuthorLength, maxGenreLength, maxIdLength, maxQuantityLength;

    // Utility to update static max lengths
    void updateMaxLengths();

    // Simplified length calculation
    int calculateLength(const string &field) const;
    int calculateLength(int field) const;

public:

    // Pointers for doubly linked list
    shared_ptr<BookNode> next, prev;

    // Constructors
    BookNode(const string &bookName, const string &authorName, const string &genre, int id, int quantity = 1);
    BookNode();

    // Getters
    string getBookName() const;
    string getAuthorName() const;
    string getBookGenre() const;
    int getQuantity() const;
    int getId() const;

    // Setters
    void setBookName(const string &bookName);
    void setAuthorName(const string &authorName);
    void setBookGenre(const string &genre);
    void setQuantity(int quantity);
    void increaseQuantity();
    void decreaseQuantity();

    // Formatting calculations
    int getNamePadding() const;
    int getAuthorPadding() const;
    int getGenrePadding() const;
    int getIdPadding() const;
    int getQuantityPadding() const;

    // Print book info
    void printBookInfo() const;
};

#endif //LMS_BOOKNODE_H
