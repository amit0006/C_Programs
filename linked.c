#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *first,  *temp, *last;
void create()
{
	printf("Enter any positive number, if you enter nugative number then it will stop taking inputs\n");
	temp=(struct node *)malloc(sizeof(struct node));
	scanf("%d", &temp->data);
	temp->next=NULL;
	first=temp;
	last=temp;
	while(temp->data>=0)
	{
		printf("Enter any positive number, if you enter nugative number then it will stop taking inputs\n");
		temp=(struct node *)malloc(sizeof(struct node));
		scanf("%d", &temp->data);
		//st->next=temp;
		temp->next=NULL;
		last->next=temp;
		last=temp;
	}
}
void display()
{
	printf("The elements you have entered are\n");
	temp=first;
	while(temp->data>=0)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void main()
{
	first=NULL;
	last=NULL;
	temp=NULL;
	create();
	display();
}

