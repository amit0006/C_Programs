#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1;
int stack[MAX];
void push()
{
	printf("Enter the number that you want to insert\n");
	int element;
	scanf("%d", &element);
	if(top==MAX-1)
		printf("\nStack is full\n");
	else
		stack[++top]=element;
}
void pop()
{
	int element;
	element=stack[top];
	printf("\nDeleting %d from the stack\n", element);
	top--;
}
void display()
{
	if(top==-1)
		printf("\nStack Underflow\n");
	else
	{
		printf("\nThe elements in the stack are:\n");
		for(int i=top;i>=0;i--)
			printf("%d\n", stack[i]);
	}
}
void palindrone()
{
	int num=0;
	int rev=0;
	int k=0;
	for(int i=top;i>=0;i--)
	{
		num=stack[i];
		if(num==stack[rev])
			k=1;
		else
			break;
		rev=rev+1;
	}
	if(k==1)
		printf("\nPalindrone\n");
	else
		printf("\nNot palindrone\n");
}
void check()
{
	if(top==-1)
		printf("\nStack is in underflow condition\n");
	else if(top==MAX-1)
		printf("\nStack is in overflow condition\n");
	else
		printf("\nStack is not in underflow and overflow and is ok\n");
}
void main()
{
	while(1)
	{
		int choice;
		printf("Enter your choice:\n1.Press 1 for push\n2.Press 2 for pop\n3.Press 3 for display the status of the stack\n4.Press 4 for checking palindrone\n6.Press 5 for checking if stack is overflow or underflow\n7.Press 6 for exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:push();
			       break;
			case 2:pop();
			       break;
			case 3:display();
			       break;
			case 4:palindrone();
			       break;
			case 5:check();
			       break;
			case 6:exit(0);
			       break;
			default:printf("Invalid choice\n");
		}
	}
}

