#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "permutations.h"
void RandomArray(int* nums,int size,int max)
{
	int i=0;
	for(;i<size;i++)
	{
		nums[i]=rand()%max;
	}
}

#define N 3
int main()
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
}











