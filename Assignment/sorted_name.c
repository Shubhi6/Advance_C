/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */
#include<stdio.h>
#include<stdlib.h>
#define maxlen 32
#define maxname 256

//fun declaration
void swap(void *aptr, void *bptr,int count);
void sort_alphabet(char *array[],int count);
int my_strcmp(char *s1,char *s2);

int main()
{       
        //declaration of varible
	int count, length, i,j;
	char choice,option;
 

	do
	{       //take info from user
		printf("Enter the count of person:\n");
		scanf("%d",&count);
                
                //condition of limit 
		if ((count <= 0) || (count > maxname))
		{
			printf("Error!size is out of range.");
                        return 1;
		}
                //allocation of memory
		char**ptr =( char**) malloc(sizeof(char*) *count);
                //condition for checking pointer
		if ( ptr == NULL )
		{
			printf("Error!!");
		}

		for(i=0; i<count ;i++)
		{
			ptr[i] = (char*)malloc (sizeof(char) * (maxlen+1));
			if (ptr[i] == NULL)
			{
				printf("Error!!");
			}
		}


		printf("person names:\n");
		for(i=0; i<count;i++)
		{
			scanf("%s",ptr[i]);

			length = (sizeof(ptr[i]) -1);
			if (length > maxlen)
			{
				printf("plesae enter the name of max length of 32");
			}
		}
		printf("After sorting:\n");
		sort_alphabet(ptr,count);
		for(i =0; i<count;i++)
		{
			printf("%s\n",ptr[i]);
		}
             		free(ptr);
	//	ptr == NULL;
		//printf("\n");
		printf("continue(y/n):");
		scanf("\n%c",&option);
		if(option == 'y')
		{

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
void sort_alphabet(char *array[],int count)
{
        //declaration of varible
	int i,j;
        //for loop for whole of the sequence
	for(i =0;i<count;i++)
	{       
                //for loop for iteration
		for(j=0;j<(count -i -1);j++)
		{         
                        //fun call for comparison
			if ((my_strcmp( *(array+j) , *(array +j +1)) > 0))
			{       
                                //fun call for swapping
				swap(*(array+j),*(array + j +1), maxlen);
			}
		}
	}
}

//fun definition
void swap(void *aptr, void *bptr,int count)
{       
        //declaration of varible
	int i;
	char temp;
        
        //loop for swapping
	for (i=0;i<count;i++)
	{
		temp = *(char*)aptr;
		*(char *)aptr++ = *(char *)bptr;
		*(char *)bptr++ = temp;

	}
}

//fun definition
int my_strcmp( char *s1,char *s2)
{
return( *s1 > (*s2)? 1: -1) ;
}
