#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel in the image
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
           // For each pixel, take the average of the red, green, and blue values to determine what shade of gray it should be 
           // Update the original red, green, and blue values to the new gray value
           image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
           image[i][j].rgbtGreen = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
           image[i][j].rgbtBlue = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel in the image
    for(int i = 0; i < height; i++)
    {
        for( int j = 0; j < width; j++)
        {
            // Compute sepia valuse for each pixel
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // Check if sepia value is greater than 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            else if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            else if (sepiaBlue > 255)
            {
               sepiaBlue = 255;
            }
            else
            {
                // Update values to sepia values
                image[i][j].rgbtRed = sepiaRed;
                image[i][j].rgbtGreen = sepiaGreen;
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
