#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
}*largest_node,*del_node,*parent_node,*root;

int flag=0,child=0;

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

void inorder(struct node *current_node)
{
	if(current_node != NULL)
	{
		inorder(current_node->left);
		printf(" %d ",current_node->data);
		inorder(current_node->right);
	}
	else
		return;
}

void preorder(struct node *current_node)
{
	if(current_node != NULL)
	{
		printf(" %d ",current_node->data);
		preorder(current_node->left);
		preorder(current_node->right);
	}
	else
		return;
}

void postorder(struct node *current_node)
{
	if(current_node != NULL)
	{
		postorder(current_node->left);
		postorder(current_node->right);
		printf(" %d ",current_node->data);
	}
	else
		return;
}

void findparent(struct node *child_node,struct node *current_node)
{
	if(current_node==NULL)
		return;
	if(current_node->left == child_node)
	{
		child = 0;
		parent_node = current_node;
		return;
	}
	if(current_node->right == child_node)
	{
		child = 1;
		parent_node = current_node;
		return;
	}
	else
	{
		findparent(child_node,current_node->left);
		findparent(child_node,current_node->right);
	}
}

void findlargest(struct node *current_node)
{
	if(current_node == NULL)
		return;
	else
	{
		findlargest(current_node->left);
		largest_node = current_node;
		findlargest(current_node->right);
	}
}

void deletion(struct node *current_node,int value)
{
	parent_node = current_node;
	child =0;
	largest_node = current_node;
	if(current_node==NULL)
	{
		printf("\nDeletion not possible:");
		return;
	}
	else if(value < current_node->data)
	{
		deletion(current_node->left,value);
	}
	else if(value > current_node->data)
	{
		deletion(current_node->right,value);
	}
	else if(current_node->left && current_node->right)
	{
		findlargest(current_node->left);
		struct node *temp = largest_node;
		current_node->data = temp->data;
		temp->data = value;
		deletion(temp,value);
	}
	else
	{
		if(current_node->left==NULL && current_node->right==NULL)
		{
			findparent(current_node,root);
			if(child==0)
				parent_node->left=NULL;
			else
				parent_node->right = NULL;
			free(current_node);
		}
		else if(current_node->left!=NULL)
		{
			current_node->data = (current_node->left)->data;
			(current_node->left)->data = value;
			deletion(current_node->left,value);
		}
		else
		{
			current_node->data = (current_node->right)->data;
			(current_node->right)->data = value;
			deletion(current_node->right,value);
		}
	}
	
}

int main()
{
	int op,elem,del;
	char ch;
	root = NULL;
	printf("---Options---\n1.Insetion\n2.Inorder\n3.Preorder\n4.Postorder\n5.Deletion\n");
	do
	{
		printf("Enter the option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1: printf("\nEnter the element:");
				scanf("%d",&elem);
				insert(&root,elem);
				break;
			case 2: printf("\nInorder:  ");
				 inorder(root);
				break;
			case 3:  printf("\npreorder:  ");
				 preorder(root);
				 break;
			case 4:  printf("\npostorder:  ");
				 postorder(root);
				 break;
			case 5:  printf("\nEnter the element:");
				 scanf("%d",&del);
				 deletion(root,del);
				 break;
			default : printf("\nInvalid option:");
				  break;
		}
		printf("\nDo you want to continue y or n:");
		scanf(" %c",&ch);
	}while(ch!='n');
	return 0;
}












