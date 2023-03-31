#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
};

struct node *table[10];

void init()
{
	for(int i=0;i<10;i++)
		table[i] = NULL;
}

void insert(int value)
{
	int hkey = value%10;
	int i,index;
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = value;
	for(i=0;i<10;i++)
	{
		index = (hkey+i)%10;
		if(table[index]==NULL)
		{
			table[index] = newnode;
			break;
		}
	}
	if(i==10)
		printf("Element cannot be inserted\n");
}

void delete(int value)
{
	int i,index;
	int hkey = value%10;
	for(i=0;i<10;i++)
	{
		index = (hkey+i)%10;
		if(table[index]!=NULL)
		{
			if(table[index]->data==value)
			{
				table[index] = NULL;
				break;
			}
		}
	}
	if(i==10)
		printf("Value not found\n");
}

void search(int value)
{
	int i,index;
	int hkey = value%10;
	for(i=0;i<10;i++)
	{
		index = (hkey+i)%10;
		if(table[index]!=NULL)
		{
			if(table[index]->data==value)
			{
				printf("Value %d found at index %d\n",value,index);
				break;
			}
		}
	}
	if(i==10)
		printf("Value not found\n");
}

void display()
{
	printf("Hash Table\n");
	for(int i=0;i<10;i++)
	{
		if(table[i]!=NULL)
			printf("Index - %d  Value - %d\n",i,table[i]->data);
		else
			printf("Index - %d  Value - NULL\n",i);
	}
}

int main()
{
	init();
	int op,elem;
	char ch;
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
				  search(elem);
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
