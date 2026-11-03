#include "headers.h"

void save(BookRecord *BR, IssueRecord *IR)
{
    FILE *fp;

    // Create temporary pointers to traverse both linked lists
    BookRecord *temp1 = BR;
    IssueRecord *temp2 = IR;

    // ---------------- SAVE BOOK RECORDS ----------------

    // Open the BookRecord.txt file in write mode
    // Existing contents will be overwritten
    fp = fopen("BookRecord.txt", "w");

    // Check whether the file was opened successfully
    if(fp == NULL)
    {
        printf("Book File Not Opened\n");
        return;
    }

    // Traverse the Book Record linked list
    while(temp1 != NULL)
    {
        // Write Book ID, Title, Author and Quantity into the file
        // The pipe (|) separates individual fields
        fprintf(fp, "%d|%s|%s|%d\n",
                temp1->bookID,
                temp1->title,
                temp1->author,
                temp1->quantity);

        // Move to the next book node
        temp1 = temp1->link;
    }

    // Close the BookRecord.txt file
    fclose(fp);


    // ---------------- SAVE ISSUE RECORDS ----------------

    // Open the BookIssueRecord.txt file in write mode
    // Existing contents will be overwritten
    fp = fopen("BookIssueRecord.txt", "w");

    // Check whether the file was opened successfully
    if(fp == NULL)
    {
        printf("Issue File Not Opened\n");
        return;
    }

    // Traverse the Issue Record linked list
    while(temp2 != NULL)
    {
        // Write issue details, dates and fine amount into the file
        // Each field is separated by a pipe (|)
        fprintf(fp, "%d|%d|%d|%s|"
                    "%d|%d|%d|"
                    "%d|%d|%d|"
                    "%d|%d|%d|%.2f\n",

                // Issue and book identification details
                temp2->issueID,
                temp2->bookID,
                temp2->userID,
                temp2->userName,

                // Issue date
                temp2->issueDate.day,
                temp2->issueDate.month,
                temp2->issueDate.year,

                // Due date
                temp2->dueDate.day,
                temp2->dueDate.month,
                temp2->dueDate.year,

                // Return date
                temp2->returnDate.day,
                temp2->returnDate.month,
                temp2->returnDate.year,

                // Fine amount (two digits after decimal point)
                temp2->fineAmount);

        // Move to the next issue node
        temp2 = temp2->link;
    }

    // Close the BookIssueRecord.txt file
    fclose(fp);

    // Display success message after saving both files
    printf("Records Saved Successfully\n");
}


// ---------------- LOAD RECORDS FROM FILE ----------------
void SyncFromFile(BookRecord **BR, IssueRecord **IR)
{
    FILE *fp;

    // Pointers used to create new nodes
    BookRecord *newBook;
    BookRecord *bookTail = NULL;

    IssueRecord *newIssue;
    IssueRecord *issueTail = NULL;


    // ---------------- READ BOOK RECORDS ----------------

    // Open the BookRecord.txt file in read mode
    fp = fopen("BookRecord.txt", "r");

    // Check whether the file exists and opened successfully
    if(fp != NULL)
    {
        // Read book records until the end of the file
        while(1)
        {
            // Dynamically allocate memory for a new BookRecord node
            newBook = malloc(sizeof(BookRecord));

            // Stop if memory allocation fails
            if(newBook == NULL)
                break;

            // Read Book ID, Title, Author and Quantity from the file
            // Maximum title length = 19 characters
            // Maximum author length = 29 characters
            if(fscanf(fp, "%d|%19[^|]|%29[^|]|%d",
                      &newBook->bookID,
                      newBook->title,
                      newBook->author,
                      &newBook->quantity) != 4)
            {
                // Free allocated memory if record reading fails
                free(newBook);
                break;
            }

            // Initialize the link pointer of the new node
            newBook->link = NULL;

            // Check whether the linked list is empty
            if(*BR == NULL)
            {
                // Make the new node the first node
                *BR = newBook;
            }
            else
            {
                // Attach the new node at the end of the linked list
                bookTail->link = newBook;
            }

            // Update the tail pointer to the newly inserted node
            bookTail = newBook;
        }

        // Close the BookRecord.txt file
        fclose(fp);
    }


    // ---------------- READ ISSUE RECORDS ----------------

    // Open the BookIssueRecord.txt file in read mode
    fp = fopen("BookIssueRecord.txt", "r");

    // Check whether the file exists and opened successfully
    if(fp != NULL)
    {
        // Read issue records until the end of the file
        while(1)
        {
            // Dynamically allocate memory for a new IssueRecord node
            newIssue = malloc(sizeof(IssueRecord));

            // Stop if memory allocation fails
            if(newIssue == NULL)
                break;

            // Read issue details, dates and fine amount from the file
            if(fscanf(fp,
                "%d|%d|%d|%29[^|]|"
                "%d|%d|%d|"
                "%d|%d|%d|"
                "%d|%d|%d|%lf",

                // Issue and book identification details
                &newIssue->issueID,
                &newIssue->bookID,
                &newIssue->userID,
                newIssue->userName,

                // Issue date
                &newIssue->issueDate.day,
                &newIssue->issueDate.month,
                &newIssue->issueDate.year,

                // Due date
                &newIssue->dueDate.day,
                &newIssue->dueDate.month,
                &newIssue->dueDate.year,

                // Return date
                &newIssue->returnDate.day,
                &newIssue->returnDate.month,
                &newIssue->returnDate.year,

                // Fine amount
                &newIssue->fineAmount) != 14)
            {
                // Free allocated memory if record reading fails
                free(newIssue);
                break;
            }

            // Initialize the link pointer of the new node
            newIssue->link = NULL;

            // Check whether the Issue Record linked list is empty
            if(*IR == NULL)
            {
                // Make the new node the first node
                *IR = newIssue;
            }
            else
            {
                // Attach the new node at the end of the linked list
                issueTail->link = newIssue;
            }

            // Update the tail pointer to the newly inserted node
            issueTail = newIssue;
        }

        // Close the BookIssueRecord.txt file
        fclose(fp);
    }

    // Display message after attempting to load both files
    printf("Records Loaded Successfully\n");
}