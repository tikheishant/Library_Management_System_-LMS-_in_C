#include "headers.h"

// Function to update the details of an existing book
void updateBookDetail(BookRecord *head)
{
    // Check whether the book linked list is empty
    if(head == NULL)
    {
        printf("\033[31mBook Record is Empty\033[0m\n");
        return;
    }

    // Declare variables to store user input
    int ID;
    char name[20];
    int qua;
    char auth[30];
    int choise;

    // Get the Book ID from the user
    printf("Enter the book ID : ");
    scanf("%d", &ID);

    // Clear the input buffer
    __fpurge(stdin);

    // Get the book name from the user
    printf("Enter the book name : ");
    scanf("%[^\n]s", name);

    // Start traversing the book linked list
    BookRecord *temp = head;

    while(temp)
    {
        // Check whether both Book ID and Book Name match
        if((temp->bookID == ID) && (!strcmp(temp->title, name)))
        {
            // Display the menu for selecting which detail to update
            while(1)
            {
                printf("+-------------------+\n");
                printf("| 1.Book ID         |\n");
                printf("| 2.Book Name       |\n");
                printf("| 3.Author          |\n");
                printf("| 4.Quantity        |\n");
                printf("| 5.Return          |\n");
                printf("+-------------------+\n");

                // Read the user's choice
                __fpurge(stdin);
                scanf("%d", &choise);

                // Clear the input buffer
                __fpurge(stdin);

                // Perform the operation based on the user's choice
                switch(choise)
                {
                    // Update Book ID
                    case 1:
                        printf("Enter the Updated ID : ");
                        scanf("%d", &ID);
                        temp->bookID = ID;
                        break;

                    // Update Book Name
                    case 2:
                        printf("Enter the Updated Book Name : ");
                        scanf("%[^\n]s", name);
                        strcpy(temp->title, name);
                        break;

                    // Update Author Name
                    case 3:
                        printf("Enter the Updated Author name : ");
                        scanf("%[^\n]s", auth);
                        strcpy(temp->author, auth);
                        break;

                    // Update Book Quantity
                    case 4:
                        printf("Enter the Updated Quantity : ");
                        scanf("%d", &qua);
                        temp->quantity = qua;
                        break;

                    // Exit the update menu
                    case 5:
                        printf("\033[32mBook detail Updated Successfully\033[0m\n");
                        return;
                }
            }
        }

        // Move to the next node in the linked list
        temp = temp->link;
    }

    // Display message if the requested book is not found
    printf("\033[31mBook not found\033[0m\n");
    printf("\n");
}