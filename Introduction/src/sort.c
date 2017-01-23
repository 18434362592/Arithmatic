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







