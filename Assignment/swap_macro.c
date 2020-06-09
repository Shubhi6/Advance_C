/*Title:-WAP to define a macro (t, x, y) that interchanges two arguments of type t
Author:-Shubhi Omar
Date:-5-11-2019
Description
Input:- Read the input from user
Output:- Print the output
Enetr the num1 : 10
Enter the num2 : 20
After swapping:
num1 : 20
num2 : 10
 */

#include<stdio.h>
#include<stdlib.h>

//Decfine the macro of swap
#define SWAP(t, x, y)  	\
{			\
    t temp = x; 	\
    x = y; 		\
    y = temp; 		\
}
int main()
{
    char ch;
    do
    {
	//Declare the varibales
	int choice;

	//Menu for option
	printf("1.char\n2.short int\n3.int\n4.float\n5.double\n");

	//User choice
	printf("Enter the choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
	    case 1:
		{
		    //Declare the variable
		    char ch1, ch2;
		    //input from user
		    printf("Enter the  ch1 and ch2\n");
		    scanf(" %c %c", &ch1, &ch2);
		    getchar();
		    //Print the input character before swap
		    printf("Before swap ch1 = %c, ch2 = %c\n", ch1, ch2);
		    SWAP(char, ch1, ch2)
			//Print the output character after swap
			printf("After swap ch1 = %c, ch2 = %c\n", ch1, ch2);
		    break;
		}
	    case 2:
		{
		    //Declare the variable
		    short int num1, num2;
		    //Input from user
		    printf("Enter the num1 and num2\n");
		    scanf("%hd %hd", &num1, &num2);
		    //Print the input numbers before swap
		    printf("Before swap num1 = %hd, num2 = %hd\n", num1, num2);
		    SWAP(short int, num1, num2)
			//Print the output numbers after swap
			printf("After swap num1 = %hd, num2 = %hd\n", num1, num2);
		    break;
		}
	    case 3:
		{
		    //Declare the variable
		    int num1, num2;
		    //Input from user
		    printf("Enter the num1 and num2\n");
		    scanf("%d %d", &num1, &num2);
		    //Print the input numbders before swap
		    printf("Before swap num1 = %d, num2 = %d\n", num1, num2);
		    SWAP(int, num1, num2)
			//Print the output numbers after swap
			printf("After swap num1 = %d, num2 = %d\n", num1, num2);
		    break;
		}
	    case 4:
		{
		    //Declare the variable
		    float num1, num2;
		    //Input from user
		    printf("Enter the num1 and num2\n");
		    scanf("%f %f", &num1, &num2);
		    //Print the input numbers before swap
		    printf("Before swap num1 = %f, num2 = %f\n", num1, num2);
		    SWAP(float, num1, num2)
			//Print the output numbers after swap
			printf("After swap num1 = %f, num2 = %f\n", num1, num2);
		    break;
		}
	    case 5:
		{
		    //Declare the varible
		    double num1, num2;
		    //Input from user
		    printf("Enter the num1 and num2\n");
		    scanf("%lf %lf", &num1, &num2);
		    //Print the input numbers before swap
		    printf("Before swap num1 = %lf, num2 = %lf\n", num1, num2);
		    SWAP(double, num1, num2)
			//Print the output after swap
			printf("After swap num1 = %lf, num2 = %lf\n", num1, num2);
		    break;
		}
	    default:
		//Print the error massage
		printf("Enter the valid choice\n");
		break;
	}
	//Prompt for continue option
	printf("Do you want to continue(y/n)\n");
	scanf("\n%c", &ch);
	getchar();
    }
    while(ch == 'Y' || ch == 'y');
    return 0;
}



