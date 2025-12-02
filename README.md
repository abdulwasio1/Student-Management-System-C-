# Student Management System (C++)

A complete console-based **Student Management System** built in **C++**,
featuring full CRUD operations, file persistence, searching, sorting,
and automatic grade calculation. This project demonstrates practical use
of **arrays of structures**, **file handling**, and **modular
functions**.

------------------------------------------------------------------------

## 📌 Features

### 🔵 Data Management (CRUD)

-   Add new student records\
-   View all students\
-   Update existing records\
-   Delete records by ID

### 🔵 Data Persistence

-   All records are saved in `data.txt`\
-   Automatically loads data on startup\
-   No data loss between executions

### 🔵 Search & Sort

**Search by:** - ID\
- Name (case-insensitive)\
- Grade

**Sort by:** - Name (A → Z)\
- Percentage (High → Low)\
- Age (Low → High)

### 🔵 Grade Calculation

Automatically computes: - Total marks (5 subjects)\
- Percentage\
- Grade (A, B, C, F)

------------------------------------------------------------------------

## 🛠️ Technologies Used

-   C++\
-   File I/O (`fstream`)\
-   Arrays & Structures\
-   Bubble Sort\
-   String processing\
-   Console formatting (`iomanip`)

------------------------------------------------------------------------

## 📂 File Structure

    ├── mega.cpp          # Main program file
    ├── data.txt          # Automatically generated student database
    └── README.md         # Documentation

------------------------------------------------------------------------

## 🚀 How to Run

### 1. Compile

    g++ mega.cpp -o sms

### 2. Run

Linux/macOS:

    ./sms

Windows:

    sms.exe

------------------------------------------------------------------------

## 📖 Program Menu

    1. Data Entry Module
    2. View All Students
    3. Search Students
    4. Sort Students
    5. Update Student Record
    6. Delete Student Record
    0. Exit

------------------------------------------------------------------------

## 📌 Concepts Demonstrated

-   Arrays of structures\
-   Modular programming\
-   File read/write operations\
-   Searching & sorting algorithms\
-   Case-insensitive string comparison\
-   Persistent storage logic\
-   Basic console UI design

------------------------------------------------------------------------

## 📎 Possible Future Enhancements

-   Replace arrays with `std::vector`\
-   Switch to OOP-based design\
-   Add data validation\
-   Add login/admin system\
-   Export records to CSV\
-   Improve UI with colors
