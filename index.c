//To find the starting and ending index of a number in a sorted array
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
	int old,new;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(a[mid]==key)
		{
			k=1;
			while(a[mid]==key)
			{
				new=mid;
				if(a[mid+1]==key)
				{
					mid=mid+1;
				}
				else
				{
					break;
				}
			}
			printf("now mid is outside loop %d\n", mid);
			while(a[mid]==key)
			{
				old=mid;
				mid=mid-1;
			}
			break;			
		}
		else if(a[mid]>key)
			e=mid-1;
		else
		{
			s=mid+1;
		}
	}
	printf("The starting index is %d and ending index is %d\n", old,new);
	if(k==0)
		printf("Key not found\n");
}
