#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 10
char stack[MAX];
int top=-1;
void push(char ch){
	stack[++top]=ch;
}
char pop(){
	return (stack[top--]);
}
int pr(char ch){
	switch (ch)
	{
		case '#':
				return 0;
		case '(':
				return 1;
		case '+':
		case '-':
				return 2;
		case '*':
		case '/':
		case '%':
				return 3;
		case '^':
				return 4;
	}

}
void main(){
	char infix[100];
	printf("Enter the infix expression\n");
	scanf("%s", infix);
	char a[100];
	int k=0;
	push('#');
	int i=0;
	while(i<strlen(infix))
	{
		char ch=infix[i++];
		if(isalnum(ch)){
			a[k++]=ch;
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^'){
			while(pr(ch)<=pr(stack[top]))
				a[k++]=pop();
			push(ch);
		}
		else if(ch=='('){
			push(ch);
		}
		else if(ch==')'){
			while(stack[top]!='('){
				a[k]=pop();
				k++;
			}
			char x=pop();
		}
	}
	i=0;
	while(stack[top]!='#')
		a[k++]=pop();
	printf("The postfix expression is : \n");
	a[k]='\0';
	printf("%s", a);
	
}
