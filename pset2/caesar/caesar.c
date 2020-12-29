#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check number of command line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Set the key
    int k = atoi(argv[1]);

    // Check whether the first command line argument is an integer
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Declare string variables
    string plaintext = get_string("plaintext: ");
    char ciphertext[strlen(plaintext)];

    // Iterate and convert plaintext characters
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = ((plaintext[i] - 'A' + k) % 26) + 'A';
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = ((plaintext[i] - 'a' + k) % 26) + 'a';
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // Add null terminator and finish program
    ciphertext[strlen(plaintext)] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}