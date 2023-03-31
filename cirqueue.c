#include<stdio.h>
int queue[5];
int max,front=-1,rear=-1,flag=1;
void push(int);
int pop();
void display();
int main()
{
	int elem,n,delitem;
	char ch;
	printf("Enter max size of the queue:");
	scanf("%d",&max);
	do 
	{
		printf("\nEnter 1 for insertion , 2 for deletion:");
		scanf("%d",&n);
		if(n==1)
		{
			printf("\nEnter the element to be inserted:");
			scanf("%d",&elem);
			push(elem);
			display();
		}
		else if(n==2)
		{
			delitem = pop();
			if(flag!=0) 
			{
				printf("\nDeletd item = %d",delitem);
				display();
			}
		}
		else
		{
			printf("\nInvlid option entered");
		}
		printf("\nDo you want to conyinue enter y or n:");
		scanf(" %c",&ch);
	}while(ch=='y');
	return 0;
}
void push(int e)
{
	if((front==0 && rear==max-1)||(front==rear+1))
	{
		printf("\nOverflow");
		return;
	}
	else if(rear==max-1)
	{
		rear=0;
		queue[rear]=e;
		return;
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=e;
		return;
	}
	else
	{
		rear++;
		queue[rear]=e;
		return;
	}
}
int pop()
{
	int i;
	flag=1;
	if(front==-1)
	{
		printf("\nUnderflow");
		flag=0;
	}
	else if(front==rear)
	{
		i = queue[front];
		front=-1;
		rear=-1;
		return i;
	}
	else if(front==max-1)
	{
		i= queue[front];
		front =0;
		return i;
	}
	else
	{
		i= queue[front];
		front++;
		return i;
	}
}
void display()
{
	printf("\nQueue: ");
	if(rear<front)
	{
		for(int i=front;i<max;i++)
		{
			printf(" %d ",queue[i]);
		}
		for(int i=0;i<=rear;i++)
		{
			printf(" %d ",queue[i]);
		}
	}
	else
	{	
		for(int i=front;i<=rear;i++)
		{
			printf(" %d ",queue[i]);
		}
	}
}



















