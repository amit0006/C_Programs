/*Develop a menu driven Program in C for the following operations on Circular QUEUE of 
Characters (Array Implementation of Queue with maximum size MAX) 
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations */
#include<stdio.h>
#include<stdlib.h>
#define size 5
int rear,count,front,item,que[size];
void insert(){
	if(count==size){
		printf("Queue is full\n");
	}
	else{
		rear=(rear+1)%size;
		printf("Enter the item you want to insert\n");
		scanf("%d", &item);
		que[rear]=item;
		count++;
	}
}
void del(){
	if(count==0)
		printf("Queue is empty\n");
	else{
		item=que[front];
		printf("Deleting %d from the stack\n", item);
		front=(front+1)%size;
		count--;
	}
}
void sit(){
	if(count==size)
		printf("The queue is in overflow condition\n");
	else if(count == 0)
		printf("The queue is in underflow condition\n");
	else
		printf("Queue is normal\n");
}
void display(){
	int i,f;
	for(int i=1,f=front;i<=count;i++){
		printf("%d\n", que[f]);
		f=(f+1)%size;
	}
}
void main(){
	front=0;
	rear=-1;
	int choice;
	while(1){
		printf("Enter your choice:\n1.Press 1 for inserting an element\n2.Press 2 for deleting an element\n3.Press 3 for checking situation\n4.Press 4 displaying the elements in the Queue\n5.Press 5 for exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:insert();
			       break;
			case 2:del();
			       break;
			case 3:sit();
			       break;
			case 4:display();
			       break;
			case 5:exit(0);
			       break;
			default:printf("Invalid choice\n");
		}
	}
}

