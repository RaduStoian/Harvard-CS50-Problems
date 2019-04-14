// Recover 50 deleted jpgs from an image of a memory card named card.raw
//
// Program accepts 1 argument - the input file 
//
// Searches through card.raw in blocks of 512 bytes. 
//
// Looks for the 4 bytes signifying the start of a jpg
//
// If found, it opens a new jpg file and writes all next bytes to that file until it finds another start of jpg.
// Then it closes the previous jpg file and opens another. 
//  
// Process continues until the end of the memory card, when it cannot find another full block of 512 bytes.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{


    char *infile = argv[1];


    // Accept only 1 arguments
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./recover file\n");
        return 1;
    }

    // Make sure you can open file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }


    // 1 Block of 512 bytes
    unsigned char buffer[512];

    // file counter
    int jpg = 0;
    int count = 0;
    FILE *picture = NULL;


    // Reading from Card till the end
    while (fread(buffer, 512, 1, inptr) == 1)
    {


        // look for first 4 bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)

        {


            // to close picture
            if (jpg == 1)
            {
                fclose(picture);
            }

            else

            {
                jpg = 1;
            }


            // open picture
            if (jpg == 1)
            {
                char filename[8];
                sprintf(filename, "%03i.jpg", count);
                picture = fopen(filename, "a");
                count++;

            }

        }

        if (jpg == 1)
        {
            // write to picture
            fwrite(&buffer, 512, 1, picture);
        }
    }


    fclose(inptr);
    fclose(picture);
    return 0;
}
