#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Declar variable for change owed
    float dollars;

    // Ask for positive float input
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // Declare and initialise cents variable
    int cents = round(dollars * 100);

    // Possible coins to use as change
    int coins[] = {25, 10, 5, 1};
    int change = 0;

    // For each coin, check whether it is small enough, deduct from cents and increment change counter
    for (int i = 0; i < 4; i++)
    {
        while (coins[i] <= cents)
        {
            cents -= coins[i];
            change++;
        }
    }

    printf("%i\n", change);
}

