#include <stdio.h>
#include <stdlib.h>
static int count=0;
void perm(int *nums,int numsSize,int** res,int start,int end,int* returnSize) 
{
	if(start==end)
	{
		count++;
		int i=0;
		int *temp=(int*)malloc(numsSize*sizeof(int));
		for(;i<numsSize;i++)
		{
			temp[i]=nums[i];
		}
		res[*returnSize]=temp;
		(*returnSize)++;			//It is an very important to enclosed the pointer
		return;
	}
	int i=start;
	for(;i<=end;i++)
	{
		printf("(%d , %d) ",start,i);
		count++;
		int temp=nums[i];	
		nums[i]=nums[start];
		nums[start]=temp;
		
		perm(nums,numsSize,res,start+1,end,returnSize);

		temp=nums[i];   
        nums[i]=nums[start];
        nums[start]=temp;
	}
}

int returnN(int numSize)
{
	int sum=1;
	while(numSize>=1)
	{
		sum=numSize*sum;
		(numSize)--;
	}
	return sum;
}

int** permute(int* nums, int numsSize, int *returnSize) {
		int i=0;
		int N=returnN(numsSize);
        int **res=(int**)malloc((N)*sizeof(int*));
        perm(nums,numsSize,res,0,numsSize-1,returnSize);
        return res;
}

int main()
{
	int nums[5]={1,2,3,4,5};
	int size=0;
	int** res=permute(nums,5,&size);
	int i=0,j=0;
	int numsSize=5;
	int returnSize1=returnN(numsSize);
	for(i=0;i<returnSize1;i++)
	{
		for(j=0;j<numsSize;j++)	
		{
			printf(" %d ",res[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<returnSize1;i++)
	{
		free(res[i]);
	}
	free(res);
	
	printf("count is %d",count);
}

