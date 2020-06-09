#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "decode.h"
#include "types.h"
#include "common.h"
#include "test_decode.c"

//for command line argument input in main
int main(int argc, char *argv[])
{
    Status status;
    char *secret_file, *src_image, *stego_image;
    OperationType op_type;
    EncodeInfo encInfo;
    op_type = check_operation_type(argv);

    // Fill with sample filenames
    /*  secret_file = "secret.txt";
	src_image = "beautiful.bmp";
	stego_image = "stego_img.bmp";*/
    //for encryption
    if (op_type == e_decode)
    {
	printf("INFO: Decryption\n");

        //for reading and validating code
	if(read_and_validate_decode_args(argv, &encInfo) == e_failure)
	{
	    printf("INFO: Output .bmp file is not present\n");
	    return e_failure;
	}
	else
	{
	    printf("INFO:Opening required files.\n");
	    // Test open_files
	   if (do_decoding(&encInfo) == e_failure)
	  {
	    fprintf(stderr, "ERROR: Unable to encode %s file into %s image\n", secret_file, src_image);
	    return 1;
	  }
	  else
	  {
            printf("###Decryption done successfully.###\n");
	    fprintf(stdout,"DECRYPTION: %s file is decrypted in %s image\n", encInfo.dest_fname, encInfo.stego_image_fname);
	    return 0;
          }
    }
    
    printf("INFO : operation type not done\n");
    return 0;
}
}

//for checking operation type
OperationType check_operation_type(char *argv[])
{
    if (!(strcmp(argv[1],"-e")))
    {
	return e_encode;
    }
    else if(!(strcmp(argv[1],"-d")))
    {
	return e_decode;
    }
    else
    {  
       printf("Enter operation type\n-e for encryption\n-d for decryption.\n");
       return e_unsupported;
    }
}

//for encoding
Status do_decoding(EncodeInfo *encInfo)
{       
        //calling function for open
	if (open_files(encInfo) == e_success)
	{       
              //  calling fun  for copy bmp
		if (copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
		{       
                        //calling fun for magic string
			if (decode_magic_string(MAGIC_STRING, encInfo) == e_success)
			{       
                                //calling fun for secret file
				if (decode_secret_file_extn(encInfo->extn_secret_file,encInfo) == e_success)
				{       
                                        //calling fun for secret file
					if (decode_secret_file_size(encInfo->size_secret_file, encInfo) == e_success)
					{       
                                                //calling fun for secret file
						if (decode_secret_file_data(encInfo) == e_success)
						{       
                                                        //calling fun for decoding
							if (decode_data_to_image(encInfo->secret_data, encInfo->size_secret_file, encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
							{
								if (copy_remaining_img_data(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
								{
									return e_success;
								}
								else
								{
									return e_failure;
								}

							}
							else
							{
								return e_failure;
							}
						}      
						else
						{
							return e_failure;
						}


					}
					else
					{
						return e_failure;
					}

				}
				else
				{
					return e_failure;
				}

			}
			else
			{
				return e_failure;
			}

		}
		else
		{
			return e_failure;
		}

	}
}


