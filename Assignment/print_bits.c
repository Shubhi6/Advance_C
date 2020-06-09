/*
   Title-:WAP to check whether the entered number is perfect or not.
   Author-:Shubhi Omar
   Date-:02/10/2019
   Description-: Input-:Read a number from the user.
   Output-:Print bits of the no and it's compliment.
           Please enter the no to get in binary.79
           binary bits of 79 is : 0000000000000000000000000100111
           two's compliment : -79
           1111111111111111111111111011000

 */



#include<stdio.h>

int main()
{       
        //Declaring variable
	int num, bin, bin_1, two_s, one_s, count;
	printf("Please enter the no to get in binary.");
	scanf("%d",&num);

	printf("Binary bits of %d is : ",num);
        //for integers value i.e.4 byte
	for (count = 31; count > 0; count--)
	{ 
		bin = num >> count;
                //for printing value in binary format
		if(bin & 1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");

        //logic for 2's compliment
	one_s= ~num;
	two_s= one_s + 1;
	printf("Two's compliment : %d\n",two_s);
	for(count=31;count>0;count--)
	{
		bin_1=two_s >> count;
                //for binary format
		if(bin_1 & 1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");

	return 0;
}

