#include "headers.h"

// ---------------- FUNCTION DECLARATIONS ----------------

// Book functions
BookRecord *addNewBook(BookRecord *);
BookRecord *removeBook(BookRecord *);
void updateBookDetail(BookRecord *);
void searchBook(BookRecord *);
void viewAllBooks(BookRecord *);

// Issue functions
IssueRecord *issueBook(IssueRecord *, BookRecord *);
void returnBook(IssueRecord *, BookRecord *);
void listIssueBooks(IssueRecord *);

// File handling functions
void save(BookRecord *, IssueRecord *);
void SyncFromFile(BookRecord **, IssueRecord **);


// ---------------- MAIN FUNCTION ----------------

int main()
{
    // Declare the login password
    int savePass = 3432;

    // Declare the login User ID
    char uId[] = "Record@980";

    // Variables to store login details entered by the user
    int tempPass;
    char tempUID[20];

    // Variable to store the user's menu choice
    int choice;

    // Initialize both linked list head pointers to NULL
    BookRecord *BR = NULL;
    IssueRecord *IR = NULL;

    // Load previously saved book and issue records from files
    // Addresses of head pointers are passed so SyncFromFile()
    // can modify the original head pointers
    SyncFromFile(&BR, &IR);

    // ---------------- USER AUTHENTICATION ----------------

    // Ask the user to enter the User ID
    printf("Enter the User ID  : ");
    scanf("%[^\n]s", tempUID);

    // Ask the user to enter the password
    printf("Enter the Password : ");
    scanf("%d", &tempPass);

    // Compare the entered password and User ID with stored credentials
    if((tempPass == savePass) && (!strcmp(uId, tempUID)))
    {
        // Continue displaying the menu until the user chooses Exit
        while(1)
        {
            // Set the menu heading color to bold cyan
            printf("\033[1;36m");

            // Display the menu heading and top border
            printf("+----------------------------------------+\n");
            printf("|         Book Management Menu           |\n");
            printf("|----------------------------------------|\n");

            // Reset text formatting
            printf("\033[0m");

            // Set the menu options color to cyan
            printf("\033[36m");

            // Display all available menu options
            printf("| 1. Add New Book                        |\n");
            printf("| 2. Update Book Details                 |\n");
            printf("| 3. Remove Book                         |\n");
            printf("| 4. Search Book                         |\n");
            printf("| 5. View All Books                      |\n");
            printf("| 6. Issue Book                          |\n");
            printf("| 7. Return Book                         |\n");
            printf("| 8. List Issued Books                   |\n");
            printf("| 9. Save                                |\n");
            printf("| 10. Exit                               |\n");
            printf("+----------------------------------------+\n");

            // Reset text formatting to default
            printf("\033[0m");

            // Clear the input buffer before reading the menu choice
            __fpurge(stdin);

            // Read the menu choice entered by the user
            scanf("%d", &choice);

            // Execute the selected operation
            switch(choice)
            {
                // Add a new book to the Book Record linked list
                case 1:
                    BR = addNewBook(BR);
                    break;

                // Update the details of an existing book
                case 2:
                    updateBookDetail(BR);
                    break;

                // Remove a book from the Book Record linked list
                case 3:
                    BR = removeBook(BR);
                    break;

                // Search for a book using its details
                case 4:
                    searchBook(BR);
                    break;

                // Display all available books
                case 5:
                    viewAllBooks(BR);
                    break;

                // Issue a book and update the Issue Record linked list
                case 6:
                    IR = issueBook(IR, BR);
                    break;

                // Return an issued book and update the records
                case 7:
                    returnBook(IR, BR);
                    break;

                // Display all issued book records
                case 8:
                    listIssueBooks(IR);
                    break;

                // Save both linked lists into their respective files
                case 9:
                    save(BR, IR);
                    break;

                // Save all records and terminate the program
                case 10:
                    save(BR, IR);
                    exit(0);
            }
        }
    }
    else
    {
        // Display an error message if the login credentials are incorrect
        printf("\033[31mWrong ID or Password\033[0m\n");
    }
}
