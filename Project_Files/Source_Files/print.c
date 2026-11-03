#include "headers.h"

// Function to display all available book records
void viewAllBooks(BookRecord *head)
{
    // Create a temporary pointer to traverse the linked list
    BookRecord *temp = head;

    // Check whether the Book Record linked list is empty
    if(head == NULL)
    {
        printf("\033[31mBook Record is Empty\033[0m\n");
        return;
    }
    else
    {
        // Display the heading in green color
        printf("\033[32mAvailable Books\033[0m\n");

        // Display the table's top border
        printf("+--------------------------------------------------------------+\n");

        // Display the column headings
        // %-8s  : Left-align text within 8 characters
        // %-20s : Left-align text within 20 characters
        // %-15s : Left-align text within 15 characters
        printf("| %-8s | %-20s | %-15s | %-8s |\n",
               "Book ID", "Book Name", "Auther", "Quantity");

        // Display the separator line
        printf("----------------------------------------------------------------\n");

        // Traverse the linked list until the end
        while(temp)
        {
            // Display the details of the current book node
            printf("| %-8d | %-20s | %-15s | %-8d |\n",
                   temp->bookID,
                   temp->title,
                   temp->author,
                   temp->quantity);

            // Move to the next node in the linked list
            temp = temp->link;
        }

        // Display the bottom border of the table
        printf("+--------------------------------------------------------------+\n");
    }
}

// Function to display all issued book records
void listIssueBooks(IssueRecord *head)
{
    // Check whether the Issue Record linked list is empty
    if(head == NULL)
    {
        printf("\033[31mNo Book is Issue Yet\033[0m\n");
        return;
    }

    // Create a temporary pointer to traverse the linked list
    IssueRecord *temp = head;

    // Display the top border of the table
    printf("+-------------------------------------------------------------------------------------------------------------+\n");

    // Display the column headings
    printf("| %-8s | %-8s | %-8s | %-20s | %-10s | %-10s | %-10s | %-8s |\n",
           "Issue ID",
           "Book ID",
           "User ID",
           "User Name",
           "Issue Date",
           "Due Date",
           "Return Date",
           "Fine Amount");

    // Display the separator line
    printf("+-------------------------------------------------------------------------------------------------------------+\n");

    // Traverse the Issue Record linked list
    while(temp)
    {
        // Display the details of the current issued book
        printf("| %-8d | %-8d | %-8d | %-20.20s | %02d-%02d-%04d | %02d-%02d-%04d | %02d-%02d-%04d  | %-8f Rs |\n",

               // Display Issue ID, Book ID and User ID
               temp->issueID,
               temp->bookID,
               temp->userID,

               // Display User Name
               // %-20.20s limits the output to 20 characters
               temp->userName,

               // Display Issue Date in DD-MM-YYYY format
               temp->issueDate.day,
               temp->issueDate.month,
               temp->issueDate.year,

               // Display Due Date in DD-MM-YYYY format
               temp->dueDate.day,
               temp->dueDate.month,
               temp->dueDate.year,

               // Display Return Date in DD-MM-YYYY format
               temp->returnDate.day,
               temp->returnDate.month,
               temp->returnDate.year,

               // Display the fine amount
               temp->fineAmount);

        // Move to the next node in the linked list
        temp = temp->link;
    }

    // Display the bottom border of the table
    printf("+-------------------------------------------------------------------------------------------------------------+\n");
}
