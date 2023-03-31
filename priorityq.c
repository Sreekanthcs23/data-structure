#include<stdio.h>
struct q
{
	int data;
	int prio;
};
struct q queue[20];
int max,front=-1,rear=-1,flag=1;
void push(int,int);
int pop();
void display();
int main()
{
	int elem,pr,n,delitem;
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
			printf("\nEnter the priority of the element:");
			scanf("%d",&pr);
			push(elem,pr);
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
void push(int e,int p)
{
	int i;
	if(rear==max-1)
	{
		printf("\nOverflow");
		return;
	}
	else if(front == -1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear].data=e;
		queue[rear].prio=p;
		return;
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			if(p<queue[i].prio)
			{
				break;
			}
		}
		for(int j=rear;j>=i;j--)
		{
			queue[j+1].data = queue[j].data;
			queue[j+1].prio = queue[j].prio;
		}
		rear++;
		queue[i].data = e;
		queue[i].prio = p;
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
	else if(front == rear)
	{
		i = queue[front].data;
		front= -1;
		rear = -1;
		return i;
	}
	else
	{
		i = queue[front].data;
		front++;
		return i;
	}
}
void display()
{
	printf("\nQueue: ");
	for(int i=front;i<=rear;i++)
	{
		printf(" %d:%d ",queue[i].data,queue[i].prio);
	}
}
