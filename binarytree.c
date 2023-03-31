#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
}*last_node,*del_node,*parent_node,*root;

struct node *queue[30];

int front=-1,rear=-1;

void enque(struct node *ptr)
{
	if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		queue[rear] = ptr;
		return;
	}
	rear++;
	queue[rear] = ptr;
}

struct node* deque()
{
	struct node *ptr;
	if(front==-1)
		return NULL;
	else if(front==rear)
	{
		ptr = queue[front];
		front = -1;
		rear = -1;
		return ptr;
	}
	else
	{
		ptr = queue[front];
		front++;
		return ptr;
	}
}

int flag=0,child=0;

void insert(int value)
{
	front = -1;
	rear = -1;
	struct node *current_node=root,*newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;
	if(root == NULL)
	{
		root = newnode;
		return;
	}
	else
	{
		while(front<=rear)
		{
			if(current_node->left==NULL)
			{
				current_node->left = newnode;
				return;
			}
			if(current_node->right==NULL)
			{
				current_node->right = newnode;
				return;
			}
			if(current_node->left!=NULL)
				enque(current_node->left);
			if(current_node->right!=NULL)
				enque(current_node->right);
			current_node = deque();
		}
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

void findlastnode(struct node *current_node)
{
	if(current_node != NULL)
	{
		last_node = (current_node);
		if(current_node->left!=NULL)
		{
			parent_node = (current_node);
			child = 0;
		}
		findlastnode(current_node->left);
		if(current_node->right!=NULL)
		{
			parent_node = (current_node);
			child = 1;
		}
		findlastnode(current_node->right);
	}
	else
		return;
}

void finddelnode(struct node *current_node,int value)
{
	if(flag==1)
		return;
	if(current_node != NULL)
	{
		if(current_node->data == value)
		{
			del_node = (current_node);
			flag=1;
			return;
		}
		finddelnode(current_node->left,value);
		finddelnode(current_node->right,value);
	}
	else
		return;
}

void delete(struct node *current_node,int value)
{
	flag = 0;
	child=0;
	last_node = current_node;
	parent_node = current_node;
	del_node = NULL;
	findlastnode(current_node);
	finddelnode(current_node,value);
	if(last_node==current_node)
		root = NULL;
	if(flag==0)
	{
		printf("\nDeletion not possible\n");
		return;
	}
	del_node->data = last_node->data;
	if(child==0)
		parent_node->left = NULL;
	else
		parent_node->right = NULL;
	free(last_node);
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
				insert(elem);
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
				 delete(root,del);
				 break;
			default : printf("\nInvalid option:");
				  break;
		}
		printf("\nDo you want to continue y or n:");
		scanf(" %c",&ch);
	}while(ch!='n');
	return 0;
}
























