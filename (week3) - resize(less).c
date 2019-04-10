// Resizes a bmp file.
// takes 3 inputs : n - times to resize, input file and output file.

//reads input file,
//creates new updated file headers,
//loops through all pixels in all rows,
//copies pixels n times and rows n times,
//adds padding at the end of all rows if necessary
//writes to output file,

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // n smaller than 100
    if (n < 0 && n > 100)
    {
        fprintf(stderr, "n should be between 0 and 100\n");
        return 2;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }




    // UPDATE HEADER INFORMATION ----------------------------------------------

    // keep original img data
    int originWidth = abs(bi.biWidth);
    int originHeight = abs(bi.biHeight);


    bi.biWidth *= n;
    bi.biHeight *= n;



    // determine padding for new img
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // determine padding for old img
    int originPadding = (4 - (originWidth * sizeof(RGBTRIPLE)) % 4) % 4;



    bi.biSizeImage = (sizeof(RGBTRIPLE) * bi.biWidth + padding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);





    // Actual pixel copying ----------------------------------------------------
    int x;




    // iterate over all rows
    for (int i = 0; i < originHeight; i++)
    {


        // repeating the row n times.-----------
        for (int q = 0; q < n; q++)
        {

            // copy pixels onto the row ---------------
            for (int j = 0; j < originWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int z = 0; z < n; z++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // Adding padding at end of row ---
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }

            // go back to start of row.
            fseek(inptr, -(originWidth * 3), SEEK_CUR);

        }

        // go to the end of row.
        fseek(inptr, originWidth * 3, SEEK_CUR);

        // skip over padding to next row
        fseek(inptr, originPadding, SEEK_CUR);

    }


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
