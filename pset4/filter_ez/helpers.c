#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int mean = round((round(image[i][j].rgbtBlue) + round(image[i][j].rgbtGreen) + round(image[i][j].rgbtRed)) / 3);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = mean;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Sepia formula
            int sepiared = (int) round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiagreen = (int) round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiablue = (int) round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            // Cap at 255 (Ternary operator)
            (sepiared > 255) ? (image[i][j].rgbtRed = 255) : (image[i][j].rgbtRed = sepiared);

            (sepiagreen > 255) ? (image[i][j].rgbtGreen = 255) : (image[i][j].rgbtGreen = sepiagreen);

            (sepiablue > 255) ? (image[i][j].rgbtBlue = 255) : (image[i][j].rgbtBlue = sepiablue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Temp array
    RGBTRIPLE tmp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int c = 0;
            int sumred = 0;
            int sumgreen = 0;
            int sumblue = 0;

            // Iterate over pixels near pixel in question
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    // Check if nearby pixels exists
                    if (i + a >= 0 && i + a < height && j + b >= 0 && j + b < width)
                    {
                        // Sum up existing nearby pixel colors and increment c for average calculation
                        sumred += image[i + a][j + b].rgbtRed;
                        sumgreen += image[i + a][j + b].rgbtGreen;
                        sumblue += image[i + a][j + b].rgbtBlue;
                        c++;
                    }
                }
            }

            // Calculate and assign averages
            tmp[i][j].rgbtRed = round((float) sumred / c);
            tmp[i][j].rgbtGreen = round((float) sumgreen / c);
            tmp[i][j].rgbtBlue = round((float) sumblue / c);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Copy pixel values from tmp to original
            image[i][j] = tmp[i][j];
        }
    }
    return;
}
