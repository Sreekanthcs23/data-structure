#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

int l=0,f=1;
struct node *new,*top;

void createNode()
{
	new = (struct node*) malloc(sizeof(struct node*));
	return;
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
	l++;
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
	l--;
}

void display() 
{
	struct node* ptr = top;
	printf("\nStack:  ");
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
	top = NULL;
	printf("---OPTIONS---\n1.Push\n2.Pop\n");
	do
	{
		printf("\nEnter the option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1: printf("\nEnter the element:");
				scanf("%d",&elem);
				push(elem);
				display();
				break;
			case 2: item = pop();
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










