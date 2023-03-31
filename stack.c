#include<stdio.h>
void push(int [],int *,int,int);
int pop(int [],int *);
int flag=0;
int main()
{
	int top=-1,n,item,max,i,delitem;
	char ch;
	printf("Enter maximum size of the stack : ");
	scanf("%d",&max);
	int stack[max];
	do
	{
		printf("Enter 1 for push , 2 for pop: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: printf("Enter element to be pushed : ");
				scanf("%d",&item);
				push(stack,&top,item,max);
				break;
			case 2: delitem = pop(stack,&top);
				 if(flag==0)
				 	printf("\nDeleted item = %d\n",delitem);
				 break;
		}
		printf("\nStack = ");
		for(i=top;i>=0;i--)
			printf(" %d ",stack[i]);
		printf("\nDo you want to continue enter y/n:");
		scanf(" %c",&ch);
	}while(ch!='n');
	return 0;
}
void push(int s[],int *t,int it,int m)
{
	if(*t == m-1)
	{
		printf("\nStack overflow");
		return;
	}
	*t = (*t) + 1;
	s[*t]=it;
}
int pop(int s[],int *t)
{
	if(*t == -1)
	{
		printf("\nStack underflow");
		flag=1;
	}
	else
	{
		flag=0;
		int it = s[*t];
		*t = (*t) - 1;
		return it;
	}
}




















