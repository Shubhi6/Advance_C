/*
Title        : WAP to print int of a float number
Author Name  : Shubhi omar
Date         : 11/11/2019
Description  : Enter a float number
               1.2
               0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 

*/


#include<stdio.h>

union demoted
{
    float var;
    struct
    {
	unsigned mantissa : 23;
	unsigned exp : 8;
	unsigned sign : 1;
    }demoted_int;
};

int main()
{
    //Declare the char variable
    char ch;


    do
    {
	//Decalring the local variables


	float flt_no;
	int i,temp = 0;
	union demoted ints;
	unsigned int mask = 0x800000;

	//User want to enter the number
	printf("Enter a float number\n");
	scanf("%f",&flt_no);

	//Assign float variable 
	ints.var = flt_no;

	//Assign float variable as float variable
	temp = (ints.demoted_int.exp) - 127;    

	//Getting the number of MSB in mantissa
	int new_mantissa = ((ints.demoted_int.mantissa) >> (23 - temp)) | (1 << temp); 
        
        if(ints.demoted_int.sign == 1)
        {
         new_mantissa = new_mantissa *(-1);
        }
        else if(new_mantissa < 1)
        {
         new_mantissa = 0;
        }
	//Obtaining new mantissa
	for(i = 22; i >= 0; i--)
	{
	    new_mantissa & (mask >>= 1) ? printf("1 ") : printf("0 ");
	}

	printf("\n");
        printf("Demoted int =%d\n",new_mantissa);
	printf("Do you want to continue? (y/n)");
	getchar();

	scanf("%c",&ch);
    }while(ch == 'y');
}

