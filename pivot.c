/*Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.*/
#include<stdio.h>
void main()
{
	int n,sum1,sum2;
	printf("Enter the value of n\n");
	scanf("%d", &n);
	int x;
	x=-1;
	sum1=0;
	sum2=0;
	int y=n;
	int i,j;
	int a[100];
	for(i=0;i<y;i++)
	{
		a[i]=n;
		n=n-1;
	}
	for(i=0;i<y;i++)
	{
		sum1=sum1+a[i];
		for(j=i;j<y;j++)
		{
			sum2=sum2+a[j];
		}
		if(sum1==sum2)
			break;
		else
			sum2=0;
	}
	printf("Sum is %d\n", sum1);
	if(i==y)
	{
		printf("The pivot number is %d\n", x);
	}
	else
		 printf("The pivot number is %d\n", a[i]);
}
