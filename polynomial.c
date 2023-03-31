#include<stdio.h>
int main()
{
	int a[2][20],ff=0,ss,sf,rs,i,j,k,n1,n2;
	printf("Enter number of terms in 1st polynomail");
	scanf("%d",&n1);
	while (ff < n1)
	{
		printf("\nEnter exponent:");
		scanf("%d",&a[0][ff]);
		printf("\nEnter coefficient:");
		scanf("%d",&a[1][ff]);
		ff++;
	}
	ff--;	
	ss=ff+1;
	sf=ff+1;
	printf("Enter number of terms in 2nd polynomail");
	scanf("%d",&n2);
	while (sf < n1+n2)
	{
		printf("\nEnter exponent:");
		scanf("%d",&a[0][sf]);
		printf("\nEnter coefficient:");
		scanf("%d",&a[1][sf]);
		sf++;
	}
	sf--;
	rs=sf+1;
	i=0;
	j=ss;
	k=rs;
	while(i<=ff&&j<=sf)
	{
		if(a[0][i]==a[0][j])
		{
			a[1][k] = a[1][i] + a[1][j];
			a[0][k] = a[0][i];
			i++;
			j++;
			k++;
		}
		else if(a[0][i]>a[0][j])
		{
			a[1][k] = a[1][i];
			a[0][k] = a[0][i];
			i++;
			k++;
		}
		else 
		{
			a[1][k] = a[1][j];
			a[0][k] = a[0][j];
			j++;
			k++;
		}
	}
	while(i<=ff)
	{
		a[1][k] = a[1][i];
		a[0][k] = a[0][i];
		i++;
		k++;
	}
	while(j<=sf)
	{
		a[1][k] = a[1][j];
		a[0][k] = a[0][j];
		j++;
		k++;
	}
	i=0;
	printf("\n1st polynomial : ");
	while(i<=ff)
	{
		printf("%dx^%d + ",a[1][i],a[0][i]);
		i++;
	}
	j=ss;
	printf("\n2nd polynomial : ");
	while(j<=sf)
	{
		printf("%dx^%d + ",a[1][j],a[0][j]);
		j++;
	}
	int p=rs;
	printf("\nResult polynomial : ");
	while(p<k)
	{
		printf("%dx^%d + ",a[1][p],a[0][p]);
		p++;
	}
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
