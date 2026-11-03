#include "headers.h"

// Function to search for a book using Book ID and Book Name
void searchBook(BookRecord *head)
{
    // Check whether the book linked list is empty
    if(head == NULL)
    {
        printf("Book Record is Empty\n");
        return;
    }

    // Declare variables to store the Book ID and Book Name
    int ID;
    char name[20];

    // Get the Book ID from the user
    printf("Enter the Book ID : ");
    scanf("%d", &ID);

    // Clear the input buffer
    __fpurge(stdin);

    // Get the Book Name from the user
    printf("Enter the Book Name : ");
    scanf("%[^\n]s", name);

    // Create a temporary pointer to traverse the linked list
    BookRecord *temp = head;

    // Traverse the linked list until the end
    while(temp)
    {
        // Check whether both Book ID and Book Name match
        if((temp->bookID == ID) && (!strcmp(temp->title, name)))
        {
            // Change the text color to green
            printf("\033[32m\n");

            // Display the matching book details
            printf("*********************************\n");
            printf("*  Book ID     : %d\n", temp->bookID);
            printf("*  Book Name   : %s\n", temp->title);
            printf("*  Author Name : %s\n", temp->author);
            printf("*  Quantity    : %d\n", temp->quantity);
            printf("*********************************\n");

            // Reset the text color to default
            printf("\033[0m\n");

            // Stop searching after finding the book
            return;
        }

        // Move to the next node in the linked list
        temp = temp->link;
    }
}