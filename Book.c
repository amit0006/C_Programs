/*Distribute the pages of n book to the m number of students such that the maximum of alloccated pages is the minimum in all the allocations*/
#include<stdio.h>
#include<stdbool.h>
bool isPossible(int arr[],int n,int m,int mid){ //Function to find if the distribution is possible on that mid value
	int sCount=1;
	int pageSum=0;
	for(int i=0;i<n;i++){
		if((arr[i]+pageSum)<=mid){
			pageSum=arr[i]+pageSum;
		}
		else{
			sCount++;
			if(sCount>m || arr[i]>mid)
				return false;
			pageSum=arr[i];
		}
	}
	return true;
}
void main(){
	int m,n,arr[10],mid; //No. of students = m,number of books=n,  
	printf("Enter the number of books\n");
	scanf("%d", &n);
	printf("Enter the pages of books\n");
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("Enter the number of students\n");
	scanf("%d", &m);
	int s=0;
	int sum=0;
	for(int i=0;i<n;i++)
		sum=sum+arr[i];
	int e=sum;
	int ans=-1;
	while(s<e){ //Implementing binary search method
		mid=(s+e)/2;
		if(isPossible(arr,n,m,mid)){
                        e=mid-1;
                        ans=mid;
		}
		else
			s=mid+1;
	}
	if(ans==-1)
		printf("Allocation of book is not possible\n");
	else
		printf("The minimum of maximum pages allocated to the student is %d\n", ans);
}

