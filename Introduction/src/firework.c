#include <stdio.h>
#include <math.h>
#define P 70
static double k1,k2,k3,k4,k5,k6;
static int times=1;
int compute_it(double nC,double nH,double nO,double nN,double Kw,double *nCO2_cp,double *nCO_cp,double *nH2O_cp,double *nH2_cp,double *nN2_cp);
void second(double *nCO2_1,double *nCO_1,double *nH2O_1,double *nH2_1,double *nN2_1,double nC_0,double nH_0,double nO_0,double nN_0,double Kw);

void fires(double nC_0,double nH_0,double nO_0,double nN_0,double Kw)
{
	double A=((nC_0+(nH_0 / 2) -nO_0)*Kw + nO_0) / (2*(Kw-1));
	double nCO2_1 = -A + sqrt(A*A + nC_0*(nO_0 - nC_0)/(Kw-1));
	double nCO_1 = nC_0 -nCO2_1;
	double nH2O_1 =nO_0 -nC_0 -nCO2_1;
	double nH2_1 = nH_0/2 -nH2O_1;
	double nN2_1=nN_0 /2;
	printf("this is %d time\n",times++);
	printf("nCO2 is %.4lf\nnCO  is %.4lf\nnH2O is %.4lf\nnH2  is %.4lf\nnN2  is %.4lf\n",nCO2_1,nCO_1,nH2O_1,nH2_1,nN2_1);
	printf("nH is %.4lf\nnOH is %.4lf\nnNO is %.4lf\nnO is %.4lf\nnO2 is %.4lf\n\n\n\n",0.0,0.0,0.0,0.0,0.0);
	//check
	/*double temp1 =nCO2_1 + nCO_1;
	double temp2 =2*nH2O_1 + 2*nH2_1;
	double temp3 =2*nCO2_1 + nCO_1 + nH2O_1;
	double temp4 =2*nN2_1;
	printf("%d checking *****************\n",times);
	times++;
	printf("nC_0 is %.4lf\nnH_0 is %.4lf\nnO_0 is %.4lf\nnN_0 is %.4lf\n",temp1,temp2,temp3,temp4);
	
	//check Kw
	printf("checking Kw************\n");
	double temp5 = (nCO_1 * nH2O_1)/(nCO2_1*nH2_1);
	printf("Kw is %.4lf\n\n\n\n",Kw);*/
	
	//call up function second
	k1=0.3293;
	k2=0.05354;
	k3=0.02472;
	k4=0.005489;
	k6=0.005073;
	
	double *temp_1=&nCO2_1;
	double *temp_2=&nCO_1;
	double *temp_3=&nH2O_1;	
	double *temp_4=&nH2_1;
	double *temp_5=&nN2_1;			
	second(temp_1,temp_2,temp_3,temp_4,temp_5,nC_0,nH_0,nO_0,nN_0,Kw);
}

void second(double *nCO2_1,double *nCO_1,double *nH2O_1,double *nH2_1,double *nN2_1,double nC_0,double nH_0,double nO_0,double nN_0,double Kw)
{
	double n_1=(*nCO2_1) + (*nCO_1) + (*nH2O_1) + (*nH2_1)+ (*nN2_1);
	double nH2_2 = sqrt(k3*(*nH2_1)/(P/n_1));
	double nOH_2 = k2*(*nH2O_1)/(sqrt((*nH2_1)*P/(n_1)));
	double nNO_2 = k4*(*nH2O_1)*(sqrt(*nN2_1))/((*nH2_1)*sqrt(P/(n_1)));
	double nO_2 = k6*(*nH2O_1)/((*nH2_1)*P/(n_1));
	double nO2_2 = (k1*(*nCO2_1))*(k1*(*nCO2_1))/((*nCO_1)*(*nCO_1)*P/(n_1));
	printf("this is %d time\n",times);
	times++;
	printf("nH is %.4lf\nnOH is %.4lf\nnNO is %.4lf\nnO is %.4lf\nnO2 is %.4lf\n",nH2_2,nOH_2,nNO_2,nO_2,nO2_2);
	double n0C_2=nC_0;
	double n0H_2 = nH_0 -nH2_2 - nOH_2;
	double n0O_2 = nO_0 - nOH_2 - nNO_2;
	double n0N_2 = nN_0 - nNO_2;
	int continue1=compute_it(n0C_2,n0H_2,n0O_2,n0N_2,Kw,nCO2_1,nCO_1,nH2O_1,nH2_1,nN2_1);
	
	//continue???
	if(continue1 ==1)
	{
		second(nCO2_1,nCO_1,nH2O_1,nH2_1,nN2_1,nC_0,nH_0,nO_0,nN_0,Kw);
	}
}

int compute_it(double nC,double nH,double nO,double nN,double Kw,double *nCO2_cp,double *nCO_cp,double *nH2O_cp,double *nH2_cp,double *nN2_cp)
{
	double A=((nC+(nH / 2) -nO)*Kw + nO) / (2*(Kw-1));
	double nCO2_1 = -A + sqrt(A*A + nC*(nO - nC)/(Kw-1));
	double nCO_1 = nC -nCO2_1;
	double nH2O_1 =nO -nC -nCO2_1;
	double nH2_1 = nH/2 -nH2O_1;
	double nN2_1=nN /2;
	printf("nCO2 is %.4lf\nnCO is %.4lf\nnH2O is %.4lf\nnH2 is %.4lf\nnN2 is %.4lf\n\n\n\n",nCO2_1,nCO_1,nH2O_1,nH2_1,nN2_1);
	//checking*********
	/*double temp1 =nCO2_1 + nCO_1;
	double temp2 =2*nH2O_1 + 2*nH2_1;
	double temp3 =2*nCO2_1 + nCO_1 + nH2O_1;
	double temp4 =2*nN2_1;
	printf("%d checking *****************\n",times);
	times++;
	printf("nC_0 is %.4lf\nnH_0 is %.4lf\nnO_0 is %.4lf\nnN_0 is %.4lf\n",temp1,temp2,temp3,temp4);
	
	//check Kw
	printf("checking Kw************\n");
	double temp5 = (nCO_1 * nH2O_1)/(nCO2_1*nH2_1);
	printf("Kw is %.4lf\n",Kw);*/
	
	//continue??
	if((fabs(*nCO2_cp - nCO2_1) > 0.0001) || (fabs(*nCO_cp - nCO_1) > 0.0001) || (fabs(*nH2O_cp - nH2O_1) > 0.0001) ||(fabs(*nH2_cp - nH2_1) > 0.0001)||(fabs(*nN2_cp - nN2_1) > 0.0001))
	{
		*nCO2_cp=nCO2_1;
		*nCO_cp=nCO_1;
		*nH2O_cp = nH2O_1;
		*nH2_cp = nH2_1;
		*nN2_cp = nN2_1;
		return 1;
	}
	else 
	{
		return 0;
	}
}











