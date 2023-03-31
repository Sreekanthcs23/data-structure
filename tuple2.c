#include<stdio.h>
struct tup
{
	int row;
	int col;
	int val;
};
void toTuple(int [][10],struct tup [20],int,int);
void transpose(struct tup [20],struct tup [20]);
void display(struct tup [20]);
void sum(struct tup [20],struct tup [20],struct tup [20]);
int main()
{
	int r1,c1,i,j,r2,c2;
	struct tup b1[20],b2[20],t1[20],t2[20],s1[20];
	printf("Enter the number of rows and columns of 1st :");
	scanf("%d %d",&r1,&c1);
	printf("Enter the number of rows and columns of 2nd:");
	scanf("%d %d",&r2,&c2);
	int a1[r1][10],a2[r2][10];
	printf("Enter the 1st matrix : \n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&a1[i][j]);
		}
	}
	printf("Enter the 2nd matrix : \n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			scanf("%d",&a2[i][j]);
		}
	}
	toTuple(a1,b1,r1,c1);
	toTuple(a2,b2,r2,c2);
	printf("\n1st Matrix Tuple form:\n");
	display(b1);
	printf("\n2nd Matrix Tuple form:\n");
	display(b2);
	transpose(b1,t1);
	transpose(b2,t2);
	printf("Transpose of 1st: \n");
	display(t1);
	printf("Transpose of 2nd: \n");
	display(t2);
	sum(b1,b2,s1);
	printf("\nSum : \n");
	display(s1);
	return 0;
}
void toTuple(int a[][10],struct tup b[20],int r,int c)
{
	int i,j,k=1;
	b[0].row = r;
	b[0].col = c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
				b[k].row = i;
				b[k].col = j;
				b[k].val = a[i][j];
				k++;
			}
		}
	}
	b[0].val = k-1;
}
void transpose(struct tup b[20],struct tup t[20])
{
	int i;
	t[0].row = b[0].col;
	t[0].col = b[0].row;
	t[0].val = b[0].val;
	for(i=1;i<=b[0].val;i++)
	{
		
		t[i].row = b[i].col;
		t[i].col = b[i].row;
		t[i].val = b[i].val;
	}
}
void display(struct tup b[20])
{
	int i,j;
	for(i=0;i<=b[0].val;i++)
	{
		
		printf("  %d   %d   %d",b[i].row,b[i].col,b[i].val);
		printf("\n");
	}
}
void sum(struct tup b1[20],struct tup b2[20],struct tup s[20])
{
	int i,j,k;
	i = 1;
	j = 1;
	k=1;
	if(b1[0].row!=b2[0].row || b1[0].col!=b2[0].col)
	{
		printf("\nAddition not possible");
		return;
	}
	else
	{
		s[0].row = b1[0].row;
		s[0].col = b1[0].col;
		while(i<=b1[0].val&&j<=b2[0].val)
		{
			if(b1[i].row==b2[j].row && b1[i].col==b2[j].col)
			{
				s[k].val = b1[i].val + b2[j].val;
				s[k].row = b1[i].row;
				s[k].col = b1[i].col;
				i++;
				j++;
			}
			else if(b1[i].row<b2[j].row)
			{
				s[k].val = b1[i].val;
				s[k].col = b1[i].col;
				s[k].row = b1[i].row;
				i++;
			}
			else if(b1[i].row>b2[j].row)
			{
				s[k].val = b2[j].val;
				s[k].col = b2[j].col;
				s[k].row = b2[j].row;
				j++;
			}
			else if(b1[i].col<b2[j].col)
			{
				s[k].val = b1[i].val;
				s[k].col = b1[i].col;
				s[k].row = b1[i].row;
				i++;
			}
			else
			{
				s[k].val = b2[j].val;
				s[k].col = b2[j].col;
				s[k].row = b2[j].row;
				j++;
			}
			k++;
		}
		while(i<=b1[0].val)
		{
			s[k].val = b1[i].val;
			s[k].col = b1[i].col;
			s[k].row = b1[i].row;
			i++;
			k++;
		}
		while(j<=b2[0].val)
		{
			s[k].val = b2[j].val;
			s[k].col = b2[j].col;
			s[k].row = b2[j].row;
			j++;
			k++;
		}
		s[0].val = k-1;
	}
}













