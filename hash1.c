#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *table[10];

void init()
{
	int i;
	for(int i=0;i<10;i++)
		table[i] = NULL;
}

void insert(int value)
{
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = NULL;
	int index = value%10;
	if(table[index]==NULL)
		table[index] = newnode;
	else
	{
		struct node *ptr = table[index];
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newnode;
	}
}

struct node* search(int value)
{
	int index = value%10;
	int flag=0;
	struct node *ptr = table[index];
	while(ptr!=NULL)
	{
		if(ptr->data==value)
		{
			flag=1;
			printf("Element %d found at index %d\n",ptr->data,index);
			return ptr;
		}
		ptr = ptr->next;
	}
	if(flag==0)
	{
		printf("Value not found in the table\n");
		return NULL;
	}
}

void delete(int value)
{
	int index = value%10;
	struct node *ptr = table[index];
	if(ptr==NULL)
	{
		printf("Element not present\n");
		return;
	}
	struct node *temp = ptr;
	int flag=0;
	if(ptr->data==value)
	{
		table[index] = ptr->next;
		free(ptr);
		return;
	}
	while(ptr!=NULL)
	{
		if(ptr->data==value)
		{
			flag=1;
			break;
		}
		else
		{
			temp = ptr;
			ptr = ptr->next;
		}
	}
	if(flag==1)
	{
		temp->next = ptr->next;
		free(ptr);
	}
	else
		printf("Value not found\n");
}

void display()
{
	for(int i=0;i<10;i++)
	{
		struct node *ptr = table[i];
		printf("Chain[%d]-->",i);
		while(ptr)
		{
			printf("%d -->",ptr->data);
			ptr = ptr->next;
		}
		printf("NULL\n");
	}
}

int main()
{
	init();
	int op,elem;
	char ch;
	struct node *ptr;
	printf("---OPTIONS---\n1.insert\n2.delete\n3.search\n4.display\n");
	do
	{
		printf("Enter the option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1 : printf("Enter the element:");
				 scanf("%d",&elem);
				 insert(elem);
				 break;
			case 2 : printf("Enter element to be deleted:");
				  scanf("%d",&elem);
				  delete(elem);
				  break;
			case 3 : printf("Enter element to be found:");
				  scanf("%d",&elem);
				  ptr=search(elem);
				  break;
			case 4 : display();
				  break;
			default : printf("Invalid option\n");
				  break; 
		}
		printf("Enter n to stop:");
		scanf(" %c",&ch);
	}while(ch!='n');
	return 0;
}




















