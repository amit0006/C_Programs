/*Find the sum of the polynomial containing three vaiable*/
#include<stdio.h>
struct poly{
        int cf;
        int px;
	int py;
	int pz;
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
                printf("Enter the power of the x in term %d:", i);
		printf("Going to take the Second element of p1\n");
                scanf("%d", &p1[i].px);
		printf("Enter the power of y in term %d\n", i);
		scanf("%d", &p1[i].py);
		printf("Enter the power of z in term %d\n", i);
		scanf("%d", &p1[i].pz);
        }
        printf("Enter the polynomial 2\n");
        for(int i=0;i<n;i++){
                printf("Enter the coefficient of term %d:", i);
                scanf("%d", &p2[i].cf);
                printf("Enter the power of x in term %d:", i);
                scanf("%d", &p2[i].px);
		printf("Enter the power of y in term %d\n", i);
                scanf("%d", &p2[i].py);
                printf("Enter the power of z in term %d\n", i);
                scanf("%d", &p2[i].pz);
        }
        printf("Polynomial 1:");
        for(int i=0;i<m;i++){
                if(p1[i].cf!=0){
                        if(p1[i].cf<0)
                                printf("%d", p1[i].cf);
                        else
                                printf("+%d", p1[i].cf);
                        if(p1[i].px!=0)
                                printf("x^%d", p1[i].px);
			if(p1[i].py!=0)
                                printf("y^%d", p1[i].py);
			if(p1[i].pz!=0)
                                printf("z^%d", p1[i].pz);
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
			if(p2[i].py!=0)
                                printf("y^%d", p2[i].py);
			if(p2[i].pz!=0)
                                printf("z^%d", p2[i].pz);
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
			if(p3[i].py!=0)
                                printf("y^%d", p3[i].py);
                        if(p3[i].pz!=0)
                                printf("z^%d", p3[i].pz);
                }
        }
        printf("\n");
}
int search(int x){
        for(int i=0;i<n;i++){
                if(p1[x].px==p2[i].px){
			if(p1[x].py==p2[i].py){
				if(p1[x].pz==p2[i].pz)
					return i;
			}
		}
        }
        return -1;
}
void copy(int x){
        for(int i=0;i<n;i++){
                if(p2[i].cf!=-999){
                        p3[x].cf=p2[i].cf;
                        p3[x].px=p2[i].px;
			p3[x].py=p2[i].py;
			p3[x++].pz=p2[i].pz;
                }
        }
        p3[x].cf=-999;
}
void add(){
        int cf1,px1,py1,pz1,pos,sum,k=0;
        for(int i=0;i<m;i++){
                cf1=p1[i].cf;
                px1=p1[i].px;
		py1=p1[i].py;
		pz1=p1[i].pz;
                pos=search(i);
                if(pos>=0){
                        sum=cf1+p2[pos].cf;
                        p3[k].cf=sum;
                        p2[pos].cf=-999;
                }
                else
                        p3[k].cf=cf1;
                p3[k].px=px1;
		p3[k].py=py1;
		p3[k++].pz=pz1;
        }
        copy(k);
}
void main(){
        read();
        add();
        display();
}
