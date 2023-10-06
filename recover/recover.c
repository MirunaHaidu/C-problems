#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int HEADER_SIZE = 4;
const int BLOCK_SIZE = 512;

bool is_JPEG(uint8_t header[HEADER_SIZE]);

int main(int argc, char *argv[])
{

    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    typedef uint8_t BYTE;
    BYTE buffer[BLOCK_SIZE];

    int fileCount = 0;
    FILE *output = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (is_JPEG(buffer))
        {
            if (output != NULL)
            {
                fclose(output);
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", fileCount++);
            output = fopen(filename, "w");
            if (output == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", filename);
                return 2;
            }
        }
        if (output != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(file);

    return 0;
}

bool is_JPEG(uint8_t header[HEADER_SIZE])
{
    return (header[0] == 0xff && header[1] == 0xd8 && header[2] == 0xff && (header[3] >= 0xe0 && header[3] <= 0xef));
}