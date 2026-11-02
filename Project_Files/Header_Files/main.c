#include"headers.h"
// Book functions
BookRecord *addNewBook(BookRecord *);
BookRecord *removeBook(BookRecord *);
void updateBookDetail(BookRecord *);
void searchBook(BookRecord *);
void viewAllBooks(BookRecord *);

// Issue functions
IssueRecord *issueBook(IssueRecord *, BookRecord *);
void returnBook(IssueRecord *, BookRecord *);
void listIssueBooks(IssueRecord *);

// File handling
void save(BookRecord *, IssueRecord *);
void SyncFromFile(BookRecord **, IssueRecord **);

int main()
{
	int savePass=3432;
	char uId[]="Record@980";
	int tempPass;
	char tempUID[20];
	int choice;
	BookRecord *BR=NULL;
	IssueRecord *IR=NULL;
	SyncFromFile(&BR,&IR);
	printf("Enter the User ID  : ");
        scanf("%[^\n]s",tempUID);
	printf("Enter the Password : ");
	scanf("%d",&tempPass);
	if((tempPass==savePass) && (!strcmp(uId,tempUID)))
	{	
		while(1)
		{
			printf("\033[1;36m");
			printf("+----------------------------------------+\n");
			printf("|         Book Management Menu           |\n");
			printf("|----------------------------------------|\n");
			printf("\033[0m");
			printf("\033[36m");
			printf("| 1. Add New Book                        |\n");
			printf("| 2. Update Book Details                 |\n");
			printf("| 3. Remove Book                         |\n");
			printf("| 4. Search Book                         |\n");
			printf("| 5. View All Books                      |\n");
			printf("| 6. Issue Book                          |\n");
			printf("| 7. Return Book                         |\n");
			printf("| 8. List Issued Books                   |\n");
			printf("| 9. Save                                |\n");
			printf("| 10. Exit                               |\n");
			printf("+----------------------------------------+\n");
			printf("\033[0m");
		
			__fpurge(stdin);
			scanf("%d",&choice);

			switch(choice)
			{
				case 1:BR=addNewBook(BR);
				       break;
				case 2:updateBookDetail(BR);
			      	       break;
				case 3:BR=removeBook(BR);
				       break;
				case 4:searchBook(BR);
				       break;
				case 5:viewAllBooks(BR);
				       break;
				case 6:IR=issueBook(IR,BR);
				       break;
				case 7:returnBook(IR,BR);
				       break;
				case 8:listIssueBooks(IR);
				       break;
				case 9:save(BR,IR);
				       break;
				case 10:save(BR,IR);
				        exit(0);
			}
		}
	}
	else
	{
		printf("\033[31mWrong ID or Password\033[0m\n");
	}
}
