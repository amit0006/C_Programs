#include<stdio.h>
#include<stdbool.h>
bool isPossible(int mid,int n,int m,int a[]){
	int painter =1;
	int time=0;
	for(int i=0;i<n;i++){
		if((time+a[i])<=mid)
			time=time+a[i];
		else{
			painter++;
			if(painter>m||a[i]>mid)
				return false;
			time=a[i];
		}
	}
	return true;
}
void main(){
	int a[100],n;
	printf("Enter the number of boards\n");
	scanf("%d", &n);
	printf("Enter the boards\n");
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	int sum=0;
	for(int i=0;i<n;i++)
		sum=sum+a[i];
	int s=0;
	int e=sum;
	int mid,ans,m;
	printf("Enter the number of painters\n");
	scanf("%d", &m);
	while(s<=e){
		mid=(s+e)/2;
		if(isPossible(mid,n,m,a)){
			ans=mid;
			e=mid-1;
		}
		else
			s=mid+1;
	}
	printf("The smallest time is %d\n", ans);
}
