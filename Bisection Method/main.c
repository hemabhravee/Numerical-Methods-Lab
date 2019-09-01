/*
Title - Bisection Method
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 1
*/
#include <stdio.h>
#include <stdlib.h>
#define TOL 10e-8

float f (float x)
{
    return (x*x - 50);
}

void bisection(float a, float b)
{
    if(f(a)*f(b)>0)
    {
        printf("Incorrect values of a and b");
        exit(0);
    }
    else
    {
        float c=(a+b)/2;
        if(f(c)<TOL)
        {
            printf("Approximate root = %f",c);
            exit(0);
        }
        if(f(c)==0)
        {
            printf("root = %f",c);
            exit(0);
        }
        else if(f(a)*f(c)<0)
        {
            bisection(a,c);
        }
        else 
        {
            bisection(c,b);
        }
        
    }
}
    
    int main()
    {
        float a=1, b=13;
        bisection(a,b);  
    }
