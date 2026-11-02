#include"headers.h"
BookRecord *addNewBook(BookRecord *head)
{
	BookRecord *newnode=calloc(1,sizeof(BookRecord));
	if(newnode==NULL)
	{
		printf("\033[31mNode Not Created\033[0m\n");
		return head;
	}

	printf("Enter the book ID : ");
	scanf("%d",&newnode->bookID);
	printf("Enter the new Book name : ");
	__fpurge(stdin);
	scanf("%[^\n]s",newnode->title);
	printf("Enter the Auther Name : ");
	__fpurge(stdin);
	scanf("%[^\n]s",newnode->author);
	printf("Enter the available Quantity : ");
	scanf("%d",&newnode->quantity);
	if(head==NULL)
		head=newnode;
	else
	{
		BookRecord *temp=head;
		while(temp->link)
		{
			temp=temp->link;
		}
		temp->link=newnode;
	}
	return head;
}
