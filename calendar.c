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
}
void main()
{
	create();
	printf("Now displaying\n");
	display();
}


