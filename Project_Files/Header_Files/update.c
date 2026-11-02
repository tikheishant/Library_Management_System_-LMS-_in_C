#include"headers.h"
void updateBookDetail(BookRecord *head)
{
	if(head==NULL)
	{
		printf("\033[31mBook Record is Empty\033[0m\n");
		return;
	}
	int ID;
	char name[20];
	int qua;
	char auth[30];
	int choise;
	printf("Enter the book ID : ");
	scanf("%d",&ID);
	__fpurge(stdin);
	printf("Enter the book name : ");
	scanf("%[^\n]s",name);

	BookRecord *temp=head;
	while(temp)
	{	
		if((temp->bookID==ID)&&(!strcmp(temp->title,name)))
		{
			while(1)
			{
				printf("+-------------------+\n");
				printf("| 1.Book ID         |\n");
				printf("| 2.Book Name	    |\n");
				printf("| 3.Auther	    |\n");
				printf("| 4.Quantity        |\n");
				printf("| 5.Return          |\n");
				printf("+-------------------+\n");
				__fpurge(stdin);
				scanf("%d",&choise);
				
				__fpurge(stdin);
				switch(choise)
				{
					case 1:printf("Enter the Updated ID : ");
					       scanf("%d",&ID);
					       temp->bookID=ID;
					       break;
					case 2:printf("Enter the Updated Book Name : ");
					       scanf("%[^\n]s",name);
					       strcpy(temp->title,name);
					       break;
					case 3:printf("Enter the Updated Auther name : ");
					       scanf("%[^\n]s",auth);
					       strcpy(temp->author,auth);
					       break;
					case 4:printf("Emter the Updated Quantity : ");
					       scanf("%d",&qua);
					       temp->quantity=qua;
					       break;
					case 5:printf("\033[32mBook detail Updated Successfully\033[32m\n");
					       return;
				}
			}
		}
		temp=temp->link;
	}
	printf("\033[31mBook not found\033[0m\n");
	printf("\n");
}
