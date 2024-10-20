/*Develop a Program in C for the following Stack Applications 
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %,
^ */
#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 50
int stack[MAX];
int top=-1;
void push(int ch){
	stack[++top]=ch;
}
void calc(char c){
	int a,b,ans;
	a=stack[top--];
	/*stack[top]='\0';
	top--;*/
	b=stack[top--];
	/*stack[top]='\0';
	top--;*/
	switch(c){
		case '+':ans=(b+a);
			 break;
		case '-':ans=(b-a);
			 break;
		case '*':ans=(a*b);
			 break;
		case '/':ans=(b/a);
			 break;
		case '^':ans=pow(b,a);
			 break;
		default:printf("Invalid operator\n");
			return;
	}
	stack[++top]=ans;
}
void main(){
	char pstack[MAX];
	printf("Enter the suffix expression\n");
	scanf("%s", pstack);
	int n=strlen(pstack);
	for(int i=0;i<n;i++){
		if(pstack[i]>='0' && pstack[i]<='9')
			push(pstack[i]-48);
		else if(pstack[i]=='+' || pstack[i]=='-' || pstack[i]=='*' || pstack[i]=='/' || pstack[i]=='^')
			calc(pstack[i]);
	}
	printf("The result is : %d\n", stack[top]);
}

