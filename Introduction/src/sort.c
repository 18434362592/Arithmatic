#include <stdlib.h>
#include "sort.h"
#include "user-define.h"
void exch(int *former,int *later)
{
	int temp=*former;
	*former=*later;
	*later=temp;
}

void insertion_sort(int *nums,int start,int end)
{
	int i,j;
	for(i=start+1;i<end;i++)
	{
		j=i-1;
		int key=nums[i];
		while(j>=start&&key<nums[j])			//the core is that these elements of start to i-1 of array compare with i
		{
			//the elements whose index is j move back one position
			//and it's index add one
			nums[j+1]=nums[j];
			j--;	//compare former one
		}
		nums[j+1]=key;
	}
}

void merge_sort(int* nums,int start,int end)
{
	if(end==start)
	{
		return;
	}
	int lower=start;
	int upper=end;
	int middle=(lower+upper)/2;
	merge_sort(nums,lower,middle);
	merge_sort(nums,middle+1,upper);
	//Combine [lower,middle] and [middle+1.upper] into [lower,upper]
	//the result is sorted between lower and upper
	int* former=malloc((middle - lower +1)*sizeof(int));
	int* later=malloc((upper-middle)*sizeof(int));
	//inital former and later
	int i,j;
	for(i=lower,j=0;i<=middle;i++)
	{
		former[j++]=nums[i];
	}
	for(i=middle+1,j=0;i<=upper;i++)
	{
		later[j++]=nums[i];
	}
	//now combine the solutions to the subproblems into the solutions
	int f=0,l=0;		//f : former index  l : later index
	int fs=middle-lower +1;
	int ls=upper-middle;
	int k=lower;
	while(f<fs&& l<ls)
	{
		if(former[f]<later[l])
		{
			nums[k++]=former[f++];
		}
		else
		{
			nums[k++]=later[l++];
		}
	}
	//check which array over firstly
	if(l<ls)
	{
		for(;l<ls;l++)
		{
			nums[k++]=later[l];
		}
	}
	else
	{
		for(;f<fs;f++)
		{
			nums[k++]=former[f];
		}
	}
	
	//release the memory of the Former and the Later
	free(former);
	free(later);
}

int test_sort(int *nums,int size)
{
	int i=1;
	for(;i<size;i++)
	{
		if(nums[i]<nums[i-1])
				return 0;
	}
	return 1;
}







