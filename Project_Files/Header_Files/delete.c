#include"headers.h"
BookRecord *removeBook(BookRecord *head)
{
	if(head==NULL)
	{
		printf("\033[31mBook Record is Empty\033[0m\n");
		return head;
	}
	int ID;
	char name[20];

	printf("Enter the book ID : ");
	scanf("%d",&ID);
	printf("Enter the book name : ");
	__fpurge(stdin);
	scanf("%[^\n]s",name);

	BookRecord *temp=head;
	BookRecord *prev=head;
	if(head->link==NULL)
	{
		if((head->bookID==ID)&&(!strcmp(head->title,name)))
		{
			free(head);
			printf("\033[32mBook Remove Successfully\033[0m\n");
			return NULL;
		}
	}
	else
	{
		while(temp)
		{	
			if((temp->bookID==ID)&&(!strcmp(temp->title,name)))
			{
				prev->link=temp->link;
				free(temp);
				printf("\033[32mBook Remove Successfully\033[0m\n");
				return head;	
			}
			prev=temp;
			temp=temp->link;
		}
	}
	printf("\033[31mBook not Found\033[0m\n");
	return head;
}
