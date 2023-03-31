#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

int f=1;
struct node *new,*front,*rear,*top;

void createNode()
{
	new = (struct node*) malloc(sizeof(struct node*));
	return;
}

void enque(int el)
{
	createNode();
	if((front==NULL)&&(rear==NULL))
	{
		front = new;
		rear = new;
		rear->data = el;
		rear->link = NULL;
	}
	else
	{
		rear->link = new;
		rear = new;
		rear->data = el;
		rear->link = NULL;
	}
}

int deque()
{
	int it;
	f = 1;
	if((front==NULL)&&(rear==NULL))
	{
		printf("\nUnderflow\n");
		f=0;
	}
	else if(front==rear)
	{
		it = front->data;
		free(front);
		front= NULL;
		rear = NULL;
		return it;
	}
	else 
	{
		it = front->data;
		struct node *temp = front;
		front = front->link;
		free(temp);
		return it;
	}
}

void push(int el)
{
	createNode();
	if(top==NULL)
	{
		top = new;
		new->data = el;
		new->link = NULL;
	}	
	else 
	{
		new->link = top;
		new->data = el;
		top = new;
	}
}

int pop()
{
	f=1;
	int it;
	struct node *ptr = top;
	if(ptr==NULL)
	{
		printf("\nstack underflow\n");
		f=0;
	}
	else
	{
		it = ptr->data;
		top = ptr->link;
		free(ptr);
		return it;
	}
}

void display() 
{
	struct node* ptr = front;
	while(ptr!=NULL)
	{
		printf("%d   ",ptr->data);
		ptr = ptr->link;
	}
}

int main()
{
	int l=0,elem;
	char ch;
	do
	{
		printf("Enter the queue element:");
		scanf("%d",&elem);
		enque(elem);
		l++;
		printf("\nEnter y OR n:");
		scanf(" %c",&ch);
	}while(ch!='n');
	printf("\nQueue:  ");
	display();
	for(int i=1;i<=l;i++)
	{
		push(deque());
	}
	for(int i=1;i<=l;i++)
	{
		enque(pop());
	}
	printf("\nQueue reverse:  ");
	display();
	return 0;
}






















