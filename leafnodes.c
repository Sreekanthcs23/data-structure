#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
}*root;

int count=0;

void insert(struct node **current_node,int value)
{
	if(*current_node == NULL)
	{
		struct node *tmp = (struct node*) malloc(sizeof(struct node));
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->data = value;
		*current_node = tmp;
		return;
	}
	else if(value < ((*current_node)->data))
	{
		insert(&((*current_node)->left),value);
	}
	else
	{
		insert(&((*current_node)->right),value);
	}
}

void countleaf(struct node *current_node)
{
	if(current_node!=NULL)
	{
		countleaf(current_node->left);
		if(current_node->left==NULL && current_node->right==NULL)
		{
			count++;
		}
		countleaf(current_node->right);
	}
	else
		return;
}

int main()
{
	int elem;
	char ch;
	do
	{
		printf("\nEnter element to be inserted:");
		scanf("%d",&elem);
		insert(&root,elem);
		printf("\nEnter n to stop: y to continue:");
		scanf(" %c",&ch);
	}while(ch!='n');
	countleaf(root);
	printf("\nNumber of leaf nodes = %d",count);
	return 0;
}















