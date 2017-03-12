#include <stdio.h>
#include <math.h>
void firesecond();
static double a[4],a1[4],b[5],b1[5],c[5],K[5],K1[5],A,kw1,JD,z=0.0,q=0.0,n=0.0,kw=7.296,P=70;
void fireone()
{
	int i,j,k=1,m=0;
    a[0]=25.5243,a[1]=33.1277,a[2]=33.0757,a[3]=9.3395;
    K[0]=3.293E-1,K[1]=5.354E-2,K[2]=2.472E-2,K[3]=5.489E-3,K[4]=5.073E-3;
    for(i=0;i<5;i++)
		c[i]=0;
    A=(kw*(a[0]+a[1]/2-a[2])+a[2])/(2*(kw-1));
	b[0]=-A+sqrt(A*A+a[0]*(a[2]-a[0])/(kw-1));   
	b[1]=a[0]-b[0];   
	b[2]=a[2]-a[0]-b[0];   
	b[3]=a[1]/2-b[2];   
	b[4]=a[3]/2;
	for(j=0;j<5;j++)      
		printf("%0.4f    ",b[j]);
	printf("\n");   
	for(j=0;j<5;j++)     
		printf("%0.4f    ",c[j]);   
	printf("\n"); 
	
	firesecond();      
}

void firesecond()
{
	int i,j;
	q=0;
	for(i=0;i<5;i++)   
		q=q+b[i]+c[i];
	printf(" this is the q %0.4f \n\n",q);
	c[0]=sqrt(K[2]*b[3]/(P/q));
	c[1]=K[1]*b[2]/sqrt(b[3]*P/q);
	c[2]=(K[3]*b[2]*sqrt(b[4]))/(b[3]*sqrt(P/q));
	c[3]=K[4]*b[2]/(b[3]*P/q);
	c[4]=((K[0]*b[0])*(K[0]*b[0]))/(b[1]*b[1]*P/q);
	
	//faults
	a1[0]=a[0];
	a1[1]=a[1]-c[0]-c[1];
	a1[2]=a[2]-c[1]-c[2]-c[3]-2*c[4];	
	a1[3]=a[3]-c[2];
	A=(kw*(a1[0]+a1[1]/2-a1[2])+a1[2])/(2*(kw-1));
	b1[0]=-A+sqrt(A*A+a1[0]*(a1[2]-a1[0])/(kw-1));   
	b1[1]=a1[0]-b1[0];   
	b1[2]=a1[2]-a1[0]-b1[0];   
	b1[3]=a1[1]/2-b1[2];   
	b1[4]=a1[3]/2;
	
	for(j=0;j<5;j++)      
		printf("%0.4f    ",b1[j]);
	printf("\n");   
	for(j=0;j<5;j++)     
		printf("%0.4f    ",c[j]);  
	printf("\n\n\n");
	if((fabs(b1[0]-b[0]))>0.0001||(fabs(b1[1]-b[1]))>0.0001||(fabs(b1[2]-b[2]))>0.0001||(fabs(b1[3]-b[3]))>0.0001||(fabs(b1[4]-b[4]))>0.0001)
	{
		b[0]=b1[0];
		b[1]=b1[1];
		b[2]=b1[2];
		b[3]=b1[3];
		b[4]=b1[4];
		firesecond();
	}
}






