void findreplacement()
{
	struct node *replace_node = del_node;
	if(del_node->right!=NULL)
	{
		replace_node = del_node->right;
		while(replace_node->left!=NULL)
			replace_node = replace_node->left;
	} 
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
	replace_node = root;
	parent_node = root;
	del_node = NULL;
	finddelnode(current_node,value);
	findlastnode(current_node);
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
