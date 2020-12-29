#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool validate(string key);

int main(int argc, string argv[])
{
    string key = argv[1];

    //Check number of arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (validate(key))
    {
        // Declare plaintext and ciphertext
        string plaintext = get_string("plaintext: ");
        char ciphertext[strlen(plaintext)];

        // Iterate over every character in plaintext and append to ciphertext accordingly
        for (int i = 0; i < strlen(plaintext); i++)
        {
            if (isupper(plaintext[i]) != 0)
            {
                char s = toupper(key[((int) plaintext[i]) - 65]);
                ciphertext[i] = s;
            }
            else if (islower(plaintext[i]) != 0)
            {
                char s = tolower(key[((int) plaintext[i]) - 97]);
                ciphertext[i] = s;
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }
        ciphertext[strlen(plaintext)] = '\0';
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else
    {
        printf("Invalid key\n");
        return 1;
    }
}

bool validate(string key)
{
    int matches = 0;

    // Check key length
    if (strlen(key) == 26)
    {
        // Iterate over alphabet to ensure 26 unique alphabetic characters
        for (char i = 'a'; i <= 'z'; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (tolower(key[j]) == i)
                {
                    matches++;
                    break;
                }
            }
        }
        if (matches == 26)
        {
            return true;
        }
        else
        {
            printf("Key must contain 26 unique alphabetic characters\n");
            return false;
        }
    }
    else
    {
        printf("Key must be 26 characters long\n");
        return false;
    }
}