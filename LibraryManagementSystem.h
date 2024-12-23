#ifndef LMS_LIBRARYMANAGEMENTSYSTEM_H
#define LMS_LIBRARYMANAGEMENTSYSTEM_H
#include <memory>
#include <functional>
#include <iostream>
#include <iomanip>
#include <string>

#include "BookNode.h"

class LibraryManagementSystem {
private:
    shared_ptr<BookNode> head, tail;
    int length;

    /**
     * @brief Sorts the linked list of books in either ascending or descending order using selection sort.
     *
     * Example:
     * Consider a list of books with IDs: 3 -> 1 -> 4 -> 2. Using selection sort with an ascending comparator,
     * the list will be rearranged to: 1 -> 2 -> 3 -> 4.
     *
     * @param comparator A function that determines the sorting order.
     *        Example: comparator = [](shared_ptr<BookNode> a, shared_ptr<BookNode> b) { return a->getId() < b->getId(); }
     */
    void selectionSort(const function<bool(shared_ptr<BookNode>, shared_ptr<BookNode>)>& comparator);
    /**
     * @brief Splits a doubly linked list into two halves.
     *
     * Example:
     * Given a list: 1 -> 2 -> 3 -> 4 -> 5, the function splits it into:
     * First half: 1 -> 2 -> 3
     * Second half: 4 -> 5
     *
     * @param head The head of the list to split.
     * @return A shared pointer to the head of the second half.
     */
     shared_ptr<BookNode> Split(shared_ptr<BookNode> head);
    /**
     * @brief Merges two sorted doubly linked lists into one sorted list.
     *
     * Example:
     * Given two sorted lists:
     * List 1: 1 -> 3 -> 5
     * List 2: 2 -> 4 -> 6
     * The merged list will be: 1 -> 2 -> 3 -> 4 -> 5 -> 6.
     *
     * @param left The first sorted list.
     * @param right The second sorted list.
     * @param comparator A function that determines the merge order.
     * @return A shared pointer to the head of the merged list.
     */
    shared_ptr<BookNode> merge(shared_ptr<BookNode> left, shared_ptr<BookNode> right, function<bool(shared_ptr<BookNode>, shared_ptr<BookNode>)> comparator);
    /**
     * @brief Sorts a doubly linked list using merge sort.
     *
     * Example:
     * Given an unsorted list: 4 -> 2 -> 5 -> 1 -> 3, the function will sort it to: 1 -> 2 -> 3 -> 4 -> 5.
     *
     * @param head The head of the list to sort.
     * @param comparator A function that determines the sorting order.
     * @return A shared pointer to the head of the sorted list.
     */
    shared_ptr<BookNode> MergeSort(shared_ptr<BookNode> head, function<bool(shared_ptr<BookNode>, shared_ptr<BookNode>)> comparator);

public:
    LibraryManagementSystem();
    /**
     * @brief Adds a book to the front of the library.
     *
     * Example:
     * Adding a book with ID 1 to the front of a list: 2 -> 3 results in: 1 -> 2 -> 3.
     *
     * @param Book The book node to add.
     */
    void push_front(shared_ptr<BookNode> Book);
    /**
     * @brief Adds a book to the end of the library.
     *
     * Example:
     * Adding a book with ID 4 to the end of a list: 1 -> 2 -> 3 results in: 1 -> 2 -> 3 -> 4.
     *
     * @param Book The book node to add.
     */
    void push_back(shared_ptr<BookNode> Book);
    /**
     * @brief Inserts a book at a specified index.
     *
     * Example:
     * Inserting a book with ID 2 at index 1 in the list: 1 -> 3 results in: 1 -> 2 -> 3.
     *
     * @param Book The book node to insert.
     * @param Index The position to insert the book at.
     */
    void insert(shared_ptr<BookNode> Book, int Index);
    /**
    * @brief Deletes a book from the library by its ID.
    *
    * Example:
    * Deleting a book with ID 3 from the list: 1 -> 3 -> 4 results in: 1 -> 4.
    *
    * @param id The ID of the book to delete.
    */
    void deleteBook(int id);
    /**
     * @brief Finds a book by its ID.
     *
     * Example:
     * Searching for ID 2 in the list: 1 -> 2 -> 3 returns the node with ID 2.
     *
     * @param id The ID of the book to find.
     * @return A shared pointer to the book node if found, nullptr otherwise.
     */
    shared_ptr<BookNode> searchByID(int id);
    /**
     * @brief Sorts the library using the specified sorting algorithm.
     *
     * Example:
     * Calling sort with a comparator for ascending order on the list: 3 -> 1 -> 4 results in: 1 -> 3 -> 4.
     *
     * @param comparator The function that determines the sorting order.
     * @param type The sorting algorithm to use ("selection" or "merge").
     */
    void sort(function<bool(shared_ptr<BookNode>, shared_ptr<BookNode>)> comparator, string type = "selection");
    /**
     * @brief Displays the library in a tabular format.
     *
     * Example:
     * For a list of books, the function outputs a table with columns for ID, Book Name, Author Name, Genre, and Quantity.
     */
    void display();
};


#endif //LMS_LIBRARYMANAGEMENTSYSTEM_H
