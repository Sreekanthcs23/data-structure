#include<stdio.h>
#include<ctype.h>
#include<math.h>
char expr[50],prefix[50],stack[50],rev[50],prerev[50],temp[50];
int top=-1,stack2[50],top2=-1;
int l1=0,l2,k=0;
void convert();
int pre(char);
int assoc(char);
void push(char);
char pop();
void push2();
int pop2();
void evaluate();
int main()
{
	char c;
	printf("Enter the expression: ");
	scanf("%s",expr);
	while(expr[l1]!='\0')
		l1++;	
	for(int j=0;j<l1;j++)
	{
		if(expr[l1-j-1]=='(')
			rev[j]=')';
		else if(expr[l1-j-1]==')')
			rev[j]='(';
		else
			rev[j]=expr[l1-j-1];
	}
	convert();
	for(int j=0;j<k;j++)
	{
		prefix[j]=prerev[k-j-1];
	}
	printf("\nPre fix : ");
	for(int i=0;i<k;i++)
		printf("%c",prefix[i]);
	evaluate();
	
	printf("\nResult =%d",stack2[top2]);
	return 0;	
}
void convert()
{
	char ch;
	int a,p1,p2,fl;
	for(int i=0;i<l1;i++)
	{
		ch = rev[i];
		if(isalnum(ch))
		{
			prerev[k] = ch;
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
				prerev[k] = pop();
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
					prerev[k] = pop();
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
						prerev[k] = pop();
						k++;
						push(ch);
					}
					fl=1;
				}
			}
		}
	}
	while(top!=-1)
	{
		prerev[k] = stack[top];
		k++;
		top--;
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
void push2(int n)
{
	top2++;
	stack2[top2] = n;
}
int pop2()
{
	int n = stack2[top2];
	top2--;
	return n;
}
void evaluate()
{
	char ch,op;
	int x,y,j,p;
	for(int i=0;i<k;i++)
	{
		if(isalnum(prerev[i]))
		{
			printf("\nEnter the value of %c:",prerev[i]);
			scanf(" %c",&temp[i]);
		}
		else
			temp[i]=prerev[i];
			
	}
	for(int i=0;i<k;i++)
	{
		ch = temp[i];
		if(isalnum(ch))
		{
			j = ch - '0';
			push2(j);
		}
		else
		{
			op = ch;
			x = pop2();
			y = pop2();
			switch(op)
			{
				case '^': p = pow(x,y);
					  push2(p);
					  break;
				case '*': push2(x*y);
					  break;
				case '/': push2(x/y);
					  break;
				case '+': push2(x+y);
					  break;
				case '-': push2(x-y);
					  break;
			}
		}
	}	
}














