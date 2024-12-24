#include "LibraryManagementSystem.h"

void LibraryManagementSystem::selectionSort(const function<bool(shared_ptr<BookNode>, shared_ptr<BookNode>)>& comparator){
    if (!head) return;

    auto current = head;
    while (current)
    {
        auto minOrMax = current;
        auto next = current->next;

        while (next)
        {
            if (comparator(minOrMax, next)) minOrMax = next;
            next = next->next;
        }

        if (minOrMax != current){
            if (minOrMax->prev) minOrMax->prev->next = minOrMax->next;
            if (minOrMax->next) minOrMax->next->prev = minOrMax->prev;

            if (current == head) head = minOrMax;

            minOrMax->prev = current->prev;
            minOrMax->next = current;

            if (current->prev) current->prev->next = minOrMax;
            current->prev = minOrMax;
            current = minOrMax;
        }

        current = current->next;

    }

}

shared_ptr<BookNode> LibraryManagementSystem::Split(shared_ptr<BookNode> head){
    auto slow = head;
    auto fast = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    auto temp = slow->next;
    slow->next = nullptr;
    if (temp != nullptr ) temp->prev = nullptr;
    return temp;
}

shared_ptr<BookNode> LibraryManagementSystem::merge(shared_ptr<BookNode> left, shared_ptr<BookNode> right, function<bool(shared_ptr<BookNode>, shared_ptr<BookNode>)> comparator){
    if (!left) return right;
    if (!right) return left;

    if (comparator(left, right)){
        right->next = merge(left, right->next, comparator);
        if (right->next) right->next->prev = right;
        right->prev = nullptr;
        return right;
    }
    else{
        left->next = merge(left->next, right, comparator);
        if (left->next) left->next->prev = left;
        left->prev = nullptr;
        return left;
    }
}

shared_ptr<BookNode> LibraryManagementSystem::MergeSort(shared_ptr<BookNode> head, function<bool(shared_ptr<BookNode>, shared_ptr<BookNode>)> comparator){
    if (!head || !head->next) return head;

    auto mid = Split(head);

    head = MergeSort(head, comparator);
    mid = MergeSort(mid, comparator);

    return merge(head, mid, comparator);
}

LibraryManagementSystem::LibraryManagementSystem() : head(nullptr), tail(nullptr), length(0){}

void LibraryManagementSystem::push_front(shared_ptr<BookNode> Book)
{
    if (!head)
    {
        head = tail = Book;
    }
    else
    {

        Book->next = head;
        head->prev = Book;
        head = Book;
    }
    length++;
}

void LibraryManagementSystem::push_back(shared_ptr<BookNode> Book)
{
    if (!head)
    {
        head = tail = Book;
    }
    else
    {
        Book->prev = tail;
        tail->next = Book;
        tail = Book;
    }
    length++;
}

void LibraryManagementSystem::insert(shared_ptr<BookNode> Book, int Index) {
    if(Index > length) {
        cout << "Index out of range." << endl;
        cout << "Pushing the book to the end of the library." << endl;
        push_back(Book);
        return;
    }
    shared_ptr<BookNode> current;

    // Choosing the traversal direction based on the index
    if (Index <= length / 2)
    {
        // Traverse from the head
        current = head;
        for (int i = 1; i < Index; ++i) current = current->next;
    }
    else
    {
        // Traverse from the tail
        current = tail;
        for (int i = length; i > Index; --i) current = current->prev;
    }

    // Update pointers to insert the new node
    Book->next = current;
    Book->prev = current->prev;

    if (current->prev) current->prev->next = Book;
    current->prev = Book;

    // Increment the length of the library
    length++;
}

void LibraryManagementSystem::deleteBook(int id)
{
    // If the library is empty, print an error message and do nothing
    if (!head)
    {
        cout << "Library is empty." << endl;
        return;
    }

    // Find the node in the library with the given ID
    shared_ptr<BookNode> current = searchByID(id);

    // If the book is not found, print an error message and do nothing
    if (!current)
    {
        cout << "Book not found." << endl;
        return;
    }

    // If the book to be deleted is the head of the library, update the head
    if (current == head) head = current->next; // Set the new head to the next node


    // If the book to be deleted is the tail of the library, update the tail
    if (current == tail) tail = current->prev; // Set the new tail to the previous node

    // If the book to be deleted is not the head or tail of the library, update the next and previous pointers of the adjacent nodes
    if (current->prev) current->prev->next = current->next; // Set the previous node's next pointer to the next node

    if (current->next) current->next->prev = current->prev; // Set the next node's previous pointer to the previous node

    // Decrement the length of the library
    length--;
}

shared_ptr<BookNode> LibraryManagementSystem::searchByID(int id)
{
    if (!head || !tail)
    {
        cout << "Library is empty." << endl;
        return nullptr;
    }

    shared_ptr<BookNode> left = head, right = tail;

    while (left && right && left != right->next)// Stop when pointers cross or meet
    {
        // Check if the book with the given ID was found by the forward traversal
        if (left->getId() == id) return left; // Found by forward traversal

        // Check if the book with the given ID was found by the backward traversal
        if (right->getId() == id) return right; // Found by backward traversal

        // Move the pointers
        left = left->next;
        right = right->prev;
    }

    return nullptr; // Book not found
}

void LibraryManagementSystem::sort(function<bool(shared_ptr<BookNode>, shared_ptr<BookNode>)> comparator, string type){
    if (type == "selection") selectionSort(comparator);

    if (type == "merge"){
        head = MergeSort(head, comparator);
        auto current = head;
        while (current->next) current = current->next;
        tail = current;
    }


}

void LibraryManagementSystem::display()
{
    if (!head)
    {
        cout << "The library is empty." << endl;
        return;
    }

    int IDMARGIN = head->getIdPadding(),
        NAMEMARGEN = head->getNamePadding(),
        AUTHORMARGEN = head->getAuthorPadding(),
        GENREMARGEN = head->getGenrePadding(),
        QMARGEN = max(head->getQuantityPadding(), 8)+1;


    cout << "+" << string(IDMARGIN+1, '-') << "+"
                << string(NAMEMARGEN+1, '-') << "+"
                << string(AUTHORMARGEN+1, '-') << "+"
                << string(GENREMARGEN+1, '-') << "+"
                << string(QMARGEN, '-') << "+\n";
    // Print table header
    cout << left << "|" << setw(IDMARGIN) << "ID"
         << " |" << setw(NAMEMARGEN) << "Book Name"
         << " |" << setw(AUTHORMARGEN) << "Author Name"
         << " |" << setw(GENREMARGEN) << "Genre"
         << " |" << setw(QMARGEN) << "Quantity" << "|\n";
    cout << "+" << string(IDMARGIN+1, '-') << "+" << string(NAMEMARGEN+1, '-') << "+" << string(AUTHORMARGEN+1, '-') << "+" << string(GENREMARGEN+1, '-') << "+" << string(QMARGEN, '-') << "+\n";

    // Traverse the list and print book details
    auto temp = head;
    while (temp)
    {
        cout << left << "|" << setw(IDMARGIN) << temp->getId()
             << " |" << setw(NAMEMARGEN) << temp->getBookName()
             << " |" << setw(AUTHORMARGEN) << temp->getAuthorName()
             << " |" << setw(GENREMARGEN) << temp->getBookGenre()
             << " |" << setw(QMARGEN) << temp->getQuantity() << "|\n";
        temp = temp->next;
    }
    cout << "+" << string(IDMARGIN+1, '-') << "+" << string(NAMEMARGEN+1, '-') << "+" << string(AUTHORMARGEN+1, '-') << "+" << string(GENREMARGEN+1, '-') << "+" << string(QMARGEN, '-') << "+\n";
}

void LibraryManagementSystem::clear() {
    head.reset();
    tail.reset();
    length = 0;

    cout << "Library cleared. All books have been removed." << std::endl;
}


