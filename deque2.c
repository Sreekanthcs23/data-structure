#include<stdio.h>
int queue[20];
int max,front=-1,rear=-1,flag=1;
void pushf(int);
int popf();
void pushr(int);
int popr();
void display();
int main()
{
	int elem,n,delitem;
	char ch;
	printf("Enter max size of the queue:");
	scanf("%d",&max);
	do 
	{
		printf("\nEnter 1 for insertion at rear , 2 for insertion at front, 3 for deletion at rear, 4 for deletion at front:");
		scanf("%d",&n);
		if(n==1)
		{
			printf("\nEnter the element to be inserted:");
			scanf("%d",&elem);
			pushr(elem);
			display();
		}
		else if(n==2)
		{
			printf("\nEnter the element to be inserted:");
			scanf("%d",&elem);
			pushf(elem);
			display();
		}
		else if(n==3)
		{
			delitem = popr();
			if(flag!=0) 
			{
				printf("\nDeletd item = %d",delitem);
				display();
			}
		}
		else if(n==4)
		{
			delitem = popf();
			if(flag!=0) 
			{
				printf("\nDeletd item = %d",delitem);
				display();
			}
		}
		else 
			printf("\nInvalid input");
		printf("\nDo you want to conyinue enter y or n:");
		scanf(" %c",&ch);
	}while(ch=='y');
	return 0;
}
void pushr(int e)
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
void pushf(int e)
{
	if((front==0 && rear==max-1)||(front==rear+1))
	{
		printf("\nOverflow");
		return;
	}
	else if(front == -1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[front]=e;
		return;
	}
	else if(front==0 && rear!=max-1)
	{
		front=max-1;
		queue[front]=e;
		return;
	}
	else
	{
		front--;
		queue[front] = e;
		return;
	}
}
int popr()
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
		i = queue[rear];
		front= -1;
		rear = -1;
		return i;
	}
	else if(rear==0)
	{
		i = queue[rear];
		rear=max-1;
		return i;
	}
	else
	{
		i = queue[rear];
		rear--;
		return i;
	}
}
int popf()
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
		i = queue[front];
		front= -1;
		rear = -1;
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
		i = queue[front];
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


