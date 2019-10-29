#include<stdio.h>
#include <math.h>
#define F(x,y)  -1000*(y - (x + 2)) + 1

double func(double x,double y){
    return ((-1000*(y - (x+2))) + 1);
}
void main()
{
  double y1,y2,x1,a,n,h,l;
  int j;
  //printf("\nEnter the value of range: ");
  //scanf("%lf %lf",&a,&n);
  a = 0; n = 0.01;
  //printf("\nEnter the value of y1: ");
  //scanf("%lf",&y1);
  y1 = 1;
  //printf("\n\nEnter the h: ");
  //scanf("%lf",&h);
  h = 0.0005;
  //printf("\n\n  y1 = %.3lf ",y1);
  for(x1=a,j=2; x1<=n+h; x1+=h,j++)
  {
   y2= y1 + (h * func(x1,y1));
   l = F(x1,y1);
   printf("\n\n  x = %lf => y%d = %lf \t %lf \t %lf",x1,j,y2,y1,l);
   y1=y2;
  }
}

