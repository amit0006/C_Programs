#include<stdio.h>
void main()
{
	int a[100],n;
	printf("Enter the size of the array\n");
	scanf("%d", &n);
	printf("Enter the elements to the array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	printf("The array elements you have entered are\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n", a[i]);
	}
	int l=0;
	int h=n-1;
	int mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(a[mid]<a[mid+1])
		{
			l=mid+1;
		}
		else
		{
			h=mid;
		}
	}
	printf("The index of the peak element is %d\n", l);
}
