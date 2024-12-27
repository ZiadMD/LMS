#include "LibraryManagementSystem.h"

shared_ptr<BookNode> LibraryManagementSystem::getBookAtIndex(int index) {
    shared_ptr<BookNode> current;

    if (index <= length / 2) {
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    } else {
        current = tail;
        for (int i = length-1; i > index; i--) {
            current = current->prev;
        }
    }
    return current;
}

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
    if (!head) {
        cout << "Library is empty." << endl;
        cout << "Pushing the book to the end of the library." << endl;
        push_back(Book);
        return;
    }

    if (Index < 0 || Index >= length) {
        cout << "Index out of range." << endl;
        return;
    }

    if (Index == 0) {
        push_front(Book);
        return;
    }

    if (Index == length - 1) {
        push_back(Book);
        return;
    }

    shared_ptr<BookNode> current = getBookAtIndex(Index);

    // Update pointers to insert the new node
    Book->next = current;
    Book->prev = current->prev;

    current->prev->next = Book;
    current->prev = Book;

    // Increment the length of the library
    length++;
}

void LibraryManagementSystem::remove(int Index)
{
    // If the library is empty, print an error message and do nothing
    if (!head)
    {
        cout << "Library is empty." << endl;
        return;
    }
    //check the validity of the index
    if (Index < 0 || Index >= length)
    {
        cout << "Index out of range." << endl;
        return;
    }

    if (Index == 0)
    {
        pop_front();
        return;
    }

    if (Index == length - 1)
    {
        pop_back();
        return;
    }


    shared_ptr<BookNode> current = getBookAtIndex(Index);


    // If the book to be deleted is not the head or tail of the library, update the next and previous pointers of the adjacent nodes
    current->prev->next = current->next; // Set the previous node's next pointer to the next node

    current->next->prev = current->prev; // Set the next node's previous pointer to the previous node

    // Decrement the length of the library
    length--;
}

void LibraryManagementSystem::pop_back() {
    if (!head)
    {
        cout << "Library is empty." << endl;
        return;
    }
    if (head == tail) head = tail = nullptr;
    else
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    length--;
}

void LibraryManagementSystem::pop_front() {
    if (!head)
    {
        cout << "Library is empty." << endl;
        return;
    }
    if (head == tail) head = tail = nullptr;
    else
    {
        head = head->next;
        head->prev = nullptr;
    }
    length--;
}

shared_ptr<BookNode> LibraryManagementSystem::searchByID(int id)
{
    if (!head)
    {
        cout << "Library is empty." << endl;
        return nullptr;
    }

    shared_ptr<BookNode> left = head, right = tail;

    while (left && right && (left != right->next))
    {
        if (left->getId() == id) return left;
        if (right->getId() == id) return right;
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

    int IDPADDING = head->getIdPadding(),
        NAMEPADDING = head->getNamePadding(),
        AUTHORMARGEN = head->getAuthorPadding(),
        GENREMARGEN = head->getGenrePadding(),
        QMARGEN = max(head->getQuantityPadding(), 8)+1;


    cout << "+" << string(IDPADDING + 1, '-') << "+"
                << string(NAMEPADDING+1, '-') << "+"
                << string(AUTHORMARGEN+1, '-') << "+"
                << string(GENREMARGEN+1, '-') << "+"
                << string(QMARGEN, '-') << "+\n";
    // Print table header
    cout << left << "|" << setw(IDPADDING) << "ID"
         << " |" << setw(NAMEPADDING) << "Book Name"
         << " |" << setw(AUTHORMARGEN) << "Author Name"
         << " |" << setw(GENREMARGEN) << "Genre"
         << " |" << setw(QMARGEN) << "Quantity" << "|\n";
    cout << "+" << string(IDPADDING + 1, '-') << "+" << string(NAMEPADDING + 1, '-') << "+" << string(AUTHORMARGEN + 1, '-') << "+" << string(GENREMARGEN + 1, '-') << "+" << string(QMARGEN, '-') << "+\n";

    // Traverse the list and print book details
    auto temp = head;
    while (temp)
    {
        cout << left << "|" << setw(IDPADDING) << temp->getId()
             << " |" << setw(NAMEPADDING) << temp->getBookName()
             << " |" << setw(AUTHORMARGEN) << temp->getAuthorName()
             << " |" << setw(GENREMARGEN) << temp->getBookGenre()
             << " |" << setw(QMARGEN) << temp->getQuantity() << "|\n";
        temp = temp->next;
    }
    cout << "+" << string(IDPADDING + 1, '-') << "+" << string(NAMEPADDING + 1, '-') << "+" << string(AUTHORMARGEN + 1, '-') << "+" << string(GENREMARGEN + 1, '-') << "+" << string(QMARGEN, '-') << "+\n";
}

void LibraryManagementSystem::clear() {
    while (head) {
        pop_front(); // Remove the front element until the list is empty
    }
    tail.reset(); // Ensure the tail pointer is reset to nullptr
    length = 0; // Reset the length counter
    cout << "Library cleared." << endl;
}

LibraryManagementSystem::~LibraryManagementSystem() {
    clear();
}


