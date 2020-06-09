char* my_strtok(char *str,char *del)
{       
	//declaration of varible
	static int pos = 0;
	static char *s;
	int j,start;

	start =pos;
	//condition for checking null
	if( str != NULL)
	{
		s=str;
	}

	//till posiion is not null
	while(s[pos] != '\0')      
	{      //loop
		for(j=0;del[j]!='\0';j++)
		{       
			//condition for delimeter
			if (s[pos] == del[j])
			{ 
				s[pos] ='\0';
				//increase position
				pos = pos + 1;
				//condition for null
				if (s[start] !='\0')
				{
					return (&s[start]);
				}
				else 
				{      
					//if not null
					start = pos;
					pos--;
					break;
				} 
			}
		}
		pos++;
	}

	s[pos] ='\0';
	//condition for null
	if(s[start] == '\0')
	{
		return NULL;
	}
	else
	{      
		//address return
		return (&s[start]);
	}
}
