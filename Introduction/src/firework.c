#include <stdio.h>
#include <math.h>

void fires(double nC_0,double nH_0,double nO_0,double nN_0,double Kw)
{
	double A=((nC_0+(nH_0 / 2) -nO_0)*Kw + nO_0) / (2*(Kw-1));
	double nCO2_1 = -A + sqrt(A*A + nC_0*(nO_0 - nC_0)/(Kw-1));
	double nCO_1 = nC_0 -nCO2_1;
	double nH2O_1 =nO_0 -nC_0 -nCO2_1;
	double nH2_1 = nH_0/2 -nH2O_1;
	double nN2_1=nN_0 /2;
	printf("A is %.4lf\nnCO2_1 is %.4lf\nnCO_1 is %.4lf\nnH2O_1 is %.4lf\nnH2_1 is %.4lf\nnN2_1 is %.4lf\n ",A,nCO2_1,nCO_1,nH2O_1,nH2_1,nN2_1);
	//check
	double temp1 =nCO2_1 + nCO_1;
	double temp2 =2*nH2O_1 + 2*nH2_1;
	double temp3 =2*nCO2_1 + nCO_1 + nH2O_1;
	double temp4 =2*nN2_1;
	printf("checking *****************\n");
	printf("nC_0 is %.4lf\nnH_0 is %.4lf\nnO_0 is %.4lf\nnN_0 is %.4lf\n",temp1,temp2,temp3,temp4);
	
	//check Kw
	printf("checking Kw************\n");
	double temp5 = (nCO_1 * nH2O_1)/(nCO2_1*nH2_1);
	printf("Kw is %.4lf\n",Kw);
}
