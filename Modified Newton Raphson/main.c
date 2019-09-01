/*
Title - Newton Raphson vs Secant
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TOL 10e-5

double func (double x)
{
	return ( exp(x) - x - 1);
}

double derfunc (double x)
{
    return ( exp(x) - 1);
}

double ddfunc (double x)
{
	return ( exp(x) );
}

double newt(double a)
{
	double b;
	int i=0;
	do{
		i++;
        b = a - (func(a)*derfunc(a))/(derfunc(a)*derfunc(a) - func(a)*ddfunc(a));
	    if(func(b)==0)
	    {
	        printf("\nAfter %d iterations, Root = %lf",i,b);
	        return 0;
	    }
	    printf("\nAfter %d iterations, Value = %lf",i,b);
	    a=b;	    
	}while(func(b)>TOL);
    printf("\n\nRoot as given by Modified Newton Raphson Method : %lf\nNumber of iterations : %d\n\n",b,i);	

}

int main()
{
    printf("Enter initial guess \n");
    double a,b;
    scanf("%lf",&a);

    newt(a);

}
