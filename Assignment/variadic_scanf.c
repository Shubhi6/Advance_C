/*
Title-:WAP for the bitwise operations.
Author-:Shubhi omar
Date-:25/09/2019
Description-:Input-: Read a  no and choice from user and the no of bits to shift
             Output-: 


 */




#include <stdio.h>
#include <stdarg.h>

//function definition
int my_scanf(char *fmt, ...)
{       
        //declaration of variable
	va_list ap;
	int *d;
	char *c, *s;
	float *f;
	double *lf;
	int count=0;
       
        //taking the variadic variable
	va_start(ap, fmt);
       
        //condition for checking format specifier
	while (*fmt)
	{       
                //condition for specifier
		if ( *fmt  == '%')
		{ 
			fmt++;
                        
                        //condition for format specifier
	        	switch (*fmt) 
			{
				case 's':              /* string */
					s = va_arg(ap, char*);
					fscanf(stdin,"%s", c);
					 fmt++;
                                        count++;
					break;
				case 'd':              /* int */
					d = va_arg(ap, int*);
					fscanf(stdin, "%d", d);
                                        fmt++;
					count++;
					break;
				case 'c':              /* char */
					/* need a cast here since va_arg only
					   takes fully promoted types */
					c =va_arg(ap, char*);
					fscanf(stdin,"%c", c);
					fmt++;
                                        count++;
					break;
				case 'f':              /* float*/
					f = va_arg(ap, float*);
					fscanf(stdin,"%f", f);
                                        fmt++;
					count++;
					break;
				case 'l':
					fmt++;
					if (*fmt  == 'f') 
					{             /* string */
						lf = va_arg(ap, double*);
						fscanf(stdin,"%lf", lf);
                                                fmt++;
						count++;
					}
					break;  

				default:                          
					fprintf(stderr,"my_printf error!!");
					break;
			}
		}
		else
		{
			fmt++;
		}
	}

}






int main()
{       
        //declaration of variable
	int d; 
	char c;
	float f;
	double lf ;
	char s[100];
        
        //printing value using fun
	my_scanf("scanning:%d %c %f %lf %s",&d,&c,&f,&lf,s);
        printf("You entered:int=%d\nchar=%c\nfloat_value=%f\ndouble_value=%lf\nstring=%s\n ",d,c,f,lf,s);
}


