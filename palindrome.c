#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
	char ch;
	struct node *left;
	struct node *right;
};

struct node *head,*tail;
char str[50];
int l;

void createlist()
{
	int x=0;
	struct node *ptr = (struct node*) malloc(sizeof(struct node));
	head = ptr;
	tail = ptr;
	ptr->left = NULL;
	ptr->right = NULL;
	
	ptr->ch = tolower(str[0]);
	x++;
	while(x<l)
	{
		ptr->right = (struct node*) malloc(sizeof(struct node));
		(ptr->right)->left = ptr;
		ptr = ptr->right;
		char c = tolower(str[x]);
		ptr->ch = c;
		ptr->right = NULL;
		tail=ptr;
		x++;
	}
}

/*void display()
{
	struct node *start = head;
	struct node *end = tail;
	while(start!=end)
	{
		printf("%c",start->ch);
		start = start->right;
	}
}*/

int check()
{
	int x=0;
	struct node *start,*end;
	start = head;
	end = tail;
	while(x<(l/2))
	{
		if(start->ch != end->ch)
		{
			return 0;
		}
		else
		{
			start = start->right;
			end = end->left;
		}
		x++;
	}
	return 1;
	
}

int main()
{
	int res;
	printf("Enter the string:");
	scanf("%[^\n]%*c",str);
	l = strlen(str);
	createlist();
	res = check();
	if(res == 1)
	{
		printf("\nThe string is palindrome\n");
	}
	else
	{
		printf("\nThe string is not palindrome\n");
	}
	return 0;
}














