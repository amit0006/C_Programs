/*Develop a Program in C for the following operationson Singly Circular Linked List (SCLL) 
with header nodes 
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-4yz5+3x3yz+2xy5z-2xyz3 
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the 
result in POLYSUM(x,y,z) 
Support the program with appropriate functions for each of the above operations*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int powx,powy,powz,cff;
	struct node *next;
};
struct node *first=NULL,*last=NULL,*temp=NULL;
void create(){
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter the coefficient of the term\n");
	scanf("%d", &temp->cff);
	printf("Enter the power of the x\n");
	scanf("%d", &temp->powx);
	printf("Enter the power of the y\n");
	scanf("%d", &temp->powy);
	printf("Enter the power of the z\n");
	scanf("%d", &temp->powz);
	temp->next=NULL;
}
void evaluate(struct node *head){
	temp=head;
	if(temp->next==NULL){
		printf("Polynomial does not exist\n");
		return;
	}
	temp=temp->next;
	printf("Enter the value of x, y and z\n");
	int x,y,z;
	scanf("%d%d%d", &x,&y,&z);
	int ans=0;
	while(temp!=head){
		ans=ans+(temp->cff*pow(x,temp->powx)*pow(y,temp->powy)*pow(z,temp->powz));
		temp=temp->next;
	}
	printf("After evaluating the polynomial the answer is %d\n", ans);
}
void insert_end(){
	create();
	if(first==NULL){
		first=temp;
		last=temp;
	}
	else{
		last->next=temp;
		last=temp;
	}
}
void display(struct node *head){
	temp=head;
	if(temp->next==NULL){
		printf("Linked list is empty\n");
		return;
	}
	temp=temp->next;
	while(temp!=head){
		if(temp->next==head){
         	       printf("%dx^%dy^%dz^%d", temp->cff,temp->powx,temp->powy,temp->powz);
		       printf("\n");
	       	       return;
        	}
		printf("%dx^%dy^%dz^%d+", temp->cff,temp->powx,temp->powy,temp->powz);
		temp=temp->next;
	}
}
void sum_poly(struct node *h1,struct node *h2){
	if(h1->next==NULL){
		if(h2->next==NULL)
			printf("Polynomial doesn't exist sum_poly function\n");
		else{
			first=h2->next;
			temp=first;
			while(temp->next!=h2)
				temp=temp->next;
			last=temp;
		}
	}
	else if(h2->next==NULL){
		first=h1->next;
		temp=first;
		while(temp->next!=h1)
			temp=temp->next;
		last=temp;
	}
	else{
		temp=h1->next;
		struct node *temp1=h2->next;
		struct node *temp2=NULL;
		while(temp!=h1){
			if(temp->powx==temp1->powx && temp->powy==temp1->powy && temp->powz==temp1->powz){
				temp2=(struct node *)malloc(sizeof(struct node));
				temp2->cff=temp->cff+temp1->cff;
				temp2->powx=temp->powx;
				temp2->powy=temp->powy;
				temp2->powz=temp->powz;
				temp1->cff=-999;
				temp2->next=NULL;
			}
			else{
				temp2=(struct node *)malloc(sizeof(struct node));
				temp2->cff=temp->cff;
				temp2->powx=temp->powx;
				temp2->powy=temp->powy;
				temp2->powz=temp->powz;
				temp2->next=NULL;
			}
			if(first==NULL){
				first=temp2;
				last=temp2;
			}
			else{
				last->next=temp2;
				last=temp2;
			}
			temp=temp->next;
			temp1=temp1->next;
		}
		temp1=h2->next;
		while(temp1!=h2){
			if(temp1->cff!=-999){
				temp2=(struct node *)malloc(sizeof(struct node));
				temp2->cff=temp1->cff;
				temp2->powx=temp1->powx;
				temp2->powy=temp1->powy;
				temp2->powz=temp1->powz;
				last->next=temp2;
				last=temp2;
				last->next=NULL;
			}
			temp1=temp1->next;
		}
	}
}
void main(){
	int n;
	struct node *POLY1,*POLY2;
	printf("Enter the number of terms in 1st polynomial\n");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		insert_end();
	POLY1=(struct node *)malloc(sizeof(struct node));
	if(first==NULL){
		printf("You have not entered any element in the 1st polynomial\n");
		POLY1->next=NULL;
	}
	else{
	POLY1->next=first;
        last->next=POLY1;
	first=NULL;
	last=NULL;
	}
	printf("Enter the number of terms in 2nd polynomial\n");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		insert_end();
	POLY2=(struct node *)malloc(sizeof(struct node));
	if(first==NULL){
		printf("You have not entered any element in the 1st polynomial\n");
	}
	else{
		POLY2->next=first;
		last->next=POLY2;
		first=NULL;
		last=NULL;
	}
	printf("The 1st polynomial you have entered is:\n");
	display(POLY1);
	printf("The 2nd polynomial you have entered is:\n");
	display(POLY2);
	evaluate(POLY1);
	struct node *POLYSUM;
	POLYSUM=(struct node *)malloc(sizeof(struct node));
	sum_poly(POLY1,POLY2);
	POLYSUM->next=first;
	last->next=POLYSUM;
	first=NULL;
	last=NULL;
	display(POLYSUM);
}
