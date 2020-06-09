/*
Title-:WAP to print size of basic data type,
Author-:Shubhi Omar
Date-:26/9/2019
Description-: Input-:
              Output-:size of int=4 
                      size of charcter =1 
                      size of float=4
                      size of double=8

*/


#include<stdio.h>

int main()

{ 
	//Declare variables
	int i;
	char c ;
	float f ;
	double d; 
        
        //size of data type
	printf("size of int=%ld \n",sizeof(int));
	printf("size of charcter =%ld \n",sizeof(char));
	printf("size of float=%ld\n",sizeof(float));
	printf("size of double=%ld\n",sizeof(double));
	printf("size of long double=%ld\n",sizeof(long double));
	printf("size of signed int=%ld \n",sizeof(signed int));
	printf("size of unsigned int =%ld \n",sizeof(unsigned int));
	printf("size of unsigned long long int=%ld\n",sizeof(unsigned long long int));
	printf("size of unsigned long int=%ld\n",sizeof(unsigned long int));
	printf("size of unsigned short int=%ld \n",sizeof(unsigned short int));
	printf("size of short =%ld \n",sizeof(short));
	printf("size of unsigned character=%ld\n",sizeof(unsigned char));

        return 0;
}    



