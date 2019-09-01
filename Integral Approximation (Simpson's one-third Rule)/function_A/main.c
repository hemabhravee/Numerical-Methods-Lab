#include <stdio.h>
#include <math.h>
#define TOL 10e-5

float func(float x)
{
    return(1/(1+pow(x,2)));
}

int main() {
    int n=2, j; double error, integral, ans;
    float a=0, b=1;
    do
    {
        
        float h=(b-a)/n,T=func(a)+func(b);
        for(j=1; j<n ;j++)
        {
            if(j%2!=0)
            T+=4*func(a + j*h);
            else
            T+=2*func(a + j*h);
        }
        integral=T*h/3;
        ans = integral;
        error = ans - M_PI/4;
        n++;
        printf("\n %lf",fabs(error));
    }     
    while(fabs(error) > TOL/2);
    
    printf("The answer is %lf\n",ans);
    printf("%lf", fabs(ans - atan(1)));
}
