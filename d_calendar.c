/*Develop a Program in C for the following: 
a) Declare a calendar as an array of 7 elements (A dynamically Created array) to represent 
7 days of a week. Each Element of the array is a structure having three fields. The first 
field is the name of the Day (A dynamically allocated String), The second field is the 
date of the Day (A integer), the third field is the description of the activity for a 
particular day (A dynamically allocated String). 
b) Write functions create(), read() and display(); to create the calendar, to read the data 
from the keyboard and to print weeks activity details report on screen.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct calendar
{
        int date;
        char *n;
        char *d;
};
struct calendar *c;
void create()
{
        c=(struct calendar *)malloc(7*sizeof(struct calendar));
        if(c==NULL)
        {
                printf("Memory is not allocated\n");
                exit(0);
        }
}
void read()
{
        printf("Enter the day, date and description of that day\n");
        char name[10];
        char description[25];
        int date;
        for(int i=0;i<7;i++)
        {
                printf("Enter the name of the day\n");
                scanf("%s", name);
                c[i].n=(char *)malloc(strlen(name)+1);
                strcpy(c[i].n,name);
                printf("Enter the date of that day\n");
                scanf("%d", &date);
                c[i].date=date;
                printf("Enter the description of activity of that day\n");
                getchar();
                scanf("%[^\n]s", description);
                c[i].d=(char *)malloc(strlen(description)+1);
                strcpy(c[i].d, description);
        }
}
void display()
{
        printf("The details of 7 days you have entered are \n");
        for(int i=0;i<7;i++)
        {
                printf("%s-", c[i].n);
                printf("%d-", c[i].date);
                printf("%s\n", c[i].d);
                free(c[i].n);
                free(c[i].d);
        }
        free(c);
}
void main()
{
        create();
        printf("Now reading\n");
        read();
        printf("Now displaying\n");
        display();
}
