typedef struct BookRecord
{
	int bookID;
	char title[20];
	char author[30];
	int quantity;
	struct BookRecord *link;
}BookRecord;

typedef struct date
{
	int day;
	int month;
	int year;
}date;

typedef struct IssueRecord
{
	int issueID;
	int bookID;
	int userID;
	char userName[30];
	date issueDate;
	date dueDate;
	date returnDate;
	double fineAmount;
	struct IssueRecord *link;
}IssueRecord;
