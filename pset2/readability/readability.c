#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Declare variables
    int c = 0;
    float letters = 0;
    float words = 1;
    float sentences = 0;
    string text = get_string("Text: ");

    // Iterate over characters in text
    while (text[c] != '\0')
    {
        if (text[c] == ' ')
        {
            if (text[c + 1] != ' ')
            {
                words++;
            }
        }

        // Check whether element is in alphabet
        if (((65 <= (int) text[c] && (int) text[c] <= 90)) || ((97 <= (int) text[c]) && (int) text[c] <= 122))
        {
            letters++;
        }

        // Check for '?', '.' or '!'
        if (text[c] == '.' || text[c] == '?' || text[c] == '!')
        {
            sentences++;
        }
        c++;
    }
    // Calculations
    float L = 100 * letters / words;
    float S = 100 * sentences / words;
    float index = round(0.0588 * L - 0.296 * S - 15.8);

    // Final conditions
    if (index >= 16)
    {
        printf("\nGrade 16+\n");
    }
    else if (index < 1)
    {
        printf("\nBefore Grade 1\n");
    }
    else
    {
        printf("\nGrade %d\n", (int) index);
    }
}