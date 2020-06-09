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
int my_printf(char *fmt, ...)
{       
        //declaration of variable
	va_list ap;
	int d;
	char c, *s;
	float f;
	double lf;
	int i=0;
       
        //taking the variadic variable
	va_start(ap, fmt);
       
        //condition for checking format specifier
	while (*(fmt + i))
	{       
                //condition for specifier
		if ( *(fmt + i) == '%')
		{ 
			i++;
                        
                        //condition for format specifier
	        	switch (*(fmt+i)) 
			{
				case 's':              /* string */
					s = va_arg(ap, char *);
					fprintf(stdout,"%s\n", s);
					i++;
					break;
				case 'd':              /* int */
					d = va_arg(ap, int);
					fprintf(stdout, "%d\n", d);
					i++;
					break;
				case 'c':              /* char */
					/* need a cast here since va_arg only
					   takes fully promoted types */
					c = (char)va_arg(ap, int);
					fprintf(stdout,"%c\n", c);
					i++;
					break;
				case 'f':              /* float*/
					f = va_arg(ap, double);
					fprintf(stdout,"%.6f\n", f);
					i++;
					break;
				case 'l':
					i++;
					if (*(fmt + i) == 'f') 
					{             /* string */
						lf = va_arg(ap, double);
						fprintf(stdout,"%.6lf\n", lf);
						i++;
					}
					break;  

				/*default:                          
					fprintf(stderr,"my_printf error!!");
					break;*/
			}
		}
		else
		{
			putc(*(fmt + i++),stdout);
		}
	}

}






int main()
{       
        //declaration of variable
	int i =10;
	char c= 'A';
	float f=10.5;
	double d= 7.89;
	char s[] = "EMERTXE";
        
        //printing value using fun
	my_printf("Integer value is:%d\n",i);
	my_printf("Character  is:%c\n",c);
	my_printf("Float value is:%f\n",f);
	my_printf("Double value is:%lf\n",d);
	my_printf("String is:%s\n",s);
}


