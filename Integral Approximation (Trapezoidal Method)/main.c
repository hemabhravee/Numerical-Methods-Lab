/*
Title - Integral Approximation (Trapezoidal Method)
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 7
*/
#include <stdio.h>
#include <math.h>

float func(float x)
{
    return(1/(1+pow(x,2)));
}

float trapezoidal(int n, int a , int b)
{
    float T=func(a)+func(b);
    float h=(b-a)/n;
	//defining intervals
     for(int j=1; j<n ;j++)
    {
        T+=2*func(a + j*h);
    }
    return(T*h/2);
    
int main() {
    int n=10;
	//n is the number of intervals
    float a=0, b=1;
	// a and b are the limits of integral 
    float integral = trapezoidal (n,a,b);
	//we multiply this by 4 to obtain the value of pi
    float ans = 4*integral;
    printf("The answer is %f",ans);
	return 0;
}
