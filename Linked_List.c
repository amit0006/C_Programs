/*Develop a menu driven Program in C for the following operations on Singly Linked List 
(SLL) of Student Data with the fields: USN, Name, Programme, Sem, 
PhNo 
a. Create a SLL of N Students Data by using front insertion. 
b. Display the status of SLL and count the number of nodes in it 
c. Perform Insertion / Deletion at End of SLL 
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack) 
e. Exit */
#include<stdio.h>
#include<stdlib.h>
struct student{
	char USN[10];  //For storing USN of the Student
	int sem; //For storing the semester in which the student is currently studying
	char Programme[200];  //For the Programme in which they are currently enrolled
	long pno; //For phone number
	char Name[100]; //For name
	struct student *next; //For storing the address of the next node
};
struct student *first,*last,*temp;
int count=0; //For count the number of elements in the Linked List
void insert_front();
void create(){
	int n; //For creating the Linked List of N elements
	printf("Enter the number of student\n");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		insert_front();   //Calling the insert_front() function N times 
}
void insert_front(){
	temp=(struct student *)malloc(sizeof(struct student));
        printf("Enter the USN of student\n");
        scanf("%s", temp->USN);
        getchar();
        printf("Enter the Nmae of student\n");
        scanf("%[^\n]s", temp->Name);
        getchar();
        printf("enter the programme that student is studying\n");
        scanf("%[^\n]s", temp->Programme);
        printf("Enter the semester of student\n");
        scanf("%d", &temp->sem);
        printf("Enter the phone number of the student\n");
        scanf("%ld", &temp->pno);
        count++;
	if(first==NULL){
		last=temp;
		first=last;
		last->next=NULL;
	}
	else{
		temp->next=first;
		first=temp;
	}
}
void insert_end(){
	temp=(struct student *)malloc(sizeof(struct student));
	printf("Enter the USN of student\n");
        scanf("%s", temp->USN);
        getchar();
        printf("Enter the Nmae of student\n");
        scanf("%[^\n]s", temp->Name);
        getchar();
        printf("enter the programme that student is studying\n");
        scanf("%[^\n]s", temp->Programme);
        printf("Enter the semester of student\n");
        scanf("%d", &temp->sem);
        printf("Enter the phone number of the student\n");
        scanf("%ld", &temp->pno);
        count++;
	if(first==NULL){
		first=temp;
		last=first;
		last->next=NULL;
	}
	else{
		last->next=temp;
		last=temp;
	}
}
void delete_front(){
	if(first==NULL)
		printf("Linked List is empty\n");
	else if(first==last){
		free(first);
		free(last);
		first=NULL;
		last=NULL;
		count--;
	}
	else{
		temp=first->next;
		free(first);
		first=temp;
		count--;
	}
}
void delete_end(){
	if(first==NULL)
		printf("Linked List is empty\n");
	else if(first==last){
		free(first);
		free(last);
		first=NULL;
		last=NULL;
		count--;
	}
	else{
		temp=first;
		while(temp->next->next!=NULL)
			temp=temp->next;
		last=temp;
		free(last->next);
		last->next=NULL;
		count--;
	}
}
void display(){ //For displaying the elements in the linked list
	printf("The details of the student in the linked list are\n");
	temp=first; //printing the values of linked list by the reference of temp
	for(int i=0;i<count;i++){
		printf("The USN of the student %d is : %s\n", i+1,temp->USN);
		printf("The Name of the student %d is : %s\n", i+1,temp->Name);
		printf("The Programme that the student is studying is : %s\n", temp->Programme);
		printf("The smester in which the student is currently studying is : %d\n", temp->sem);
		printf("The phone number of the student is : %ld\n", temp->pno);
		temp=temp->next; //assigning the adress of next node to the temp
	}
}
void main(){
	create(); //For creating the Linked List
	display(); 
	while(1){
		printf("Enter your choice:\n1.Press 1 for insertion of details from the front\n2.Press 2 for insertion of details from the back\n3.Press 3 for deleting the details from front\n4.Press 4 for deleting details from end\n5.Press 5 for displaying status of the linked list\n6.Press 6 for Exit\n");
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:insert_front();
		       		break;
			case 2:insert_end();
		       		break;
			case 3:delete_front();
		       		break;
			case 4:delete_end();
		      		break;
			case 5:display();
		       		break;
			case 6:exit(0);
		       		break;
			default:printf("Invalid choice!\nPlease choose correctly\n");
		}
	}
}
