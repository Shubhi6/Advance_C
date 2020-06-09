/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */
#include<stdio.h>
//fun decalrations
int endian(int n);
int main()
{
        //declaration of variable
	unsigned int num;
        char *ptr;
        //taking input from user
	printf("Enter the number:");
	scanf("%d",&num);
        //checking for condition
        if (endian(num) == *(char *)&num)
        {
          printf("LITTLE ENDIAN\n");
        }
        else
        {
         printf("BIG ENDIAN\n");
         }
	return 0;
}
//fun definition
int endian(int n)
{
 char *ptr;
 //checking char
 ptr = (char *)&n;
 return *ptr;
}
