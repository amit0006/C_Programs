#include<stdio.h>
//#include<process.h>
struct calendar
{
	char day[10];
	int date;
	char description[10];
};
struct calendar c[7];
void create()
{
	printf("Enter the day, date and description for that day\n");
	for(int i=0;i<7;i++)
	{
		printf("Enter %d day\n", i);
		scanf("%s", c[i].day);
		printf("Enter the date for this\n");
		scanf("%d", &c[i].date);
		printf("Enter the description for that\n");
		scanf("%s", c[i].description);
	}
	/*printf("Enter the date of these days\n");
	for(int i=0;i<7;i++)
		scanf("%d", &c[i].date);
	printf("Enter the description of the activity that you have done on that day\n");
	for(int i=0;i<7;i++)
		scanf("%s", c[i].description);*/
	//printf("Hello");
}
void display()
{
	printf("The details of 7 days you have entered are \n");
	for(int i=0;i<7;i++)
	{
		printf("%s-",c[i].day);
		printf("%d-", c[i].date);
		printf("%s\n", c[i].description);
	}
	/*printf("The yoou have entered for these days respectively are\n");
	for(int i=0;i<7;i++)
		printf("%d\n", c[i].date);
	printf("The description you have entered on these days respectively are \n");
	for(int i=0;i<7;i++)
		puts(c[i].description);*/
}
void main()
{
	create();
	printf("Now displaying\n");
	display();
	/*struct calendar c;
	printf("Enter the first day\n");
	gets(c.day);
	printf("Enter the date for that\n");
	scanf("%d", &c.date);
	printf("Enter description\n");
	printf("Going to take the value\n");
	//fflush(stdin);
	scanf("%s",c.description);
	printf("The day is \n");
	puts(c.day);
	printf("%d", c.date);
	printf("The descrption is\n");
	pu0ts(c.description);*/
}


