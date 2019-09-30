/*
Title - Newton Raphson (2)
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TOL 10e-4

double func (double x)
{
    return (pow(x,3) - 4*pow(x,2) + 5*x - 2);
}

double derfunc (double x)
{
    return (3*pow(x,2) - 8*x + 5);
}

double ddfunc (double x)
{
	return (6*x - 8);
}

double hx (double x)
{
	return(func(x)/derfunc(x));
}

double dhx (double x)
{
	return( (pow(derfunc(x),2) - ddfunc(x)*func(x) )/( pow(derfunc(x),2) ) );
}


double newt(double a, double (*f)(double), double (*g)(double))
{
	double b;
	int i=0;
	do{
		i++;
	    b = a - f(a)/g(a);
	    if(f(b)==0)
	    {
	        printf("\nAfter %d iterations, Root = %lf",i,b);
	        return 0;
	    }
	    printf("\nAfter %d iterations, Value = %lf",i,b);
	    a=b;	    
	}while(f(b)>TOL);
    printf("\n\nRoot as given by Newton Raphson Method : %lf\nNumber of iterations : %d\n\n",b,i);	

}




int main()
{
    printf("Enter initial guess \n");
    double a = 5;
    //scanf("%lf",&a);
    
    newt(a, func, derfunc);
    newt(a, hx, dhx);
    
    newt(-5, func, derfunc);
    newt(-5, hx, dhx);
   

}
