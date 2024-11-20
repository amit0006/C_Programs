/*Explain the various operation on double ended queue using arrays*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int que[MAX],item,front=-1,rear=-1,count=0;
void insert_front(){
	printf("Enter the element you want to insert\n");
	scanf("%d", &item);
	if(front==-1){
		front=0;
		rear=0;
		que[front]=item;
		count++;
	}
	else if(count==MAX){
		printf("Cannot insert the element queue is full\n");
	}
	else{
		front=(front-1+MAX)%MAX;
		que[front]=item;
		count++;
	}
}
void insert_rare(){
	printf("Enter the element you want to insert\n");
	scanf("%d", &item);
	if(front==-1){
                front=0;
                rear=0;
                que[front]=item;
		count++;
        }
	else if(count==MAX)
		printf("Cannot insert the element queue is full\n");
	else{
		rear=(rear+1)%MAX;
		que[rear]=item;
		count++;
	}
}
void delete_front(){
	if(front==-1)
		printf("Queue is empty\n");
	else{
		item=que[front];
		front=(front+1)%MAX;
		printf("Deleting %d from the queue\n", item);
		count--;
	}
}
void delete_rare(){
	if(front==-1)
                printf("Queue is empty\n");
        else{
                item=que[rear];
		rear=(rear-1+MAX)%MAX;
		printf("Deleting %d from the queue\n", item);
		count--;
	}
}
void display(){
	printf("The queue elements are \n");
	for(int i=0,f=front;i<count;i++,f=(f+1)%MAX)
		printf("%d ", que[f]);
	printf("\n");
}
void main(){
	printf("--------------------MENU---------------------");
	printf("\n1.Press 1 for inserting an element from the front\n2.press 2 for inserting one element from the back\n3.Press 3 for deleting one element from the front\n4.Press 4 for deleting an element from the back\n5.Press 5 for display\n6.Press 6 for exit\n");
	while(1){
		int choice;
		printf("Enter your choice\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:insert_front();
			       break;
			case 2:insert_rare();
			       break;
			case 3:delete_front();
			       break;
			case 4:delete_rare();
			       break;
			case 5:display();
			       break;
			case 6:exit(0);
			       break;
			default:printf("Invalid chocie\n");
		}
	}
}
