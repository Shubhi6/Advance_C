#ifndef DECODE_H
#define DECODE_H

#include "types.h" // Contains user defined types

/* 
 * Structure to store information required for
 * encoding secrget file to source Image
 * Info about output and intermediate data is
 * also stored
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

typedef struct _DecodeInfo
{
   
    /* Secret File Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;

      /* Destination Image info */
    char *dest_image_fname;
    FILE *fptr_dest_image;
    uint image_capacity;
    uint bits_per_pixel;
    char image_data[MAX_IMAGE_BUF_SIZE];

} DecodeInfo;





/*Decoding Function Prototypes */

/* Perform the decoding */
Status do_decoding(DecodeInfo *decInfo);

/*Open stego file */
Status open_decode_file(DecodeInfo *decInfo);

/*Decode Magic String*/
Status decode_magic_string(char* magic_string,DecodeInfo *decInfo);

/*Decode secret file extension size*/
Status decode_secret_file_extn_size(uint file_size,DecodeInfo *decInfo);

/*Decode secret file extension */
Status decode_secret_file_extn(const char *file_extn,DecodeInfo *decInfo);
/*Decode secret file size*/
Status decode_secret_file_size(FILE * fptr_stego_image, uint size_secret_file);

/*Decode secret file data*/
Status decode_secret_file_data(DecodeInfo *decInfo);

Status decode_data_to_image(char *data, int size, FILE *fptr_stego_image, FILE *fptr_dest_image);

/* decode a byte into array from LSB of image data  */
Status decode_byte_fromlsb(char *data, char *image_buffer);

#endif
