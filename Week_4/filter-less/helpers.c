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
           float Red = image[i][j].rgbtRed;
           float Green = image[i][j].rgbtGreen;
           float Blue = image[i][j].rgbtBlue;

           int average = round((Red + Green + Blue) / 3.0);
           image[i][j].rgbtRed = average;
           image[i][j].rgbtGreen = average;
           image[i][j].rgbtBlue = average;
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
            // Compute sepia values for each pixel
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * Red + 0.769 * Green + 0.189 * Blue);
            int sepiaGreen = round(.349 * Red + .686 * Green + .168 * Blue);
            int sepiaBlue = round(.272 * Red + .534 * Green + .131 * Blue);

            // Check if sepia value is greater than 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
               sepiaBlue = 255;
            }
            
            // Update values to sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
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