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
            image[i][j].rgbtBlue = mean;
            image[i][j].rgbtGreen = mean;
            image[i][j].rgbtRed = mean;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Temp array
    RGBTRIPLE tmp[height][width];

    //Gx and Gy kernels
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Iterate over pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Declare variables for summation
            int redGx = 0;
            int redGy = 0;

            int greenGx = 0;
            int greenGy = 0;

            int blueGx = 0;
            int blueGy = 0;

            // Iterate over 3x3 block
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    if (i + a >= 0 && i + a < height && j + b >= 0 && j + b < width)
                    {
                        // Multiply by corresponding value in kernel and aggregate
                        redGx += Gx[a + 1][b + 1] * image[i + a][j + b].rgbtRed;
                        redGy += Gy[a + 1][b + 1] * image[i + a][j + b].rgbtRed;

                        greenGx += Gx[a + 1][b + 1] * image[i + a][j + b].rgbtGreen;
                        greenGy += Gy[a + 1][b + 1] * image[i + a][j + b].rgbtGreen;

                        blueGx += Gx[a + 1][b + 1] * image[i + a][j + b].rgbtBlue;
                        blueGy += Gy[a + 1][b + 1] * image[i + a][j + b].rgbtBlue;
                    }
                }
            }
            // Cap at 255
            if ((int) round(sqrt(pow(redGx, 2) + pow(redGy, 2))) <= 255)
            {
                tmp[i][j].rgbtRed = (int) round(sqrt(pow(redGx, 2) + pow(redGy, 2)));
            }
            else
            {
                tmp[i][j].rgbtRed = 255;
            }

            if ((int) round(sqrt(pow(greenGx, 2) + pow(greenGy, 2))) <= 255)
            {
                tmp[i][j].rgbtGreen = (int) round(sqrt(pow(greenGx, 2) + pow(greenGy, 2)));
            }
            else
            {
                tmp[i][j].rgbtGreen = 255;
            }

            if ((int) round(sqrt(pow(blueGx, 2) + pow(blueGy, 2))) <= 255)
            {
                tmp[i][j].rgbtBlue = (int) round(sqrt(pow(blueGx, 2) + pow(blueGy, 2)));
            }
            else
            {
                tmp[i][j].rgbtBlue = 255;
            }
        }
    }

    // Copy tmp into image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }
    return;
}
