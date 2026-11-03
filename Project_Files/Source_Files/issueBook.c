#include"headers.h"
IssueRecord * issueBook(IssueRecord *head,BookRecord *book)
{
	char name[20];
	printf("Enter the book name : ");
	__fpurge(stdin);
	scanf("%[^\n]s",name);
	BookRecord *temp=book;

	while(temp)
	{
		if(!strcmp(temp->title,name))
		{
			if(temp->quantity>0)
			{
				IssueRecord *newnode=calloc(1,sizeof(IssueRecord));
				if(newnode==NULL)
				{
					printf("\033[31mNode not Created\033[0m\n");
					return head;
				}
				printf("Enter the issueID : ");
				scanf("%d",&newnode->issueID);
	
				newnode->bookID=temp->bookID;
	
				printf("Enter the user ID : ");
				scanf("%d",&newnode->userID);
				__fpurge(stdin);
				printf("Enter the user name : ");
				scanf("%[^\n]s",newnode->userName);
	
				time_t raw_time = time(NULL);
				struct tm *info = localtime(&raw_time);
	
				newnode->issueDate.day=info->tm_mday;
				newnode->issueDate.month=info->tm_mon+1;
				newnode->issueDate.year=info->tm_year+1900;
			
				newnode->dueDate.day=info->tm_mday+10;
				newnode->dueDate.month=info->tm_mon+1;
				newnode->dueDate.year=info->tm_year+1900;
				if(newnode->dueDate.month<8)
				{
					if(newnode->dueDate.month %2)
					{
						if(newnode->dueDate.day>31)
						{
							newnode->dueDate.day-=31;
							++newnode->dueDate.month;
						}
					}
					else
					{
						if(newnode->dueDate.day>30)
						{
							newnode->dueDate.day-=30;
							++newnode->dueDate.month;
						}
						else if(newnode->dueDate.month==2 && newnode->dueDate.day>28)
						{
							if(newnode->dueDate.year%4!=0)
							{
								newnode->dueDate.day-=28;
							}
							else
							{
								newnode->dueDate.day-=29;
							}
							++newnode->dueDate.month;
						}
					}
				}
				else
				{
					if(newnode->dueDate.month%2==0)
					{
						if(newnode->dueDate.day>31)
						{
							newnode->dueDate.day-=31;
							++newnode->dueDate.month;
							if(newnode->dueDate.month>12)
							{
								newnode->dueDate.month-=12;
								++newnode->dueDate.year;
							}
						}
					}
					else
					{
						if(newnode->dueDate.day>30)
						{
							newnode->dueDate.day-=30;
							++newnode->dueDate.month;
						}
					}
				}
			
				if(head==NULL)
				{
					head=newnode;
					--temp->quantity;
					printf("\033[32mBook Issued Successfully\033[0m\n");
					return head;
				}
				else
				{
					IssueRecord *temp1=head;
					while(temp1->link)
					{
						temp1=temp1->link;
					}
					temp1->link=newnode;
					--temp->quantity;
					printf("\033[32mBook Issued Successfully\033[0m\n");
				}
				return head;
			}
			else
			{
				printf("\033[31mQuantity of Book is Zero\033[0m\n");
				return head;
			}
		}
		temp=temp->link;
	}
	printf("\033[31mBook not found\033[0m\n");
	return head;
}
