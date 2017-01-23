#include "zhimi.h"
#include <stdio.h>
//this is used for computing optimal strategy of ZHIMI arena.
double compute(double HP1,double attack1,double HP2,double attack2)
{
	double k=(HP1-HP2)/(attack1-attack2);
	double b=(HP1) - (k*attack1);
	return (-1)*(b)/(2*k);
}

int zhimi_isOptimal(double* result,double HP1,double attack1,double HP2,double attack2)
{
	double k=(HP1-HP2)/(attack1-attack2);
	double b=(HP1) - (k*attack1);
	double hit_times1;
	double hit_times2;
	*result = (-1)*(b)/(2*k);
	double i=attack1;
	while(i<attack2)
	{
		hit_times1=(k*i + b)/ (*result);		
		hit_times2=(k*(*result) + b)/i;
		printf("difference is %.3lf,hit_times1 is %.3lf and his attack1 is %.3lf as well as his HP %.3lf\n",hit_times2-hit_times1,hit_times1,i,i*k+b);
		if(hit_times2 < hit_times1)
		{
			return 0;
		}
		i+=5;
	}
	return 1;
}
