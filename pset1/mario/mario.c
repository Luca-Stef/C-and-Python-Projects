#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    switch(n)
    {
        case 1:
            printf("#  #\n");
            break;
        case 2:
            printf(" #  #\n##  ##\n");
            break;
        case 3:
            printf("  #  #\n  ##  ##\n###  ###\n");
            break;
        case 4:
            printf("   #  #\n  ##  ##\n ###  ###\n####  ####\n");
            break;
        case 5:
            printf("    #  #\n   ##  ##\n  ###  ###\n ####  ####\n#####  #####\n");
            break;
        case 6:
            printf("     #  #\n    ##  ##\n   ###  ###\n  ####  ####\n #####  #####\n######  ######\n");
            break;
        case 7:
            printf("      #  #\n     ##  ##\n    ###  ###\n   ####  ####\n  #####  #####\n ######  ######\n#######  #######\n");
            break;
        case 8:
            printf("       #  #\n      ##  ##\n     ###  ###\n    ####  ####\n   #####  #####\n  ######  ######\n #######  #######\n########  ########\n");
            break;
    }

}
