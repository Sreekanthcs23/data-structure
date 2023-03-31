#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	char name[20];
	int number;
	int marks;
	struct student *next;
};

struct student *head,*sorted;

void insert(char n[],int num,int m,struct student **hi)
{
	
	struct student *new = (struct student *) malloc(sizeof(struct student));
	strcpy(new->name,n);
	new->number = num;
	new->marks = m;
	new->next = (*hi);
	(*hi) = new;
}


void delete(int key,struct student **h)
{
	struct student *temp = *h,*prev;
	if(temp!=NULL && temp->number == key)
	{
		*h = temp->next;
		free(temp);
		return;
	}
	while(temp!=NULL && temp->number!=key)
	{
		prev =  temp;
		temp = temp->next;
	}
	if(temp==NULL)
	{
		return;
	}
	prev->next = temp->next;
	free(temp);
}

void search(int key)
{
	struct student *ptr = head;
	while(ptr!=NULL)
	{
		if(ptr->number==key)
		{
			printf("\nSearched entry:  Name: %s  Number: %d  Marks: %d",ptr->name,ptr->number,ptr->marks);
			return;
		}
		ptr = ptr->next;
	}
	printf("\nEntry not found");
	return;
}

void sort()
{
	struct student *small,*ptr;
	sorted = NULL;
	int min,x=2;
	while(head!=NULL)
	
	{
		ptr = head;
		min= ptr->number;
		small = ptr;
		while(ptr!=NULL)
		{
			if((ptr->number) > min)
			{
				min = ptr->number;
				small = ptr;
			}
			ptr = ptr->next;
		}
		insert(small->name,small->number,small->marks,&sorted);
		delete(small->number,&head);
	}
	head = sorted;
}

void display()
{
	struct student *ptr = head;
	printf("\nStudent details:\n");
	while(ptr!=NULL)
	{
		printf("Name: %s  Number: %d  Marks: %d\n",ptr->name,ptr->number,ptr->marks);
		ptr = ptr->next;
	}
}

int main()
{
	int num,m,op,flag=0;
	char n[30],ch;
	printf("---Options---\n1.Insert\n2.Delete\n3.Search\n4.Sort\n");
	do
	{
		flag=0;
		printf("Enter an option:");
		scanf(" %d",&op);
		switch(op)
		{
			case 1: printf("Enter the name: ");
				scanf("%s",n);
				printf("Enter the number: ");
				scanf("%d",&num);
				printf("Enter the marks: ");
				scanf("%d",&m);
				struct student *ptr = head;
				while(ptr!=NULL)
				{
					if(ptr->number == num)
					{
						printf("\nThe number already present\n");
						flag=1;
						break;
					}
					ptr = ptr->next;
				}
				if(flag==0)
					insert(n,num,m,&head);
				display();
				break;
			case 2: printf("Enter the number of the student to be deleted: ");
				scanf("%d",&num);
				delete(num,&head);
				display();
				break;
			case 3: printf("Enter the number of the student to be searched: ");
				scanf("%d",&num);
				search(num);
				break;
			case 4: sort();
				printf("After sorting\n");
				display(); 
				break;
			default: printf("Invalid option\n");
				 break;
		}
		printf("\nDo you want to continue y or n:");
		scanf(" %c",&ch);
	}while(ch!='n');
	return 0;
}












