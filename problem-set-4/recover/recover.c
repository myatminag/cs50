#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // While there's still data left to read from the memory card
    BYTE buffer[512];
    int file_counter = 0;
    FILE *img = NULL;
    char filename[8];

    // Create JPEGs from the data
    while (fread(buffer, sizeof(BYTE), 512, infile) == 512)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            // Create new filename
            sprintf(filename, "%03i.jpg", file_counter++);

            // Open new JPEG file for writing
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create file.\n");
                return 1;
            }
        }

        // Write to the file if an image file is currently open
        if (img != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
    }


    // Close any remaining open files
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(infile);
    return 0;
}
