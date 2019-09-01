/*
Title - Newton Raphson vs Secant
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TOL 10e-5

double func1 (double x)
{
	return ( pow(x,3) - 2*pow(x,2) - 5);
}

double derfunc1 (double x)
{
    return ( 3*pow(x,2) - 4*x);
}

double func2 (double x)
{
	return ( pow(x,3) + 4.001*pow(x,2) + 4.002*x + 1.101);
}

double derfunc2 (double x)
{
    return ( 3*pow(x,2) + 8.002*x + 4.002);
}

double func3 (double x)
{
	return ( pow(x,5) - pow(x,4) + 2*pow(x,3) + x - 4);
}

double derfunc3 (double x)
{
    return ( 5*pow(x,4) - 4*pow(x,3) + 6*pow(x,2) - 6*x + 1);
}



double newt(double a, double (*f)(double), double (*g)(double))
{
	double b;
	int i=0;
	do{
		i++;
        b = a - (f(a)/g(a));
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

double secant( double a, double b, double (*f)(double), double (*g)(double))
{
	double c;
	int i=0;
	do{
		i++;
        c = a - (f(a)/g(a));
	    if(f(c)==0)
	    {
	        printf("\nAfter %d iterations, Root = %lf",i,c);
	        return 0;
	    }
	    printf("\nAfter %d iterations, Value = %lf",i,c);
	    a=b;
		b=c;	    
	}while(f(c)>TOL);
    printf("\n\nRoot as given by Secant : %lf\nNumber of iterations : %d\n\n",c,i);
}

int main()
{
    printf("Enter initial guess \n");
    double a,b;
    scanf("%lf",&a);
    printf("Enter 2nd guess (for secant method) \n");
    scanf("%lf",&b);

    newt(a, func1, derfunc1);
    secant(a, b, func1, derfunc1);
    newt(a, func2, derfunc2);
    secant(a, b, func2, derfunc2);
    newt(a, func3, derfunc3);
    secant(a, b, func3, derfunc3);

}
