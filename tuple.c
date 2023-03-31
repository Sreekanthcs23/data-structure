#include<stdio.h>
void toTuple(int [][10],int [][3],int,int);
void transpose(int [][3],int [][3]);
void display(int [][3]);
void sum(int [][3],int [][3],int [][3]);
int main()
{
	int r1,c1,i,j,b1[10][3],r2,c2,b2[10][3],t1[10][3],t2[10][3],s1[10][3];
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
void toTuple(int a[][10],int b[][3],int r,int c)
{
	int i,j,k=1;
	b[0][0] = r;
	b[0][1] = c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
				b[k][0] = i;
				b[k][1] = j;
				b[k][2] = a[i][j];
				k++;
			}
		}
	}
	b[0][2] = k-1;
}
void transpose(int b[][3],int t[][3])
{
	int i;
	t[0][0] = b[0][0];
	t[0][1] = b[0][1];
	t[0][2] = b[0][2];
	for(i=1;i<=b[0][2];i++)
	{
		
		t[i][0] = b[i][1];
		t[i][1] = b[i][0];
		t[i][2] = b[i][2];
	}
}
void display(int b[][3])
{
	int i,j;
	for(i=0;i<=b[0][2];i++)
	{
		for(j=0;j<3;j++)
		{
			printf("  %d  ",b[i][j]);
		}
		printf("\n");
	}
}
void sum(int b1[][3],int b2[][3],int s[][3])
{
	int i,j,k;
	i = 1;
	j = 1;
	k=1;
	if(b1[0][0]!=b2[0][0] || b1[0][1]!=b2[0][1])
	{
		printf("\nAddition not possible");
		return;
	}
	else
	{
		s[0][0] = b1[0][0];
		s[0][1] = b1[0][1];
		while(i<=b1[0][2]&&j<=b2[0][2])
		{
			if(b1[i][0]==b2[j][0] && b1[i][1]==b2[j][1])
			{
				s[k][2] = b1[i][2] + b2[j][2];
				s[k][0] = b1[i][0];
				s[k][1] = b1[i][1];
				i++;
				j++;
			}
			else if(b1[i][0]<b2[j][0] || b1[i][1]<b2[j][1])
			{
				s[k][2] = b1[i][2];
				s[k][1] = b1[i][1];
				s[k][0] = b1[i][0];
				i++;
			}
			else
			{
				s[k][2] = b2[j][2];
				s[k][1] = b2[j][1];
				s[k][0] = b2[j][0];
				j++;
			}
			k++;
		}
		while(i<=b1[0][2])
		{
			s[k][2] = b1[i][2];
			s[k][1] = b1[i][1];
			s[k][0] = b1[i][0];
			i++;
			k++;
		}
		while(j<=b2[0][2])
		{
			s[k][2] = b2[j][2];
			s[k][1] = b2[j][1];
			s[k][0] = b2[j][0];
			j++;
			k++;
		}
		s[0][2] = k-1;
	}
}













