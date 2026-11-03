// Structure to store book information in the Library Management System
typedef struct BookRecord
{
    int bookID;             // Stores the unique ID of the book
    char title[20];         // Stores the book title (maximum 19 characters + '\0')
    char author[30];        // Stores the author name (maximum 29 characters + '\0')
    int quantity;           // Stores the available quantity of the book

    struct BookRecord *link; // Pointer to the next BookRecord node
} BookRecord;


// Structure to store date information
typedef struct date
{
    int day;                // Stores the day
    int month;              // Stores the month
    int year;               // Stores the year
} date;


// Structure to store issued book information
typedef struct IssueRecord
{
    int issueID;            // Stores the unique issue transaction ID
    int bookID;             // Stores the ID of the issued book
    int userID;             // Stores the ID of the user who borrowed the book
    char userName[30];      // Stores the name of the user

    date issueDate;         // Stores the date on which the book was issued
    date dueDate;           // Stores the last date for returning the book
    date returnDate;        // Stores the actual date on which the book was returned

    double fineAmount;      // Stores the fine amount for late book returns

    struct IssueRecord *link; // Pointer to the next IssueRecord node
} IssueRecord;