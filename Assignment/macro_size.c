/*
Title-:WAP to generate fibbonacci series less then the given no.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a no.
             Output-:Print fibbonacci series.

*/
#include<stdio.h>
//macro declaration
#define MY_SIZE(Var) ((char *) (&Var + 1 ) - (char *)(&Var))

int main()
{       
        //declaration of variable
	int num;
	char ch;
	float float_num;
	double double_num;
	unsigned int value;
	long int num1;
        
        //for printing the size of data type
	printf("Size of int\t\t = %ld bytes\n",MY_SIZE(num));
	printf("Size of char\t\t = %ld bytes\n",MY_SIZE(ch));
	printf("Size of float\t\t = %ld bytes\n",MY_SIZE(float_num));
	printf("Size of double\t\t = %ld bytes\n",MY_SIZE(double_num));
	printf("Size of unsigned int\t = %ld bytes\n",MY_SIZE(value));
	printf("Size of long int\t = %ld bytes\n",MY_SIZE(num1));

        return 0;


}
