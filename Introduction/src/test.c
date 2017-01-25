#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "permutations.h"
#include "zhimi.h"
void RandomArray(int* nums,int size,int max)
{
	int i=0;
	for(;i<size;i++)
	{
		nums[i]=rand()%max;
	}
}

void Print_Arrays(int* nums,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf(" %d ",nums[i]);
	}
	printf("\n");
}

#define N 1000
int main()
{
	int i,j;
	int arrays[N];
	RandomArray(arrays,N,N*2);
	Print_Arrays(arrays,N);
	//void merge_sort(int* nums,int start,int end);
	merge_sort(arrays,0,N-1);
	Print_Arrays(arrays,N);
	//int test_sort(int *nums,int size);
	if(test_sort(arrays,N)==1)
	{
		printf("The result is right!!!");
	}
	else printf("The result is false!!!");
}

/*int main()
{
	//double compute(double HP1,double attack1,double HP2,double attack2)
	double HP1,attack1,HP2,attack2;
	printf("please input HP1 attack1 and HP2 attack2\n");
	scanf("%lf%lf%lf%lf",&HP1,&attack1,&HP2,&attack2);
	double result=compute(HP1,attack1,HP2,attack2);
	printf("\n*************\nthe optimal attack is %.3lf\n",result);
	
	//int zhimi_isOptimal(double* result,double HP1,double attack1,double HP2,double attack2)
	int isP=zhimi_isOptimal(&result,HP1,attack1,HP2,attack2);
	if(isP==0)
	{
		printf("\nthe results is false!!!!!");
	}
	else
	{
		printf("\nthe results is true!!!!!");
	}
}*/

 









