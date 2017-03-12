#include <stdio.h>
#include <stdlib.h>
void perm(int *nums,int numsSize,int* returnSize,int** res,int start,int end)	//end is the index instead of length of nums
{
	int i,temp;
	if(start==end)
	{
		//initial an array
		int* tempA=(int*)malloc(numsSize*sizeof(int));
		for(i=0;i<numsSize;i++)
		{
			tempA[i]=nums[i];
		}
		res[(*returnSize)++]=tempA;
		return;
	}
	i=start;
	for(;i<=end;i++)	//exchange nums[i] with nums[start]
	{
		if(i!=start&&nums[i]==nums[start])
		{
			continue;
		}
		temp=nums[start];
		nums[start]=nums[i];
		nums[i]=temp;
		
		perm(nums,numsSize,returnSize,res,start+1,end);
		
		temp=nums[start];
		nums[start]=nums[i];
		nums[i]=temp;
	}
}

int resSize(int n)
{
	int sum=1;
	while(n>1)
	{
		sum=sum*n;
		n--;
	}
	return sum;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) 
{
	int N=resSize(numsSize);
	int** res=(int**)malloc(N*sizeof(int*));
    perm(nums,numsSize,returnSize,res,0,numsSize-1);
	return res;
}

void free_permutations(int numsSize,int** res)
{
	int i;
	int times=resSize(numsSize);
	for(i=0;i<times;i++)
	{
		free(res[i]);
	}
	free(res);
}
