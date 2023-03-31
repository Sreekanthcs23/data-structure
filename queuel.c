#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

int f=1;
struct node *new,*front,*rear;

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

void display() 
{
	struct node* ptr = front;
	printf("\nQueue:  ");
	while(ptr!=NULL)
	{
		printf("%d   ",ptr->data);
		ptr = ptr->link;
	}
}

int main()
{
	int elem,item,op;
	char ch;
	front = NULL;
	rear = NULL;
	printf("---OPTIONS---\n1.Enqueue\n2.Dequeue\n");
	do
	{
		printf("\nEnter the option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1: printf("\nEnter the element:");
				scanf("%d",&elem);
				enque(elem);
				display();
				break;
			case 2: item = deque();
				if(f==1)
				{
					printf("\nDeleted item = %d\n",item);
				}
				display();
				break;
			default: printf("\nInvalid option\n");
				 break;
		}
		printf("\nDo you want to continue y OR n:");
		scanf(" %c",&ch);
	}while(ch!='n');
	return 0;
}













