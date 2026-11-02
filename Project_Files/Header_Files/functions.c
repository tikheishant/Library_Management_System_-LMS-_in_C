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
int isLeapYear(int year)
{
    if(year % 400 == 0)
        return 1;

    if(year % 100 == 0)
        return 0;

    if(year % 4 == 0)
        return 1;

    return 0;
}
long int dateToDays(date d)
{
    int i;
    long int total = 0;

    int monthDays[] =
    {
        31,28,31,30,31,30,
        31,31,30,31,30,31
    };

    for(i = 1; i < d.year; i++)
    {
        total += 365;

        if(isLeapYear(i))
            total++;
    }

    for(i = 1; i < d.month; i++)
    {
        total += monthDays[i-1];
    }

    if(d.month > 2 && isLeapYear(d.year))
        total++;

    total += d.day;

    return total;
}
void returnBook(IssueRecord *IR,BookRecord *BR)
{
	int uID,bID;
	IssueRecord *Itemp=IR;
	BookRecord *Btemp=BR;
	int fine=5;
	long int dueDays,returnDays,lateDays;
	time_t raw_time=time(NULL);
	struct tm *info=localtime(&raw_time);
	char flag=0;

	if(IR==NULL)
	{
		printf("\033[31mIssued Book Record is Empty\033[0m\n");
		return;
	}
	printf("Enter the User ID : ");
	scanf("%d",&uID);
	printf("Enter the Book ID : ");
	scanf("%d",&bID);
	while(Itemp)
	{
		if(Itemp->userID==uID)
		{
			flag=1;
			if(Itemp->bookID==bID)
			{
				flag=2;
				if(Itemp->returnDate.day==0)
				{
					Itemp->returnDate.day = info->tm_mday;
					Itemp->returnDate.month = info->tm_mon+1;
					Itemp->returnDate.year=info->tm_year+1900;
				
					dueDays = dateToDays(Itemp->dueDate);
					returnDays = dateToDays(Itemp->returnDate);
					lateDays = returnDays - dueDays;
				
					if(lateDays<=0)
						Itemp->fineAmount=0;
					else if(lateDays>0)
						Itemp->fineAmount=lateDays * fine;

					printf("\033[32mFine Amount : %0.2f Rs\033[0m\n",Itemp->fineAmount);

					while(Btemp)
					{
						if(Btemp->bookID==bID)
						{
							++Btemp->quantity;
							break;
						}
						Btemp=Btemp->link;
					}
					flag++;
				}
			}
		}
		Itemp=Itemp->link;
	}
	if(flag==2)
		printf("\033[31mBook is Already Returned\033[0m\n");
	else if(flag==1)
		printf("\033[31mBook ID not found in User Record\033[0m\n");
	else if(flag==0)
		printf("\033[31mUser not Issued Any Book\033[0m\n");
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

//Binay files is being created using this
/*void save(BookRecord *BR,IssueRecord *IR)
{
	FILE *fp;
	BookRecord *temp1=BR;
	IssueRecord *temp2=IR;
	fp=fopen("BookRecord","wb");
	if(fp==NULL)
		return;
	while(temp1!=NULL)
	{
		fprintf(temp1,offsetof(BookRecord,link),1,fp);
		temp1=temp1->link;
	}
	fclose(fp);

	fp=fopen("BookIssueRecord","wb");
	if(fp==NULL)
		return;
	while(temp2!=NULL)
	{
		fwrite(temp2,offsetof(IssueRecord,link),1,fp);
		temp2=temp2->link;
	}
	fclose(fp);
	printf("\033[32mIformation Saved Successfully\033[0m\n");
}
void SyncFromFile(BookRecord **BR,IssueRecord **IR)
{
	FILE *fp;
	BookRecord *newBook;
	BookRecord *bookTail=NULL;

	IssueRecord *newIssue;
	IssueRecord *issueTail=NULL;

	//Read Book Records
	fp=fopen("BookRecord","rb");
	if(fp==NULL)
	{
		printf("\033[31mBook Record File Not Found\033[0m\n");
		return ;
	}

		while(1)
		{
			newBook = malloc(sizeof(BookRecord));
			if(newBook==NULL)
			{
				printf("\033[31mMemory Allocation Fail\033[0m\n");
				break;
			}

			if(fread(newBook,offsetof(BookRecord,link),1,fp)!=1)
			{
				free(newBook);
				break;
			}
			newBook->link=NULL;

			if(*BR == NULL)
			{
				*BR=newBook;
			}
			else
			{
				bookTail->link=newBook;
			}
			bookTail=newBook;
		}
		fclose(fp);

	// Read Issue Book record 
	
	fp=fopen("BookIssueRecord","rb");
	if(fp==NULL)
	{
		printf("\033[31mIssue Record File not Found\033[0m\n");
		return;
	}

	if(fp!=NULL)
	{
		while(1)
		{
			newIssue=calloc(1,sizeof(IssueRecord));
			if(newIssue==NULL)
				break;

			if(fread(newIssue,offsetof(IssueRecord,link),1,fp)!=1)
			{
				free(newIssue);
				break;
			}

			if(*IR == NULL)
			{
				*IR=newIssue;
			}
			else
			{
				issueTail->link=newIssue;
			}
			issueTail=newIssue;
		}
		fclose(fp);
	}
}*/
