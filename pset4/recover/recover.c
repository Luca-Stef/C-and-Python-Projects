#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define BYTE data type
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Verify number of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Read file
    FILE *file = fopen(argv[1], "r");

    // Check for NULL file pointer
    if (file == NULL)
    {
        printf("NULL file pointer\n");
    }

    // Declare buffer, counter, and file pointer for jpeg file
    BYTE *buffer = NULL;
    do
    {
        buffer = malloc(512);
    }
    while (buffer == NULL);
    int i = 0;
    FILE *img = NULL;

    // Detect first jpeg signature
    while (fread(buffer, 1, 512, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            char name[8];
            sprintf(name, "%03i.jpg", i);
            img = fopen(name, "w");
            fwrite(buffer, 1, 512, img);
            break;
        }
    }

    // Write to jpg file until another signature is detected
    while (fread(buffer, 1, 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            i++;
            fclose(img);
            char name[8];
            sprintf(name, "%03i.jpg", i);
            img = fopen(name, "w");
            fwrite(buffer, 1, 512, img);
        }
        else
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    free(buffer);
}