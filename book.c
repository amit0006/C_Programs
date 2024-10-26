/*Book Allocation problem
allocate the number of books given by the user in 2 students such that the answer returned should be the minimum of the maximum number of pages of books allocated
for example, if we have 4 books in which the pages are 10,20,30,40
then  the possibilitites of books are 10 and 90 (max is 90)
30 and 70 (max is 70)
60 and 40 (max is 60)
so the lowest maximum of the books is 60.
SO the answer to be returned is 60*/
#include<stdio.h>
void main(){
	printf("Enter the number of books\n");
	int n;
	scanf("%d", &n);
	int b[100];  //Array for the number of pages that each book contains
	printf("Enter the pages of the book\n");
	for(int i=0;i<n;i++)
		scanf("%d", &b[i]);
	int total=0;//For the total number of books
	for(int i=0;i<n;i++)
		total=total+b[i];
	int s=0,e=total,mid,count=n,first=0,sec=0;
	while(s<e){ //Applying binary search techniques
		mid=(s+e)/2;
		printf("The mid value is %d\n", mid);
		count=n;
		first=0;
		sec=0;
		for(int i=0;i<n;i++){
			if((first+b[i])<=mid){
				first=first+b[i];
				count--;
				printf("first is %d\n", first);
			}
			else if((sec+b[i])<=mid){
				sec=sec+b[i];
				count--;
				printf("Second is %d\n", sec);
			}
			else
				break;
		}
		printf("The count is %d\n", count);
		if(count==0)//If count is 0 then all the books are allocated means if we take higher number then it will be allocated for that also so we should take a less than mid
			e=mid-1;
		else //If count > 0 then all the books are not allocated then we shoudl search for the number whihc is greater then mid
			s=mid+1;
	}
	if(first>sec)
		printf("The minimum of the maximum nuber of pages alloted is : %d\n", first);
	else
		printf("The minimum of the maximum nuber of pages alloted is : %d\n", sec);
}
