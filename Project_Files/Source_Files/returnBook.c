#include"headers.h"
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
