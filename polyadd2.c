#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int coeff;
	int xp;
	int yp;
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
	printf("\nEnter x power:");
	scanf("%d",&(ptr->xp));
	printf("\nEnter y power:");
	scanf("%d",&(ptr->yp));
	printf("\nDo you want to continue y or n:");
		scanf(" %c",&ch);
	while(ch!='n')
	{
		ptr->link = (struct node*) malloc(sizeof(struct node));
		ptr = ptr->link;
		ptr->link = NULL;
		printf("\nEnter coefficient:");
		scanf("%d",&(ptr->coeff));
		printf("\nEnter x power:");
		scanf("%d",&(ptr->xp));
		printf("\nEnter y power:");
		scanf("%d",&(ptr->yp));
		printf("\nDo you want to continue y or n:");
		scanf(" %c",&ch);
	}
}

void display(struct node *ptr)
{
	while(ptr!=NULL)
	{
		printf("%d X^%d Y^%d + ",ptr->coeff,ptr->xp,ptr->yp);
		ptr = ptr->link;
	}
}

void calculate(struct node *ptr1,struct node *ptr2,struct node *result)
{
	struct node *ptr;
	while((ptr1!=NULL) && (ptr2!=NULL))
	{
		if((ptr1->xp == ptr2->xp) && (ptr1->yp == ptr2->yp))
		{
			result->coeff = ptr1->coeff+ptr2->coeff;
			result->xp = ptr1->xp;
			result->yp = ptr1->yp;
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		else if((ptr1->xp+ptr1->yp) > (ptr2->xp+ptr2->yp))
		{
			result->coeff = ptr1->coeff;
			result->xp = ptr1->xp;
			result->yp = ptr1->yp;
			ptr1 = ptr1->link;
		}
		else if((ptr1->xp + ptr1->yp) < (ptr2->xp + ptr2->yp))
		{
			result->coeff = ptr2->coeff;
			result->xp = ptr2->xp;
			result->yp = ptr2->yp;
			ptr2 = ptr2->link;
		}
		else if((ptr1->xp) > (ptr2->xp))
		{
			result->coeff = ptr1->coeff;
			result->xp = ptr1->xp;
			result->yp = ptr1->yp;
			ptr1 = ptr1->link;
		}
		else
		{
			result->coeff = ptr2->coeff;
			result->xp = ptr2->xp;
			result->yp = ptr2->yp;
			ptr2 = ptr2->link;
		}
		result->link = (struct node*) malloc(sizeof(struct node));
		result = result->link;
		result->link = NULL;
		
	}
	while(ptr1!=NULL)
	{
		result->coeff = ptr1->coeff;
		result->xp = ptr1->xp;
		result->yp = ptr1->yp;
		ptr1 = ptr1->link;	
		result->link = (struct node*) malloc(sizeof(struct node));
		result = result->link;
		result->link = NULL;
	}
	while(ptr2!=NULL)
	{
		result->coeff = ptr2->coeff;
		result->xp = ptr2->xp;
		result->yp = ptr2->yp;
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



















