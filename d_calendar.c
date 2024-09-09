#include<stdio.h>
#include<stdlib.h>
struct calendar
{
        int date;
        char *p;
	char *d;
};
struct calendar *c;
void create()
{
	c=(struct calendar *)malloc(7*sizeof(struct calendar));
        printf("Enter the day, date and description for that day\n");
        for(int i=0;i<7;i++)
        {
		(c+i)->p=(char *)malloc(10*sizeof(char));
		(c+i)->d=(char *)malloc(10*sizeof(char));
                printf("Enter %d day\n", i+1);
                scanf("%s", (c+i)->p);
                printf("Enter the date for this\n");
                scanf("%d", &(c+i)->date);
                printf("Enter the description for that\n");
                scanf("%s", (c+i)->d);
        }
}
void display()
{
        printf("The details of 7 days you have entered are \n");
        for(int i=0;i<7;i++)
        {
                printf("%s-", (c+i)->p);
                printf("%d-", (c+i)->date);
                printf("%s\n", (c+i)->d);
        }
}
void main()
{
        create();
        printf("Now displaying\n");
        display();
}
