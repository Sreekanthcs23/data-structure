#include<stdio.h>
void binary();
int main()
{
	
	binary();
	return 0;
}
void binary()
{
	int b[20],j,p,ele,l,r,m,f=0;
	printf("Enter the number of elements:");
	scanf("%d",&p);
	printf("\nEnter the array\n");
	for(j=0;j<p;j++)
		scanf("%d",&b[j]);
	printf("\nEnter the element to be found:");
	scanf("%d",&ele);
	l=0;
	r=p-1;
	m=(l+r)/2;
	while(l<=r)
	{
		if(ele>b[m])
		{
			l=m+1;
		}
		else if(ele==b[m])
		{
			printf("\nElement found at index %d",m);
			f=1;
			break;
		}
		else
			r=m-1;
		m=(l+r)/2;
	}
	if(f==0)
		printf("\nElement not present in the array");
}
