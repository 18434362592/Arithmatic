#include <stdio.h>

int calculate(int* premutiply,int n)
{
	*premutiply=(*premutiply)*n;
	return *premutiply;
}

int main()
{
	int sum=0;
	int N=5;
	int n=N;
	int pre_mutiply=1;
	while(n>=1)
	{
		sum=sum+calculate(&pre_mutiply,n);
		n--;
	}
	printf("%d",sum);
}
