#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int coeff;
	int pow;
	struct node *link;
};

struct node *head1=NULL,*head2=NULL,*headr=NULL;

void insertpoly(struct node **head)
{
	struct node *ptr;
	char ch;
	ptr = (struct node*) malloc(sizeof(struct node));
	*head = ptr;
	ptr->link = NULL;
	printf("\nEnter coefficient:");
	scanf("%d",&(ptr->coeff));
	printf("\nEnter power:");
	scanf("%d",&(ptr->pow));
	printf("\nDo you want to continue y or n:");
		scanf(" %c",&ch);
	while(ch!='n')
	{
		ptr->link = (struct node*) malloc(sizeof(struct node));
		ptr = ptr->link;
		ptr->link = NULL;
		printf("\nEnter coefficient:");
		scanf("%d",&(ptr->coeff));
		printf("\nEnter power:");
		scanf("%d",&(ptr->pow));
		printf("\nDo you want to continue y or n:");
		scanf(" %c",&ch);
	}
}

void display(struct node *ptr)
{
	while(ptr!=NULL)
	{
		printf("%d X^ %d + ",ptr->coeff,ptr->pow);
		ptr = ptr->link;
	}
}

void calculate(struct node *ptr1,struct node *ptr2,struct node *result)
{
	struct node *ptr,*temp;
	while((ptr1!=NULL) && (ptr2!=NULL))
	{
		if(ptr1->pow > ptr2->pow)
		{
			result->coeff = ptr1->coeff;
			result->pow = ptr1->pow;
			ptr1 = ptr1->link;
		}
		else if(ptr1->pow < ptr2->pow)
		{
			result->coeff = ptr2->coeff;
			result->pow = ptr2->pow;
			ptr2 = ptr2->link;
		}
		else
		{
			result->coeff = ptr1->coeff+ptr2->coeff;
			result->pow = ptr1->pow;
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		result->link = (struct node*) malloc(sizeof(struct node));
		result = result->link;
		result->link = NULL;
		
	}
	while(ptr1!=NULL)
	{
		result->coeff = ptr1->coeff;
		result->pow = ptr1->pow;
		ptr1 = ptr1->link;	
		result->link = (struct node*) malloc(sizeof(struct node));
		result = result->link;
		result->link = NULL;
	}
	while(ptr2!=NULL)
	{
		result->coeff = ptr2->coeff;
		result->pow = ptr2->pow;
		ptr2 = ptr2->link;	
		result->link = (struct node*) malloc(sizeof(struct node));
		result = result->link;
		result->link = NULL;
	}
}

int main()
{
	printf("Enter the 1st polynomial:\n");
	insertpoly(&head1);
	printf("\nEnter the 2nd polynomial:\n");
	insertpoly(&head2);
	struct node *result = (struct node*) malloc(sizeof(struct node));
	headr = result;
	calculate(head1,head2,result);
	printf("\n1st polynomial: ");
	display(head1);
	printf("\n2nd polynomial: ");
	display(head2);
	printf("\nResult polynomial: ");
	display(headr);
}















