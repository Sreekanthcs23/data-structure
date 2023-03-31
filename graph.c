#include<stdio.h>

int n,adj_mat[30][30],stateb[30],stated[30],queue[30],front=-1,rear=-1;

void create_graph()
{
	int count,max_edges,node1,node2;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	max_edges = n*(n-1);
	for(count=1;count<=max_edges;count++)
	{
		printf("Enter the edge %d (-1 -1 to quit) :",count);
		scanf("%d %d",&node1,&node2);
		if((node1 == -1) && (node2 == -1))
			break;
		if(node1 >= n || node2 >= n || node1 < 0 || node2 < 0)
		{
			printf("Invalid edge\n");
			count--;
		}
		else
		{
			adj_mat[node1][node2] = 1;
			adj_mat[node2][node1] = 1;
		}
	}
}

void enque(int v)
{
	if(front==-1)
		front++;
	rear++;
	queue[rear] = v;
	return;
}

int deque()
{
	int item;
	if(front==-1 || front > rear)
	{
		printf("Underflow\n");
	}
	else
	{
		item = queue[front];
		front++;
		return item;
	}
}

void bfs(int v)
{
	for(int i=0;i<n;i++)
		stateb[i] = 0;
	enque(v);
	stateb[v] = 1;
	while(!(front==-1 || front>rear))
	{
		v = deque();
		printf("  %d  ",v);
		for(int i=0;i<n;i++)
		{
			if((adj_mat[v][i]==1) && (stateb[i]==0))
			{
				enque(i);
				stateb[i] = 1;
			}
		}	
	}
	printf("\n");
}

void dfs(int v)
{
	stated[v] = 1;
	printf("  %d  ",v);
	for(int i=0;i<n;i++)
	{
		if((adj_mat[v][i]==1)&&(stated[i]==0))
			dfs(i);
	}
}

int main()
{
	int s;
	create_graph();
	printf("Enter the starting point:");
	scanf("%d",&s);
	printf("BFS:  ");
	bfs(s);
	for(int i=0;i<n;i++)
		stated[i] = 0;
	printf("DFS:  ");
	dfs(s);
	printf("\n");
	return 0;
}






















