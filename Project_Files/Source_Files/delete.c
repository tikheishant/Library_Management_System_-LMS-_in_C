#include "headers.h"

// Function to remove a book from the linked list using Book ID and Book Name
BookRecord *removeBook(BookRecord *head)
{
    // Check whether the book linked list is empty
    if(head == NULL)
    {
        printf("\033[31mBook Record is Empty\033[0m\n");
        return head;
    }

    int ID;
    char name[20];

    // Get the Book ID from the user
    printf("Enter the book ID : ");
    scanf("%d", &ID);

    // Get the Book Name from the user
    printf("Enter the book name : ");
    __fpurge(stdin);
    scanf("%[^\n]s", name);

    // temp is used to traverse the linked list
    // prev stores the address of the previous node
    BookRecord *temp = head;
    BookRecord *prev = head;

    // Check whether the linked list contains only one node
    if(head->link == NULL)
    {
        // Compare both Book ID and Book Name
        if((head->bookID == ID) && (!strcmp(head->title, name)))
        {
            // Free the memory allocated for the book node
            free(head);

            printf("\033[32mBook Remove Successfully\033[0m\n");

            // Return NULL because the linked list is now empty
            return NULL;
        }
    }
    else
    {
        // Traverse the linked list until the end
        while(temp)
        {
            // Check whether the current node matches the given ID and Name
            if((temp->bookID == ID) && (!strcmp(temp->title, name)))
            {
                // Connect the previous node to the next node
                // This removes the current node from the linked list
                prev->link = temp->link;

                // Release the memory occupied by the removed node
                free(temp);

                printf("\033[32mBook Remove Successfully\033[0m\n");

                // Return the updated head pointer
                return head;
            }

            // Move prev to the current node
            prev = temp;

            // Move temp to the next node
            temp = temp->link;
        }
    }

    // Display a message if no matching book is found
    printf("\033[31mBook not Found\033[0m\n");

    // Return the original head because no node was removed
    return head;
}