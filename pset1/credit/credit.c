#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Get user input
    string input = get_string("Number: ");

    // Get length of input
    int c = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        c++;
    }

    // Initialise list of integers
    int number[c];

    // Populate list of integers with digits of input
    for (int i = 0; i < c; i++)
    {
        number[i] =  input[i] - '0';
    }

    // Initialise variable for sum
    int sum = 0;

    // Iterate over every other digit, starting with the last
    for (int i = c - 1; i >= 0; i -= 2)
    {
        sum += number[i];
    }

    // Iterate over every other digit, starting with the secon to last
    for (int i = c - 2; i >= 0; i -= 2)
    {
        if (number[i] * 2 >= 10)
        {
            sum += (number[i] * 2) % 10;
            sum += ((number[i] * 2) / 10) % 10;
        }
        else
        {
            sum += number[i] * 2;
        }
    }

    // Checking validity
    if (!(sum % 10))
    {
        if (c == 15 && number[0] == 3 && (number[1] == 4 || number[1] == 7))
        {
            printf("AMEX\n");
        }

        else if (c == 16 && number[0] == 5 && (number[1] == 1 || number[1] == 2 || number[1] == 3 || number[1] == 4 || number[1] == 5))
        {
            printf("MASTERCARD\n");
        }

        else if ((c == 13 || c == 16) && number[0] == 4)
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
