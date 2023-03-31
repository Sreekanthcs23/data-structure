#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
}*root;

int arr[20],i=0;

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

void sort(struct node *current_node)
{
	if(current_node != NULL)
	{
		sort(current_node->left);
		arr[i] = current_node->data;
		i++;
		printf(" %d ",current_node->data);
		sort(current_node->right);
	}
	else
		return;
}

int main()
{
	int len;
	printf("Enter the number of elements:");
	scanf("%d",&len);
	printf("Enter the elements:\n");
	for(int j=0;j<len;j++)
	{
		scanf("%d",&arr[j]);
		insert(&root,arr[j]);
	}
	sort(root);
	printf("Sorted array:  ");
	for(int j=0;j<len;j++)
	{
		printf("%d  ",arr[j]);
	}
	printf("\n");
	return 0;
}














