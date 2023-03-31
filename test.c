#include<stdio.h>
#include<stdlib.h>
int main()
{
	system("mkdir c");
	system("cp test.c ./c/");
	//system("cd ./copy");
	system("gcc ./c/test.c");
	
	system("./c/a.out"); 
	return 0;
}















