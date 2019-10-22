#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define TOL 10e-3

float f1(int a,int b,int c){
    return ((-a + b - c -2)/4);
}

float f2(int a,int b,int c){
    return ((-a + b + c -1)/4);
}

float f3(int a,int b,int c){
    return ((a + b - c)/5);
}

float f4(int a,int b,int c){
    return ((-a + b - c + 1)/3);
}

int main()
{
	float x[4] = {0,0,0,0};
	float y[4];
    int iter = 20,i = 0;


    do{
        y[0] = f1(x[1],x[2],x[3]);
        y[1] = f2(x[0],x[2],x[3]);
        y[2] = f3(x[0],x[1],x[3]);
        y[3] = f4(x[0],x[1],x[2]);
        i++;
        int j;
        for(j=0;j<4;j++){
            x[j] = y[j];
        }

        printf("\nValues after %dth iteration : %f %f %f %f",i,y[0],y[1],y[2],y[3]);
    }while(i<iter);
}
