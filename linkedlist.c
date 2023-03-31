#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void creatNode();
void insertB(int);
void display();
void insertE(int);
void insertP(int,int);
int deleteB();
int deleteE();
int deleteP(int);

struct node *new,*header;
int l=0,f=1;

int main()
{
	header = NULL;
	int elem,op,pos,item;
	char ch;
	printf("---OPTIONS---\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete from begining\n5.Delete from end\n6.Delete from position\n7.Display\n");
	do
	{
		printf("\nEnter the option : ");
		scanf("%d",&op);
		switch(op)
		{
			case 1: printf("\nEnter the data:");
				scanf("%d",&elem);
				insertB(elem);
				break;
			case 2: printf("\nEnter the data:");
				scanf("%d",&elem);
				insertE(elem);
				break;
			case 3: printf("\nEnter the data:");
				scanf("%d",&elem);
				printf("\nEnter the position:");
				scanf("%d",&pos);
				insertP(elem,pos);
				break;
			case 4: item = deleteB();
				if(f==1)
				{
					printf("\nDeleted item = %d",item);
				}
				break;
			case 5: item = deleteE();
				if(f==1)
				{
					printf("\nDeleted item = %d",item);
				}
				break;
			case 6: printf("\nEnter the position:");
				scanf("%d",&pos);
				item = deleteP(pos);
				if(f==1)
				{
					printf("\nDeleted item = %d",item);
				}
				break;
			case 7: display();
				break;
			default: printf("\nInvalid option\n");
				 break;
				
		}
		printf("\nDo you want to continue y or n:");
		scanf(" %c",&ch);
	}while(ch!='n');
	return 0;
}

void createNode()
{
	new = (struct node*) malloc(sizeof(struct node*));
	return;
}


void insertB(int el)
{
	createNode();
	if(header==NULL)
	{
		header = new;
		new->data = el;
		new->link = NULL;
	}	
	else 
	{
		new->link = header;
		new->data = el;
		header = new;
	}
	l++;
}

void insertE(int el)
{
	createNode();
	if(header==NULL)
	{
		header = new;
		new->data = el;
		new->link = NULL;
	}
	else
	{
		struct node *ptr = header;
		while(ptr->link!=NULL)
		{
			ptr = ptr->link;
		}
		ptr->link = new;
		new->data = el;
		new->link = NULL;
		
	}
	l++;
}

void insertP(int el, int p)
{
	int c = 1;
	createNode();
	struct node *ptr = header;
	if(p<1 || p>l+1)
	{
		printf("\ninvalid position\n");
		return;
	}
	if(header==NULL)
	{
		header = new;
		new->data = el;
		new->link = NULL;
	}
	else if(p==1)
	{
		new->link = header;
		new->data = el;
		header = new;
	}
	else if(p==l+1)
	{
		while(ptr->link!=NULL)
		{
			ptr = ptr->link;
		}
		ptr->link = new;
		new->data = el;
		new->link = NULL;
	}
	else 
	{
		while((ptr!=NULL)&&(c!=p-1))
		{
			ptr = ptr->link;
			c++;
		}
		new->link = ptr->link;
		new->data = el;
		ptr->link = new;
	}
	l++;
}

int deleteB()
{
	f=1;
	int it;
	struct node *ptr = header;
	if(ptr==NULL)
	{
		printf("\nNo element to be deleted\n");
		f=0;
	}
	else
	{
		it = ptr->data;
		header = ptr->link;
		free(ptr);
		return it;
	}
	l--;
}

int deleteE()
{
	f=1;
	int it;
	struct node *ptr = header;
	if(ptr==NULL)
	{
		printf("\nNo element to be deleted\n");
		f=0;
	}
	else if(ptr->link==NULL)		// Only one element present
	{
		it = ptr->data;
		header = ptr->link;
		free(ptr);
		return it;
	}
	else
	{
		struct node *temp;
		while(ptr->link!=NULL)
		{
			temp = ptr;
			ptr = ptr->link;
		}
		it = ptr->data;
		temp->link = NULL;
		free(ptr);
		return it;
	}
	l--;		
}

int deleteP(int p)
{
	int c = 1,it;
	struct node *ptr = header;
	if(p<1 || p>l)
	{
		printf("\nInvalid position\n");
		f=0;
	}
	else if(header==NULL)
	{
		printf("\nNo elements to be deleted\n");
		f=0;
	}
	else if(p==1)
	{
		it = ptr->data;
		header = ptr->link;
		free(ptr);
		return it;
	}
	else if(p==l)
	{
		struct node *temp;
		while(ptr->link!=NULL)
		{
			temp = ptr;
			ptr = ptr->link;
		}
		it = ptr->data;
		temp->link = NULL;
		free(ptr);
		return it;	
	}
	else
	{
		struct node *temp;
		while((ptr!=NULL) && (c!=p))
		{
			temp = ptr;
			ptr = ptr->link;
			c++; 
		} 
		it = ptr->data;
		temp->link = ptr->link;
		free(ptr);
		return it;
	}
	l--;
}

void display()
{
	int c = 1;
	struct node* ptr = header;
	printf("\n");
	while(ptr!=NULL)
	{
		printf("Node:%d Data:%d\n",c,ptr->data);
		c++;
		ptr = ptr->link;
	}
}




















