#include<stdio.h>
struct poly{
	int cf;
	int px;
};
struct poly p1[100];
struct poly p2[100];
struct poly p3[100];
int m,n;
void read(){
	printf("Enter the number of terms of polynomial 1\n");
	scanf("%d", &m);
	printf("Enter the number of terms of polynomial 2\n");
	scanf("%d", &n);
	printf("Enter the polynomial 1\n");
	for(int i=0;i<m;i++){
		printf("Enter the coefficient of term %d:", i);
		scanf("%d", &p1[i].cf);
		printf("Enter the power of the term %d:", i);
		scanf("%d", &p1[i].px);
	}
	printf("Enter the polynomial 2\n");
	for(int i=0;i<n;i++){
                printf("Enter the coefficient of term %d:", i);
                scanf("%d", &p2[i].cf);
                printf("Enter the power of the term %d:", i);
                scanf("%d", &p2[i].px);
        }
	printf("The polynomial you have entered is \n");
	printf("Polynomial 1:");
	for(int i=0;i<m;i++){
		if(p1[i].cf!=0){
			if(p1[i].cf<0)
				printf("%d", p1[i].cf);
			else
				printf("+%d", p1[i].cf);
			if(p1[i].px!=0)
				printf("x^%d", p1[i].px);
		}
	}
	printf("\n");
	printf("Polynomial 2:");
        for(int i=0;i<n;i++){
                if(p2[i].cf!=0){
                        if(p2[i].cf<0)
                                printf("%d", p2[i].cf);
                        else
                                printf("+%d", p2[i].cf);
                        if(p2[i].px!=0)
                                printf("x^%d", p2[i].px);
                }
        }
	printf("\n");
}
void display(){
	printf("The resultant expression is : ");
	for(int i=0;p3[i].cf!=-999;i++){
		if(p3[i].cf!=0){
                        if(p3[i].cf<0)
                                printf("%d", p3[i].cf);
                        else
                                printf("+%d", p3[i].cf);
                        if(p3[i].px!=0)
                                printf("x^%d", p3[i].px);
                }
		}
	printf("\n");
}
int search(int x){
        for(int i=0;i<n;i++){
	        if(p1[x].px==p2[i].px)
                        return i;
        }
        return -1;
}
void copy(int x){
        for(int i=0;i<n;i++){
                if(p2[i].cf!=-999){
                        p3[x].cf=p2[i].cf;
                        p3[x++].px=p2[i].px;
                }
        }
	p3[x].cf=-999;
}
void add(){
	int cf1,px1,pos,sum,k=0;
	for(int i=0;i<m;i++){
		cf1=p1[i].cf;
		px1=p1[i].px;
		pos=search(i);
		if(pos>=0){
			sum=cf1+p2[pos].cf;
			p3[k].cf=sum;
			p2[pos].cf=-999;
		}
		else
			p3[k].cf=cf1;
		p3[k++].px=px1;
	}
	copy(k);
}
void main(){
	read();
	add();
	display();
}
