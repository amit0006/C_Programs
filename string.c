#include<stdio.h>
#include<string.h>
char STR[100],PAT[100],REP[100],RES[100];
void read(){
	printf("Enter the main String:");
	scanf("%[^\n]s", STR);
	getchar();
	printf("Enter the pattern String:");
        scanf("%[^\n]s", PAT);
	getchar();
	printf("Enter the replacement String:");
        scanf("%[^\n]s", REP);
}
void match(){
	int i=0,k=0,m,x,n,t=0;
	int str_len=strlen(STR);
	int pat_len=strlen(PAT);
	int rep_len=strlen(REP);
	while(i<str_len){
		m=i;
		for(x=0;x<pat_len;x++){

			if(PAT[x]==STR[m])
				m++;
			else 
				break;
		}
		if(x==pat_len){
			for(n=0;n<rep_len;n++,k++){
				RES[k]=REP[n];
				t=1;
			}
			i=i+pat_len;
		}
		else{
			RES[k]=STR[i];
			k++;
			i++;
		}
	}
	RES[k]='\0';
	if(t==0)
		printf("The pattern does not exit in main string\n");
}
void display(){
	printf("The replaced sting is : %s\n", RES);
}
void main(){
	read();
	match();
	display();
}
