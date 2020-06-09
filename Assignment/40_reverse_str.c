/*
   Title-:WAP for the prime no upto given limit.
   Author-:Shubhi omar
   Date-:25/09/2019
   Description-:Input-: Read a limit no from user.
   Output-:

 */






#include<stdio.h>
#include<string.h>
//fun declaration
void recur_reverse(char*,int start,int end);
void reverse(char*);

int main()
{       
	//declaration of variable
	char str[255],option;
	int choice;
	//for taking input
	do
	{
		printf("Enter the word:\n");
		//for getting input
		scanf("%[^\n]",str);
		printf("Enter the choice:\n1.Non-recursive\n2.Recursive\n ");
		scanf("%d",&choice);

		//for choice
		switch(choice)
		{
			case 1:


				//fun calling
				reverse(str);
				//printing the string
				printf("revrse string is:%s\n",str);
				break;

			case 2:
				//   printf("Enter the word:\n");
				//  gets(str);
				printf("reverse string is:\n");
				//fun calling
				recur_reverse(str,0,(strlen(str) -1));
				printf("%s\n",str);
				break;

			default:
				printf("Invalid choice\n");
		}
		printf("\ncontinue(y/n):");
		scanf("\n%c",&option);
		if(option == 'y')
		{
			getchar();
			continue;
		}
		else
		{ 
			break;
		}

	} while(1);
	return 0;
}


//fun definition
void reverse(char *p)
{       //declaration of variable
	int i,length;
	char *begin,*end,temp;

	length= (strlen(p) -1);
	//initialization of pointer
	begin =p;
	end=p;
	//for loop till the end
	for(i = 0; i<(length);i++)
	{
		end++;
	}
	//for loop for reversing
	for(i=0;i< (length/2);i++)
	{      
		//swapping concept
		temp= *begin;
		*begin= *end;
		*end=temp;
		begin++;
		end--;
	}

}



//fu definition
void recur_reverse(char *p,int start, int end)
{       
	//declaration of end
	char c;
	// for only one char
	if(start >= end)
	{
		return;
	}
	else
	{
                //for swapping of pointer
		c= *(p+start);
		*(p+start) = *(p+end);
		*(p+end)=c;
	}
        //for recursive calling of fun 
	recur_reverse (p,++start,--end);
}






