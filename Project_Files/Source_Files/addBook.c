#include "headers.h"

// Function to add a new book node to the linked list
BookRecord *addNewBook(BookRecord *head)
{
    // Dynamically allocate memory for a new BookRecord node
    // calloc initializes all allocated memory bytes to zero
    BookRecord *newnode = calloc(1, sizeof(BookRecord));

    // Check whether memory allocation was successful
    if(newnode == NULL)
    {
        printf("\033[31mNode Not Created\033[0m\n");

        // Return the existing head if memory allocation fails
        return head;
    }

    // Read the Book ID from the user
    printf("Enter the book ID : ");
    scanf("%d", &newnode->bookID);

    // Read the Book Name
    printf("Enter the new Book name : ");
    __fpurge(stdin);
    scanf("%[^\n]s", newnode->title);

    // Read the Author Name
    printf("Enter the Author Name : ");
    __fpurge(stdin);
    scanf("%[^\n]s", newnode->author);

    // Read the available quantity of the book
    printf("Enter the available Quantity : ");
    scanf("%d", &newnode->quantity);

    // Check whether the linked list is empty
    if(head == NULL)
    {
        // Make the new node the first node of the linked list
        head = newnode;
    }
    else
    {
        // Create a temporary pointer to traverse the linked list
        BookRecord *temp = head;

        // Traverse until the last node is reached
        // The last node contains NULL in its link field
        while(temp->link)
        {
            temp = temp->link;
        }

        // Connect the last node to the newly created node
        temp->link = newnode;
    }

    // Return the updated head pointer to the calling function
    return head;
}