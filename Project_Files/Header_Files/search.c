#include"headers.h"
void searchBook(BookRecord *head)
{
	if(head==NULL)
	{
		printf("Book Record is Empty\n");
		return ;
	}
	int ID;
	char name[20];
	printf("Enter the Book ID : ");
	scanf("%d",&ID);
	__fpurge(stdin);
	printf("Enter the Book Name : ");
	scanf("%[^\n]s",name);

	BookRecord *temp=head;
	while(temp)
	{
		if((temp->bookID==ID)&&(!strcmp(temp->title,name)))
		{
			printf("\033[32m\n");
			printf("*********************************\n");
			printf("*  Book ID     : %d\n",temp->bookID);
			printf("*  Book Name   : %s\n",temp->title);
			printf("*  Author Name : %s\n",temp->author);
			printf("*  Quantity    : %d\n",temp->quantity);
			printf("*********************************\n");
			printf("\033[0m\n");
			return ;
		}
		temp=temp->link;
	}
}
