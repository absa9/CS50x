#include <stdio.h>
#include <stdlib.h>
#include<cs50.h>
#include<math.h>
#include <stdbool.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    //ckeck that user provides a file name
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    //get the input file name
    char *file_input = argv[1];

    //open that file to recover from
    FILE *file = fopen(file_input, "r");

    //check that the file is successfully opend
    if (file == NULL)
    {
        printf("Invalid file\n");
        fclose(file);
        return 2;
    }

    //declare some variables and a pointer to new file
    unsigned char id[512];
    int count = 0;
    char file_name[10];
    FILE *newjpeg = NULL;



    while (true)
    {
        //read a block of memory from input file
        size_t n = fread(id, sizeof(char), 512, file);

        if (n == 0 && feof(file))
        {
            break;
        }

        //check if the block contain a jpg header
        bool header = (id[0] == 0xff) && (id[1] == 0xd8) && (id[2] == 0xff) && ((id[3] & 0xf0) == 0xe0);

        if (header && newjpeg != NULL)
        {
            //close the new file if one was already opend
            fclose(newjpeg);

            //incrase the number of jpg files we discoverd
            count++;
        }

        //if a header found
        if (header)
        {
            //name a file for the jpgimage that has been found and open it
            sprintf(file_name, "%03i.jpg", count);
            newjpeg = fopen(file_name, "w");
        }

        //check that the new file is successfully opend
        if (newjpeg != NULL)
        {
            //write the read data of the jpg to the new file
            fwrite(id, sizeof(char), n, newjpeg);

        }


    }

    //close any opend files
    fclose(newjpeg);
    fclose(file);

    return 0;
}
