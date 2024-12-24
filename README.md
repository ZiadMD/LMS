# Library Management System (LMS)

## 📚 Project Overview

The **Library Management System (LMS)** is a robust application built in **C++**, leveraging a **doubly linked list** data structure to efficiently store and manage book records. Each book is represented by the `BookNode` class, containing vital details such as the book's title, author, genre, unique ID, and quantity. The system is designed to streamline library operations through features like sorting, searching, and dynamic management of book records.

---

## ✨ Key Features

- **📖 Book Management**  
  Easily add, search, and delete books from the library's catalog.

- **⚙️ Dynamic Data Structure**  
  Employs a doubly linked list for seamless insertion and deletion of book records.

- **📊 Advanced Sorting Options**  
  Supports **Selection Sort** and **Merge Sort** to organize books by attributes such as ID, title, author, genre, or quantity in ascending or descending order.

- **🖥️ User-Friendly Console Interface**  
  Provides an intuitive console-based interface for hassle-free interaction.

- **✔️ Input Validation**  
  Ensures user inputs are validated to maintain data integrity and prevent errors.

- **📋 Book Information Display**  
  Presents book details in a well-structured, readable table format.

---

## 🚀 How to Use

1. **Display Library**: View all books currently available in the library.
2. **Add Book**: Add a new book by entering its details (title, author, genre, unique ID, and quantity).
3. **Search for a Book**: Locate a book by its unique ID and access its details.
4. **Sort Library**: Organize the library catalog by various attributes using your preferred sorting algorithm.
5. **Delete Book**: Remove a book from the catalog using its unique ID.
6. **Exit**: Close the application when finished.

---

## 🛠️ Installation

Follow these steps to set up the Library Management System on your local machine:

1. Clone the repository:
   ```bash
   git clone https://github.com/ZiadMD/LMS.git
   ```  

2. Navigate to the project directory:
   ```bash
   cd LMS
   ```  

3. Build the project:
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

---

## 🤝 Contribution

A heartfelt thanks to all team members for their invaluable contributions to this project. Your collaboration made this system possible.
