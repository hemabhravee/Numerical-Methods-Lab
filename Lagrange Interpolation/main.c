/*
Title - Lagrange Polynomial(1)
Author - Hemabh Ravee (IMH/10042/17)
Lab - Numerical Methods Lab - 5
*/
#include<stdio.h>
int main()
{
    float num,den,func=0;
    int d=1;
    //define size 
    int n=5;
    //creating given function
    float x[5]={5,7,11,13,17};
    float y[5]={150, 392,1452, 2366, 5202};
    
    {
        //Enter the value of the x to find the respective value of y
        float a=10;
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
}
