/*
Title - Lagrange Polynomial(2)
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 5
*/
#include<stdio.h>

float lagrange(float x[],float y[], float a, int n)
{
	float num,den,func=0;
    int i,j;
    for(i=0; i<n; i++)
    {
        num=1;
        den=1;
        for(j=0; j<n; j++)
        {
            if(j!=i)
            {
                num*=(a-x[j]);
                den*=(x[i]-x[j]);
            }
        }
        func+=((num/den)*y[i]);
    }
    printf("\n\n The respective value of the variable y is: %f",func);
}

int main()
{
    
    int d=1;
    //define size 
    int n=7;
    //creating given function
    float x[7]={1.7, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3};
    float y[7]={5.474, 6.050, 6.686, 7.8166, 9.025, 9.974};
    
    lagrange(x,y,1.85,7);
    lagrange(x,y,2.25,7);

        
   
}
