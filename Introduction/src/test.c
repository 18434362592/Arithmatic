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

#define N 3
/*int main()
{
	int i,j;
	int nums[N]={1,1,2};
	int returnSize=0;
	clock_t clock_start,clock_end,clock_total;
	clock_start=clock();
	//int** permuteUnique(int* nums, int numsSize, int* returnSize);
	int** res=permuteUnique(nums,N,&returnSize);
	clock_end=clock();
	clock_total=(double)clock_end-clock_start;
	for(i=0;i<returnSize;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	printf("total time taken by CPU is %f",(double)clock_total);
	//void free_permutations(int nums,int** res);
	free_permutations(N,res);
}*/

int main()
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
}











