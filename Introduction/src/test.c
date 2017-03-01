#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"
#include "permutations.h"
#include "zhimi.h"
#include "firework.h"
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

/*#define N 1000
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
}*/

int main()
{
	//void fires(double nC_0,double nH_0,double nO_0,double nN_0,double Kw)
	double nC_0=25.5243;
	double nH_0=33.1277;
	double nO_0=33.0757;
	double nN_0=9.3395;
	double Kw=7.296;
	fires( nC_0, nH_0, nO_0, nN_0, Kw);
}

 









