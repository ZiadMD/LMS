# Library Management System (LMS)

## Project Overview

The LMS is built using C++ and employs a doubly linked list data structure to store and manage book records. Each book is represented by a BookNode class, which contains essential information such as the book's name, author, genre, unique ID, and quantity. The system supports various operations, including sorting and searching, to enhance user experience and streamline library management tasks.

### Key Features

- **Book Management**: Add, search, and delete books from the library.
- **Dynamic Data Structure**: Utilizes a doubly linked list for efficient insertion and deletion of book records.
- **Sorting Algorithms**: Supports multiple sorting algorithms (Selection Sort and Merge Sort) to organize books based on different attributes (ID, title, author, genre, quantity).
- **User -Friendly Interface**: Provides a console-based interface for easy interaction with the system.
- **Input Validation**: Ensures that user inputs are validated to prevent errors and maintain data integrity.
- **Book Information Display**: Presents book details in a well-formatted table for better readability.

## How to Use

1. **Display Library**: View all the books currently in the library.
2. **Add Book**: Add a new book to the library by providing its details (name, author, genre, ID, and quantity).
3. **Search for a Book**: Find a book by its unique ID and view its details.
4. **Sort Library**: Sort the library based on various attributes (ID, title, author, genre, quantity) in either ascending or descending order using the selected sorting algorithm.
5. **Delete Book**: Remove a book from the library using its unique ID.
6. **Exit**: Close the application.

## Installation

To set up the Library Management System on your local machine, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/ZiadMD/LMS.git
   ```

2. Navigate to the project directory:
   ```bash
   cd LMS
   ```

3. Compile the project:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Run the application:
   ```bash
   ./LMS
   ```

## Contribution
I want to thank all my team members for the help in this project.