#include"headers.h"
void viewAllBooks(BookRecord *head)
{
	BookRecord *temp=head;
	if(head==NULL)
	{
		printf("\033[31mBook Record is Empty\033[0m\n");
		return;
	}
	else
	{
		printf("\033[32mAvailable Books\033[0m\n");
		printf("+--------------------------------------------------------------+\n");
		printf("| %-8s | %-20s | %-15s | %-8s |\n","Book ID","Book Name","Auther","Quantity");
		printf("----------------------------------------------------------------\n");
		while(temp)
		{
			printf("| %-8d | %-20s | %-15s | %-8d |\n",temp->bookID,temp->title,temp->author,temp->quantity);
			temp=temp->link;
		}
		printf("+--------------------------------------------------------------+\n");
	}

}

void listIssueBooks(IssueRecord *head)
{
	if(head==NULL)
	{
		printf("\033[31mNo Book is Issue Yet\033[0m\n");
		return;
	}
	IssueRecord *temp=head;
	printf("+-------------------------------------------------------------------------------------------------------------+\n");
	printf("| %-8s | %-8s | %-8s | %-20s | %-10s | %-10s | %-10s | %-8s |\n","Issue ID","Book ID","User ID","User Name","Issue Date","Due Date","Return Date","Fine Amount");
	printf("+-------------------------------------------------------------------------------------------------------------+\n");
	while(temp)
	{
		printf("| %-8d | %-8d | %-8d | %-20.20s | %02d-%02d-%04d | %02d-%02d-%04d | %02d-%02d-%04d  | %-8f Rs |\n",temp->issueID,temp->bookID,temp->userID,temp->userName,temp->issueDate.day,temp->issueDate.month,temp->issueDate.year,temp->dueDate.day,temp->dueDate.month,temp->dueDate.year,temp->returnDate.day,temp->returnDate.month,temp->returnDate.year,temp->fineAmount);
		temp=temp->link;
	}
	printf("+-------------------------------------------------------------------------------------------------------------+\n");
}
