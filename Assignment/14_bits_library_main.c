#include"14_bits_library.c"
#include"14_bits_library.h"
int main()
{       
        //declaration of variable
	int num, n, result, val, pos;
	int choice;
	char option;

	do{     
       
		printf("Please select the bit operation:\n1.get_n_bits\n2.replace_n_bits\n3.get_nbits_from_position\n4.replace_nbits_from_pos\n5.toggle_n_bits");
		//for taking information from user
		printf("\nEnter choice");
		scanf("%d", &choice);

		printf("Enter num:");
		scanf("%d", &num);
		printf("Please enter the bits:");
		scanf("%d", &n);

		if(choice == 2 || choice == 4)
		{ 
			printf("Enter val:");
			scanf("%d" ,&val);
		}  
		if(choice == 3 || choice == 4 || choice  == 5)
		{ 
			printf("Enter pos:");
			scanf("%d" ,&pos);
		}        
                
                //switch case for  taking choice              
		switch(choice)
		{
			case 1: 
				//for taking value
                                print_bits(num);
				printf("%d ",get_nbits(num,n));
				printf("\n");
				//function call for print result in bits
				print_bits(result);
				break;

			case 2:
                                print_bits(num);
				printf("%d ",replace_nbits(num,n ,val));
				printf("\n");
				//function call for print result in bits
				print_bits(result);
				break;

			case 3:
                                print_bits(num);
				printf("%d ",get_nbits_from_pos(num,n ,pos));
				printf("\n");
				//function call for print result in bits
				print_bits(result);
				break;

			case 4:
                                print_bits(num);
				printf("%d ",replace_nbits_from_pos(num,n ,val,pos));
				printf("\n");
				//function call for print result in bits
				print_bits(result);
				break;


			case 5:
                                print_bits(num);
				printf("%d ",toggle_nbits_from_pos(num,n ,pos));

				printf("\n");
				//function call for print result in bits
				print_bits(result);
				break;

			default:
				printf("INVALID CHOICE");
				break;
		}

		printf("continue(y/n):");
		scanf("\n%c",&option);
		if (option == 'y')
		{ 
			continue;
		}
		else
		{
			break;
		}
	}while(1);

	return 0;
}


