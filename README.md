<div align="center">

# 📚 Library Management System

### A Console-Based Library Management Application Developed Using C

<p>
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C Language">
  <img src="https://img.shields.io/badge/Concept-Singly%20Linked%20List-orange?style=for-the-badge" alt="Linked List">
  <img src="https://img.shields.io/badge/Storage-File%20Handling-green?style=for-the-badge" alt="File Handling">
  <img src="https://img.shields.io/badge/Compiler-GCC-red?style=for-the-badge&logo=gnu" alt="GCC">
  <img src="https://img.shields.io/badge/Platform-Linux-lightgrey?style=for-the-badge&logo=linux" alt="Linux">
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge" alt="Status">
</p>

**Efficient Book Management | Issue & Return Tracking | Automated Fine Calculation**

</div>

---

## 📌 Overview

The **Library Management System (LMS)** is a menu-driven console application developed using the C programming language. It is designed to simplify library operations such as adding books, updating book information, searching records, issuing books, returning books, and calculating overdue fines.

The application uses **Singly Linked Lists** for dynamic record management and **File Handling** to store and retrieve data permanently.

It provides an organized approach to managing book inventories and issue records while demonstrating practical implementation of core C programming concepts.

---

## ✨ Features

### 📚 Book Management

- ➕ **Add Books:** Add new books with Book ID, title, author, and quantity.
- 📋 **View Books:** Display all available book records.
- 🔍 **Search Books:** Find books using their unique Book ID.
- ✏️ **Update Books:** Modify existing book information.
- 🗑️ **Delete Books:** Remove book records from the library.
- 📦 **Quantity Management:** Maintain available book quantities.

### 📖 Book Issue Management

- 📝 **Issue Books:** Issue available books to library users.
- 👤 **User Details:** Maintain User ID and User Name.
- 📅 **Issue Date:** Store the date on which a book is issued.
- ⏳ **Due Date:** Maintain the expected return date.
- 📋 **Issue Records:** Keep track of issued books and their details.

### 🔄 Book Return Management

- ↩️ **Return Books:** Process previously issued books.
- 📅 **Return Date:** Automatically record the return date.
- 💰 **Fine Calculation:** Calculate fines for overdue books.
- 📦 **Quantity Update:** Automatically increase available book quantity after a return.

### 💾 Data Management

- 📂 Store book records in `BookRecord.txt`.
- 📂 Store issue records in `BookIssueRecord.txt`.
- 🔄 Load previously saved records when the application starts.
- 💾 Save updated records for future execution.

---

## 🛠️ Technologies & Concepts Used

| Technology / Concept | Implementation |
|---|---|
| Programming Language | C |
| Data Structure | Singly Linked List |
| Memory Management | Dynamic Memory Allocation |
| User-Defined Types | Structures |
| Memory Operations | Pointers |
| Data Persistence | File Handling |
| File Functions | `fopen()`, `fprintf()`, `fscanf()`, `fclose()` |
| Memory Functions | `malloc()`, `free()` |
| Compiler | GCC |
| Build Automation | Makefile |
| Operating System | Linux |

---

## 🏗️ System Architecture

The application is divided into separate functional modules. Each module handles a specific library operation.

```mermaid
flowchart TD
    A([Start Application]) --> B[Load Records from Files]
    B --> C[Main Menu]

    C --> D[Book Management]
    C --> E[Issue Book]
    C --> F[Return Book]
    C --> G[Display Records]
    C --> H[Exit]

    D --> D1[Add Book]
    D --> D2[Search Book]
    D --> D3[Update Book]
    D --> D4[Delete Book]
    D1 --> C
    D2 --> C
    D3 --> C
    D4 --> C

    E --> E1[Validate Book]
    E1 --> E2[Check Availability]
    E2 --> E3[Create Issue Record]
    E3 --> E4[Update Quantity]
    E4 --> C

    F --> F1[Find Issue Record]
    F1 --> F2[Record Return Date]
    F2 --> F3[Calculate Fine]
    F3 --> F4[Update Book Quantity]
    F4 --> C

    G --> C

    H --> I[Save Records to Files]
    I --> J([Exit Application])
