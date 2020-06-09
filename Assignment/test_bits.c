#include<stdio.h>
int main()
{
float num1=1.2;
double num2=1.3;
int *n= (int*)&num1;
long int *m=(long int *)&num2;
printf("%d\n",*n);
printf("%ld\n",*m);
}
