/*
   Title-:WAP to check whether the entered number is perfect or not.
   Author-:Shubhi Omar
   Date-:25/9/2019
   Description-: Input-:Read a number from the user.
   Output-:Print whether no is perfect or not.
 */


#include<stdio.h>

int main()

{ 
	//Declare variables
	int start_of_day,no_of_day,Result ;

	printf("Please enter the number to find the day:\n");
	scanf("%d" , &no_of_day);
        
        //condition for the no of valid days in the year
	if (no_of_day > 0 && no_of_day < 366)
	{
	printf(" 1.SUNDAY\n 2.MONDAY\n 3.TUESDAY\n 4.WEDNESDAY\n 5.THRUSDAY\n 6.FRIDAY\n 7.SATURDAY\n");
		printf("Enter the start of the day: \n ");
		scanf("%d",&start_of_day);
                if (start_of_day > 7)
                {
                 printf("INVALID START OF DAY\n");
                 }
                else
               {

		Result = (((no_of_day % 7) + (start_of_day - 1)) % 7);
		if (Result == 0)
                {
		  
                     Result = 7;
                // case for switching days
		switch (Result) 
		{ 
			case 1:
				printf("SUNDAY\n");
				break;
			case 2:
				printf("MONDAY\n");
				break;
			case 3:
				printf("TUESDAY\n");
				break;
			case 4:
				printf("WEDNESDAY\n");
				break;
			case 5:
				printf("THRUSDAY\n");
				break;
			case 6:
				printf("FRIDAY\n");
				break;
			case 7:
				printf("SATURDAY\n");
				break;
			
			
		}

	}  
}   
 }
 else
{
 printf("INVALID NO. OF DAYS!\n");

}
           return 0;
}    



