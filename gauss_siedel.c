 #include<stdio.h>
#include<math.h>
#define ESP 0.001
#define X1(x2,x3,x4) ((-2 - x2 + x3 - x4)/4)
#define X2(x1,x3,x4) ((-1 - x1 + x3 + x4)/4)
#define X3(x1,x2,x4) ((x1 + x2 - x4)/5)
#define X4(x1,x2,x3) ((1 - x1 + x2 - x3)/3)


void main()
{
  double y1,y2,y3,y4,m,n,p,o;

  //initial guess
  double x1=2,x2=2,x3=2,x4=2;

  int j=0;


  printf("\n%f\t%f\t%f\t%f",x1,x2,x3,x4);
  do
  {
   m=x1;
   x1=X1(x2,x3,x4);
   n=x2;
   x2=X2(x1,x3,x4);
   o=x3;
   x3=X3(x1,x2,x4);
   p=x4;
   x4=X4(x1,x2,x3);
   printf("\n%f\t%f\t%f\t%f",x1,x2,x3,x4);
     printf("\n\nx1 = %lf",x1);
     printf("\n\nx2 = %lf",x2);
     printf("\n\nx3 = %lf",x3);
     printf("\n\nx4 = %lf",x4);
    j++;
  }while(fabs(m-x1)>ESP && fabs(n-x2)>ESP && fabs(o-x3)>ESP && fabs(p-x4)>ESP );

  printf("\n \nIterations : %d",j);
}
