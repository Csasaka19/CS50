#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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
    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           //swap pixels the left should be in the right and the right should be in the left
           if (width % 2 == 0)
           {
               if (j < width / 2)
               {
                   RGBTRIPLE temp = image[i][j];
                   image[i][j] = image[i][width - j - 1];
                   image[i][width - j - 1] = temp;
               }
           }
           else
           {
               if (j <= width / 2)
               {
                   RGBTRIPLE temp = image[i][j];
                   image[i][j] = image[i][width - j - 1];
                   image[i][width - j - 1] = temp;
               }
           }
        }
        
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Copy each pixel to the copy array
            copy[i][j] = image[i][j];

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize the sum of red, green, and blue values to 0
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;
            float counter = 0;

            // Loop through each pixel in the image
            for (int k = -1; k < 2; k++)
            {
                // Check if the pixel is out of bounds
                if (i + k < 0 || i + k > height - 1)
                {
                    continue;
                }
                for (int l = -1; l < 2; l++)
                {
                    // Check if the pixel is out of bounds
                    if (j + l < 0 || j + l > width - 1)
                    {
                        continue;
                    }
                    // Add the red, green, and blue values of the pixel to the sum
                    sumRed += copy[i + k][j + l].rgbtRed;
                    sumGreen += copy[i + k][j + l].rgbtGreen;
                    sumBlue += copy[i + k][j + l].rgbtBlue;
                    counter++;
                }
            }
            // Update the original red, green, and blue values to the new blurred value
            image[i][j].rgbtRed = round(sumRed / counter);
            image[i][j].rgbtGreen = round(sumGreen / counter);
            image[i][j].rgbtBlue = round(sumBlue / counter);
        }
    }
}