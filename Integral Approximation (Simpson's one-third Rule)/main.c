/*
Title - Integral Approximation (Simpson's One-Third Rule)
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 7
*/
#include <stdio.h>
#include <math.h>

float func(float x)
{
    return(1/(1+pow(x,2)));
}

float simpsonsOneThird (int n, int a, int b)
{
    float T=func(a)+func(b);
    float h=(b-a)/n;
	//defining intervals
    int j;
    for(j=1; j<n ;j++)
    {
        if(j%2!=0)   //odd
        T+=4*func(a + j*h);
        else 	     //even
        T+=2*func(a + j*h);
    }
    return(T*h/3);
}

int main() {
    int n=10;
	// number of intervals
    float a=0, b=1;
	//defining limits
    float integral = simpsonsOneThird(n,a,b);
    float answer = 4*integral;
    printf("The answer is %f \n loops %d",answer,j);
	return 0;
}
