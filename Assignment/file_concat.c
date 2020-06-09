/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */

#include<stdio.h>

int main(int argc,char *argv[])
{       
        //file declaration
	FILE *fptr1,*fptr2,*fptr3;
        //checking condition for argument
	if(argc == 1)
	{
		printf("Please enter other file name also\n");
	}

	else if(argc == 2)
	{       
                //for reading
		fptr1= fopen(argv[1],"r");
	        
                 //checking file's content
         	if(fptr1 == NULL)
		{
			fprintf(stderr,"could not open files\n");
		}
		int ch;
                //copy data till end
		while(ch =fgetc(fptr1) != EOF)
		{
			printf("%c",ch);
		}
		fclose(fptr1);
	}


	else if(argc == 3)
	{       
                //for reading
		fptr1 = fopen("file_1.txt","r");
		if(fptr1 == NULL)
		{
			fprintf(stderr,"could not open files\n");
		}
                //for reading
		fptr2 = fopen("file_2.txt","r");
		if(fptr2 == NULL)
		{
			fprintf(stderr,"could not open files\n");
		}
                //for wriring
		fptr3 = fopen("file_3.txt","w");
		if(fptr3 == NULL)
		{
			fprintf(stderr,"could not open files\n");
		}

		int ch,i=0;
		char buf[1000];
                //copy data
		while((ch = fgetc(fptr1)) != EOF)
		{
			fputc(ch,fptr3);
		}
		buf[i]= '\0';
		fputs(buf,fptr3);

		i=0;
                //copy data
		while((ch = fgetc(fptr2)) != EOF)
		{
			fputc(ch,fptr3);
		}
		buf[i]= '\0';
		fputs(buf,fptr3);
                
                //closing of file
		fclose(fptr1);
		fclose(fptr2);
		fclose(fptr3);
	}
	return 0;
}


