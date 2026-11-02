#include"headers.h"
void save(BookRecord *BR, IssueRecord *IR)
{
    FILE *fp;

    BookRecord *temp1 = BR;
    IssueRecord *temp2 = IR;

    // Save Book Records

    fp = fopen("BookRecord.txt", "w");

    if(fp == NULL)
    {
        printf("Book File Not Opened\n");
        return;
    }

    while(temp1 != NULL)
    {
        fprintf(fp, "%d|%s|%s|%d\n",temp1->bookID,temp1->title,temp1->author,temp1->quantity);

        temp1 = temp1->link;
    }

    fclose(fp);


    // Save Issue Records

    fp = fopen("BookIssueRecord.txt", "w");

    if(fp == NULL)
    {
        printf("Issue File Not Opened\n");
        return;
    }

    while(temp2 != NULL)
    {
        fprintf(fp, "%d|%d|%d|%s|"
                    "%d|%d|%d|"
                    "%d|%d|%d|"
                    "%d|%d|%d|%.2f\n",

                temp2->issueID,
                temp2->bookID,
                temp2->userID,
                temp2->userName,

                temp2->issueDate.day,
                temp2->issueDate.month,
                temp2->issueDate.year,

                temp2->dueDate.day,
                temp2->dueDate.month,
                temp2->dueDate.year,

                temp2->returnDate.day,
                temp2->returnDate.month,
                temp2->returnDate.year,

                temp2->fineAmount);

        temp2 = temp2->link;
    }

    fclose(fp);

    printf("Records Saved Successfully\n");
}
void SyncFromFile(BookRecord **BR, IssueRecord **IR)
{
    FILE *fp;

    BookRecord *newBook;
    BookRecord *bookTail = NULL;

    IssueRecord *newIssue;
    IssueRecord *issueTail = NULL;

    // Read Book Records

    fp = fopen("BookRecord.txt", "r");

    if(fp != NULL)
    {
        while(1)
        {
            newBook = malloc(sizeof(BookRecord));

            if(newBook == NULL)
                break;

            if(fscanf(fp, "%d|%19[^|]|%29[^|]|%d",
                      &newBook->bookID,
                      newBook->title,
                      newBook->author,
                      &newBook->quantity) != 4)
            {
                free(newBook);
                break;
            }

            newBook->link = NULL;

            if(*BR == NULL)
            {
                *BR = newBook;
            }
            else
            {
                bookTail->link = newBook;
            }

            bookTail = newBook;
        }

        fclose(fp);
    }


    // Read Issue Records

    fp = fopen("BookIssueRecord.txt", "r");

    if(fp != NULL)
    {
        while(1)
        {
            newIssue = malloc(sizeof(IssueRecord));

            if(newIssue == NULL)
                break;

            if(fscanf(fp,
                "%d|%d|%d|%29[^|]|"
                "%d|%d|%d|"
                "%d|%d|%d|"
                "%d|%d|%d|%lf",

                &newIssue->issueID,
                &newIssue->bookID,
                &newIssue->userID,
                newIssue->userName,

                &newIssue->issueDate.day,
                &newIssue->issueDate.month,
                &newIssue->issueDate.year,

                &newIssue->dueDate.day,
                &newIssue->dueDate.month,
                &newIssue->dueDate.year,

                &newIssue->returnDate.day,
                &newIssue->returnDate.month,
                &newIssue->returnDate.year,

                &newIssue->fineAmount) != 14)
            {
                free(newIssue);
                break;
            }

            newIssue->link = NULL;

            if(*IR == NULL)
            {
                *IR = newIssue;
            }
            else
            {
                issueTail->link = newIssue;
            }

            issueTail = newIssue;
        }

        fclose(fp);
    }

    printf("Records Loaded Successfully\n");
}
