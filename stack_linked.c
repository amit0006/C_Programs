//Stack using Single Linked List
#include<stdio.h>
#include<stdlib.h>
#define max 5
struct node{
	int info;
	struct node *next;
};
struct node *first=NULL,*temp=NULL;
int top=-1,count=0;
void create(){
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter the item you want to insert\n");
	scanf("%d", &temp->info);
}
void insert_front(){
	if(count==max){
		printf("Stack overfloaw\ncannot insert the element\n");
		return;
	}
	if(first==NULL){
		create();
		first=temp;
		temp->next=NULL;
	}
	else{
		create();
		temp->next=first;
		first=temp;
	}
	count++;
}
void delete_front(){
	if(count==0){
		printf("Stack underflow!\n");
		return;
	}
	temp=first;
	first=first->next;
	free(temp);
	count--;
}
void status(){
	if(count==0)
		printf("Stack underflow!\n");
	else if(count==max)
		printf("Stack overflow\n");
	else
		printf("Stack is in normal condition\n");
}
void display(){
	if(count==0)
		printf("Stack is empty\n");
	else{
		temp=first;
		printf("Stack elements are : - \n");
		while(temp!=NULL){
			printf("%d\n", temp->info);
			temp=temp->next;
		}
	}
}
void main(){
	printf("--------------------------MENU------------------------\n");
	printf("1.Press 1 for insertion\n2.Press 2 for deletion\n3.Press 3 for checking status of the stack\n4.Press 4 for display\n5.Press 5 for exit\n");
	while(1){
		int choice;
		printf("Enter your choice:\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:insert_front();
			       break;
			case 2:delete_front();
			       break;
			case 3:status();
			       break;
			case 4:display();
			       break;
			case 5:exit(0);
			       break;
			default:printf("Invalid chocie!\n");
		}
	}
}
