//Find the pivot index in the array
/*#include<stdio.h>
void main()
{
	int a[10]={3,8,17,1,6};
	int n=5;
	int s=0;
	int e=n-1;
	int mid;
	while(s<e)
	{
		mid=(s+e)/2;
		if(a[mid]>=a[0])
			s=mid+1;
		else
			e=mid;
	}
	printf("The pivot index is %d\n", e);
}*/
//Find the target element in the rotated sorted array
#include<stdio.h>
int search(int* nums, int numsSize, int target) {
    int s=0;
    int e=numsSize-1;
    int ans,mid,k;
    k=0;
    while(s<e)
    {
        mid=(s+e)/2;
        if(nums[mid]>=nums[0])
        {
            s=mid+1;
        }
        else
        {
            e=mid;
        }
    }
    if(nums[s]==target)
    {
        k=1;
	mid=s;
    }
    else if(nums[s]<target&&target<=nums[numsSize-1])
    {
        e=numsSize-1;
        while(s<=e)
        {
            mid=(s+e)/2;
            if(nums[mid]==target)
            {
                k=1;
                break;
            }
            else if(nums[mid]>target)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }

    }
    else
    {
        e=s;
        s=0;
        while(s<=e)
        {
            mid=(s+e)/2;
            if(nums[mid]==target)
            {
                k=1;
                break;
            }
            else if(nums[mid]>target)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
    }
    if(k==1)
    {
        ans=mid;
    }
    else
    {
        ans=-1;
    }
    return ans;
}
void main()
{
	int a[100],n,target;
	printf("Enter the number of elements in a array\n");
	scanf("%d", &n);
	printf("Enter the value of array\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter the key element to search\n");
	scanf("%d", &target);
	int ans=search(a,n,target);
	printf("%d", ans);
}

