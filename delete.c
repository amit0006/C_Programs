#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
};
int item;
struct node *first,*temp,*last,*pre,*temp1;
void create(){
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter the item you want to insert\n");
	scanf("%d", &item);
	temp->info=item;
}
void insert(){
	create();
	if(first==NULL){
		first=temp;
		last=temp;
		last->next=NULL;
	}
	else{
		last->next=temp;
		last=temp;
		last->next=NULL;
	}
}
void delete(){
	printf("Enter the item that should be deleted\n");
	scanf("%d", &item);
	temp=first;
	pre=NULL;
	while(temp!=NULL && temp->info==item){ //Mainly this while loop is for deleting the first node if the information field is equal to the item
		temp = temp->next;
		free(first);
		first=temp;
	}
	while(temp!=NULL){
		if(temp->info==item){
			pre->next = temp->next;
            		free(temp);
            		temp = pre->next;
		}
		else{
			pre=temp;
			temp=temp->next;
		}
	}
	if (first == NULL) {
        last = NULL;
    } else {
        /*struct node *last_node = first;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }*/
		last=first;
		while(last->next!=NULL){
			last=last->next;
		}
        //last = last_node;
    }
}
void display(){
	temp=first;
	if(first==NULL){
		printf("Linked list is empty\n");
		return ;
	}
	printf("The elements in the linked list are\n");
	while(temp!=NULL){
		printf("%d\n", temp->info);
		temp=temp->next;
	}
}
void main(){
	int n;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		insert();
	display();
	delete();
	display();
}
