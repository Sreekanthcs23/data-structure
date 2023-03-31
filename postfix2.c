#include<stdio.h>
#include<string.h>

char expr[50];

void convert(int x,int y)
{
	int p=0,l;
	l = y-x+1;
	if((y-x-1) == 3)
	{
		printf("%c%c%c",expr[x+1],expr[x+3],expr[x+2]);
		return;
	}
	if((y-x) == 0)
	{
		printf("%c",expr[x]);
		return;
	}
	for(int i=x+1;i<y+1;i++)
	{
		if(expr[i] == '(')
			p++;
		else if(expr[i]==')')
			p--;
		if(p==0)
		{
			convert(x+1,i);
			convert(i+2,y-1);
			printf("%c",expr[i+1]);
			return;
		}
	}
}

int main()
{
	printf("Enter the exression:");
	scanf("%s",expr);
	int l = strlen(expr);
	convert(0,l-1);
	return 0;
}















