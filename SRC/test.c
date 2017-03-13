#include <stdio.h>
#include <stdlib.h>
void add(int *nums)
{
	(*nums)++;
	//*nums=*nums+1;
}

int main()
{
	int width=3,height=6;
	int i=0,j=0;
	int** res=(int**)malloc(height*sizeof(int*));
	for(;i<height;i++)
	{
		res[i]=(int*)malloc(width*sizeof(int));
	}
	
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			res[i][j]=i+1;
		}
	}
	
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	
	int abb=0;
	int *b=&abb;
	add(b);
	printf("%d",abb);
}

