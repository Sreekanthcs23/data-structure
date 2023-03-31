#include<stdio.h>
#include<ctype.h>
#include<math.h>
char expr[20],post[20],stack[20];
int top=-1;
int l1,l2,k=0;
void convert();
int pre(char);
int assoc(char);
void push(char);
void evaluate();
char pop();
int main()
{
	printf("Enter the expression: ");
	scanf("%s",expr);
	while(expr[l1]!='\0')
		l1++;	
	convert();
	while(top!=-1)
	{
		post[k] = stack[top];
		k++;
		top--;
	}
	printf("\nPost fix : ");
	for(int i=0;i<k;i++)
		printf("%c",post[i]);
	evaluate();
	printf("\nResult = %d",stack[top]);
}
void convert()
{
	char ch;
	int a,p1,p2,fl;
	for(int i=0;i<l1;i++)
	{
		ch = expr[i];
		if(isalnum(ch))
		{
			post[k] = ch;
			k++;
		}
		else if(ch == '(')
		{
			push(ch);
		}
		else if(ch == ')')
		{
			while(stack[top]!='(')
			{
				post[k] = pop();
				k++;
			}
			if(stack[top]=='(')
			{
				pop();
			}
		}
		else
		{
			fl = 0;
			while(fl==0)
			{
				p1 = pre(stack[top]);
				p2 = pre(ch);
				if(p2>p1)
				{
					push(ch);
					fl = 1;
				}
				else if(p1>p2)
				{
					post[k] = pop();
					k++;
					fl =0;
				}
				else 
				{
					a = assoc(ch);
					if(a==2)
						push(ch);
					else 
					{
						post[k] = pop();
						k++;
						push(ch);
					}
					fl=1;
				}
			}
		}
	}
} 
int pre(char ch)
{
	if(ch == '^')
		return 2;
	else if(ch == '*' || ch == '/')
		return 1;
	else if(ch == '+' || ch == '-')
		return 0;
	else 
		return -1;
}
int assoc(char ch)
{
	if(ch == '^')
		return 2;
	else 
		return 1;
}
void push(char ch)
{
	top++;
	stack[top] = ch;
}
char pop()
{
	char ch = stack[top];
	top--;
	return ch;
}
void evaluate()
{
	char op,ch;
	int x,y,j,p;
	for(int i=0;i<k;i++)
	{
		ch = post[i];
		if(isalnum(ch))
		{
			j = ch - '0';
			push(j);
		}
		else
		{
			op = ch;
			x = pop();
			y = pop();
			switch(op)
			{
				case '^': p = pow(y,x);
					  push(p);
					  break;
				case '*': push(y*x);
					  break;
				case '/': push(y/x);
					  break;
				case '+': push(y+x);
					  break;
				case '-': push(y-x);
					  break;
			}
		}
	}
}

















