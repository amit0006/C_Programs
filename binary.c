#include<stdio.h>
void main()
{
	int a[100],n;
	printf("Enter the size of the array\n");
	scanf("%d", &n);
	printf("Enter the array elements\n");
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	printf("The array elements you have entered are\n");
	for(int i=0;i<n;i++)
		printf("%d\n", a[i]);
	int key,mid,s,e;
	printf("Enter the key element you want to search in the above given set of values\n");
	scanf("%d", &key);
	s=0;
	e=n-1;
	int k=0;
	/*while(s<=e)
	{
		mid=(s+e)/2;
		if(a[mid]==key)
		{
			printf("Key found at loation %d\n", mid+1);
			k=1;
			break;			
		}
		else if(a[mid]>key)
			e=mid-1;
		else
		{
			s=mid+1;
		}
	}
	if(k==0)
		printf("Key not found\n");*/
	//We can have this method also to for the binary search program
	mid=(s+e)/2;
	if(a[mid]==key)
		printf("Key is found at location %d\n", mid+1);
	else if(a[mid]!=key)
	{
		while(s<=e)
		{
			if(a[mid]==key)
			{
				printf("Key found at location %d", mid+1);
				k=1;
				break;
			}
			else if(a[mid]>key)
			{
				e=mid-1;
				mid=(s+e)/2;
			}
			else
			{
				s=mid+1;
				mid=(s+e)/2;
			}
		}
	}
	if(k==0)
		printf("Key not found\n");
}
