#include<stdio.h>
int fun()
{
static int num=10;
num=num+10;
printf("num=%d\n",num);
}
 int main()
{
fun();
fun();
fun();
}
