/*Write a c program to create an array with n elements insert a new element at a position specified by the user and print the array elements after insertion*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *p;
	int n;
	printf("Enter the size of the array\n");
	scanf("%d", &n);
	p=(int *)malloc(n*sizeof(int));
	printf("Enter the array elements\n");
	for(int i=0;i<n;i++)
		scanf("%d", (p+i));
	int pos;
	printf("Enter the position where you want  to insert the elements\n");
	scanf("%d", &pos);
	int key;
	printf("Enter the element you want to insert\n");
	scanf("%d", &key);
	for(int i=n-1;i>=pos-1;i--)
		*(p+i+1)=*(p+i);
	*(p+(pos-1))=key;
	printf("The array is :\n");
	for(int i=0;i<=n;i++)
		printf("%d\n", *(p+i));
}


