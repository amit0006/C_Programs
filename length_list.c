/*Function for counting the number of nodes in the linked list*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
};
struct node *first,*temp,*last;
void create(){
        temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter the integer\n");
	scanf("%d", &temp->info);
}
void insert_front(){
        create();
        if(first==NULL){
                printf("Linekd list was empty and now one node is inserted\n");
                last=temp;
                first=last;                                                                                                                                                 last->next=NULL;
        }
        else{
                printf("One node is inserted from the front\n");
                temp->next=first;
                first=temp;
        }
}
void display(){ //For displaying the elements in the linked list
        printf("The details of the student in the linked list are\n");
        temp=first; //printing the values of linked list by the reference of temp
        while(temp!=NULL){
		printf("The information is %d\n", temp->info);
		temp=temp->next;
        }
}
void count(){
	int count=0;
	temp=first;
	if(first==NULL){
		printf("Linked list is empty\n");
		return;
	}
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	printf("The total number of elements in the linked list are %d\n", count);
}
void main(){
	int n;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		insert_front();
	display();
	count();
}
