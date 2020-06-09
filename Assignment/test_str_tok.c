#include<string.h>
int main()
{
char str1[]="Hello;hai:bye";
char *str2=";:";
char *token;
token=strtok(str1,str2);//replace str2(delimeter) with \o and return address of first character of string
while(token!= NULL)
{

printf("%s\n",token);
token=strtok(NULL,str2);//indicates fun called after  first time
}
}
