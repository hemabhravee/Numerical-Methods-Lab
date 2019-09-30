/*
Title - Newton Polynomial(2)
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 5
*/
#include<stdio.h>
#include<math.h>

float newton(float x[],float y[], float xTest[], int n,int m)
{
	float D[n][n];
	int i,j,k;
	
	//defining first column of D to be y or f(x)
	for(i=0;i<n;i++)
		D[i][0] = y[i];
		
	//defining the rest of the array D
	//note that we start with both i & j = 1
	for(i=1;i<n;i++)
	{
		for(j=1;j<=i;j++)
		{
			D[i][j] =( D[i][j-1]- D[i-1][j-1] )/( x[i] - x[i-j] );
		}
	}
	
	//Now the diagonal of D holds the values of the coefficient 
	for(i=0;i<n;i++)
		printf("\n%dth coefficient is : %f",i,D[i][i]);
		
	float sum, prod;
	
	//Looping testing points
	for(i=0;i<m;i++) 
	{
		sum=D[0][0];		
		for(j=1;j<i;j++)
		{
			prod = 1;
			for(k=0;k<j;k++)
			{
				prod*=(xTest[i]-x[k]);
			}
			sum+=D[j][j]*prod;
			
		}
		printf("\nError in %dth term, i.e. in f(%f) is : %f",i+1,xTest[i],sum-atan(xTest[i]));
	}
}

int main()
{
	//defining array size
    int n = 11;
    int m = 33;
    
    float xTrain[n];
    float y[n];
        
    float a=0;
    float b=6;
    int i;
    
    for(i=0;i<n;i++)
    {
    	xTrain[i] = a + i*(b-a)/n;
    	y[i] = atan(xTrain[i]);
    	//printf("%f\t%f\n",xTrain[i],y[i]);
	}
	
	float xTest[m];
	
	float c = 0;
	float d = 8;
	
	for(i=0;i<m;i++)
	{
		xTest[i] = c + i*(d-c)/m;
	}
	
    
    float x1 = 1;
    newton(xTrain,y,xTest,n,m);
  
}
