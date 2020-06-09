#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "decode.h"
#include "types.h"
#include "common.h"
#define BMP_HEADER 54

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in case of RGB color image)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 * bpp is at offset 28, size is 2 bytes
 */

//uint get_image_size_for_bmp(EncodeInfo *encInfo)
uint get_image_size_for_bmp(FILE *fptr_src_image)
{
    //  FILE *fptr_src_image = encInfo->fptr_image; // Copy to local var. Just to shorten the code
    // encInfo->fptr_image = FILE *fptr_src_image;
    uint width, height;
    unsigned short bpp;
    long img_size;

    // Seek to 18th byte
    fseek(fptr_src_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_src_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_src_image);
    printf("height = %u\n", height);

    // Get bits per pixel
    fseek(fptr_src_image, 28, SEEK_SET);
    fread(&bpp, sizeof(short), 1, fptr_src_image);
    printf("bpp = %hu\n", bpp);

    // Store values in encInfo
    /*   encInfo->width = width;
	 encInfo->height = height;
	 ncInfo->bpp = bpp;*/

    img_size = width * height * bpp / 8; // Calculate image size
    return img_size;
}

/* Description: Open files
 * Inputs: Source image filename, Secret filename and Stego Image file name
 * Output: FILE pointers for above files
 * Return Value:
 *  e_success - If all files are opened,
 *  e_failure - On file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_dest_image = fopen(encInfo->dest_image_fname, "w");
    //Do Error handling
    if (encInfo->fptr_dest_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->dest_image_fname);
	return e_failure;
    }
    else
    {
	printf("INFO:Opened .bmp file\n");
	//return e_success;
    }       

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    //Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);
	return e_failure;
    }
    else
    {
	printf("INFO:Opened secret.txt file\n");
	//return e_success;
    }


    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    //Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);
	return e_failure;
    }
    else
    {
	printf("INFO:Opened stego_image.bmp\nINFO:Done\n");
        printf("INFO:##Encoding Procedure Started.##\n");
	//return e_success;
    }
        
    // All files opened, return e_success
    return e_success;
}

//for getting file size
uint get_file_size(FILE *fptr)
{

    uint file_size;
    
    //for settingb pointerfrom starting to end
    fseek(fptr, 0L, SEEK_END);
   
    //for file size
    file_size = ftell(fptr);
   
    //again set pointer in starting
    fseek(fptr, 0L, SEEK_SET);

    return file_size;
}

//for all the files
Status read_and_validate_decode_args(char *argv[], EncodeInfo *encInfo)
{
   //for reading
    FILE *fp = fopen(argv[2], "r");
    //for checking content of file
    if (fp == NULL)
    {
	return e_failure;
    }
  
    if (argv[2] != NULL)
     {
	encInfo->stego_image_fname = arg[2];
	printf("INFO:.bmp file is present\n");
	return e_success;
    }
    else
    {
	return e_failure;
    }
     
    //for checking third arg
     
     //for checking arg 4
    if (argv[3] == NULL)
    {
	 encInfo->dest_image_fname = "decrypted_image.bmp";
         printf("INFO:Output file is not present.created decrypted_image.bmp as output by default.\n");
    }
    else
    {
	encInfo->dest_fname = argv[4];
	//return e_success;
    }
    return e_success;
}


//for checking of capacity of file
Status check_capacity(EncodeInfo *encInfo)
{
   // char MAGIC_STRING[10];
    uint  image_size, total_size = 0;
    uint file_size;
    //fun clling
    image_size = get_image_size_for_bmp(encInfo->fptr_src_image); 
    //fun calling
    file_size = get_file_size((encInfo->fptr_secret)); 
     
    //checking file size
    if(file_size != 0)
    {
	printf("INFO: %s file is not empty\n",encInfo->secret_fname);
    }
    else
    {
	printf("ERROR : %s file is empty\n",encInfo->secret_fname);
	return e_failure;
    }

      
total_size = 54 + ( strlen(MAGIC_STRING) * 8 ) + 4  * 8 + (4 * 8) + (4 * 8) + 8  * 8 ;  
 

    //condition for checking
    if(total_size > image_size)
    {
	return e_failure;
    }
    else
    {
	return e_success;
    }
}

//for copy header
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image) 
{
    
    char img_head[55];
 
    //for reading contnt of source image   
    if (fread(img_head,sizeof(char),54,fptr_src_image) != BMP_HEADER)
    {
	return e_failure;
    }
    //for checking writing of bmp header
    if (fwrite(img_head,sizeof(char),54,fptr_dest_image) != BMP_HEADER)
    {
	return e_failure;
    }
    printf("INFO:Copying BMP header\nINFO:Done\n");
    return e_success;
}

//for encoding magic string
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo)
{
   //for reading image data
   fread(encInfo->image_data, sizeof(encInfo->image_data), 1,encInfo->fptr_src_image);
   
   for (int i = 0; i < strlen(MAGIC_STRING); i++)
   {     //fun calling
        if (encode_byte_to_lsb(*(magic_string + i), encInfo->image_data) != e_success)
	{
	    printf("ERROR IN COPYING\n");
	    return e_failure;
	}
	else
	{
            //for writing the first char of magic string till next  8 byte
	    fwrite(encInfo->image_data, sizeof(char), 8, encInfo->fptr_stego_image);
	}
   }
   printf("INFO:Encoding magic string\nINFO:Done\n");
   return e_success;
}

//fun for encoding secret file extension
Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo)
{
    //for reading content
    fread(encInfo->image_data, sizeof(encInfo->image_data), 1,encInfo->fptr_src_image);
    //for printing ectension 
    for (int i = 0; i < MAX_FILE_SUFFIX; ++i)
    {
	if (encode_byte_to_lsb(*(file_extn + i), encInfo->image_data) != e_success)
	{
	     printf("ERROR IN COPYING\n");
	     return e_failure;
	}
	else
	{   //for encoding extension after magic string
	    fwrite(encInfo->image_data, sizeof(char), 8, encInfo->fptr_stego_image);
	}
    }
    printf("INFO:Encoding secret file extension\nINFO:Done\n");
    return e_success;
}

Status encode_byte_to_lsb(char data, char* image_buffer)
{
    //for encoding byte to lsb  
    for (int i = 0; i < MAX_IMAGE_BUF_SIZE ; i++)
    {
	*image_buffer = ((*image_buffer & ~0x01) | (data & 0x01));
    }
   
    return e_success;
}


//for encoding data to image
Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image)
{
    //for reading data of source   
    fread(data, sizeof(data), 1,fptr_src_image);
    //for writing data
    if(fwrite(data,sizeof(char),1,fptr_stego_image) != 1) 
    {    //checking for error
	if(ferror(fptr_stego_image) != 0)
	{
	    printf("ERROR : failed to write into a file\n");
	    clearerr(fptr_stego_image);
	    return e_failure;
	}
    }
    printf("INFO:Encoding secret file data to image\nINFO:Done\n"); 
    return e_success;
}

//for encoding secret file data
Status encode_secret_file_size(unsigned int file_size, EncodeInfo *encInfo)
{
    
    fread(encInfo->image_data, sizeof(encInfo->image_data), 1,encInfo->fptr_src_image);
    unsigned int size = file_size;
	printf("%d",file_size);
	int i;
	char ch;
	for (i = 31; i >= 0; i--)
	{

		ch=(char)(size>>i&1);
		fwrite(&ch,sizeof(char),1,encInfo->fptr_stego_image);
	}
	printf("INFO:Encoding secret file size\nINFO:Done\n");
	return e_success;
}
//for encoding secret file data
Status encode_secret_file_data(EncodeInfo *encInfo)
{
     
      unsigned char ch,ch1;
      unsigned int size1= encInfo->size_secret_file;
	
	rewind(encInfo->fptr_secret);
	while (fread(&ch1, sizeof(char), 1, encInfo->fptr_secret))
	{
		int i;
		for (i = 7;i >= 0;i--)
		{
			ch = (char)(ch1 >> i&1);
			fwrite(&ch,sizeof(char),1,encInfo->fptr_stego_image);
		}
		if (size1 < 1)
		{
			break;
		}
		size1--;
	}
	printf("INFO:Encoding secret file data\nINFO:Done\n");
	return e_success;
}
//for copyb data
Status copy_remaining_img_data(FILE *fptr_src_image, FILE *fptr_dest_image)
{     
	unsigned char ch;

	for (;	fread(&ch,sizeof(char),1,fptr_src_image) != 0; )
	{
	
		fwrite(&ch,sizeof(char),1,fptr_dest_image);
	}
	printf("INFO:Copy left over data of image\nINFO:Done\n");
	return e_success;
}
