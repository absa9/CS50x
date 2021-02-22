#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //itrate through rows
    for (int i = 0 ; i < height ; i++)
    {
        //iterate through the columns
        for (int j = 0 ; j < width ; j++)
        {
            float x = 0;
            int avg = 0;
            int b = 0, g = 0, r = 0;

            //get the values of blue, green and red
            b = image[i][j].rgbtBlue;
            g = image[i][j].rgbtGreen;
            r = image[i][j].rgbtRed;

            x = round((b + g + r) / 3.0); //round the value to nearst integer
            avg = x;

            //save the new values back to the image
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaBlue, sepiaGreen, sepiaRed;
    int newBlue = 0, newGreen = 0, newRed = 0;
    //iterate through every row
    for (int i = 0 ; i < height ; i++)
    {
        //iterate through the columns
        for (int j = 0 ; j < width ; j++)
        {
            //convert the values of red
            sepiaRed =   round(0.393 * image[i][j].rgbtRed
                               + 0.769 * image[i][j].rgbtGreen
                               + 0.189 * image[i][j].rgbtBlue);
            //if the value is very large set to the max value 255
            if (sepiaRed > 255)
            {
                newRed = 255;
            }
            else
            {
                newRed = sepiaRed;
            }

            //convert the values of Green
            sepiaGreen =   round(0.349 * image[i][j].rgbtRed
                                 + 0.686 * image[i][j].rgbtGreen
                                 + 0.168 * image[i][j].rgbtBlue);
            //if the value is very large set to the max value 255
            if (sepiaGreen > 255)
            {
                newGreen = 255;
            }
            else
            {
                newGreen = sepiaGreen;
            }

            //convert the values of blue
            sepiaBlue =   round(0.272 * image[i][j].rgbtRed
                                + 0.534 * image[i][j].rgbtGreen
                                + 0.131 * image[i][j].rgbtBlue);
            //if the value is very large set to the max value 255
            if (sepiaBlue > 255)
            {
                newBlue = 255;
            }
            else
            {
                newBlue = sepiaBlue;
            }

            //set the new values back to the image
            image[i][j].rgbtRed = newRed;
            image[i][j].rgbtGreen = newGreen;
            image[i][j].rgbtBlue = newBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0, n = width / 2 ; j < n ; j++)
        {
            //save the value of the right half in a temp. variable
            int tmpRed = image[i][j].rgbtRed;
            int tmpGreen = image[i][j].rgbtGreen;
            int tmpBlue = image[i][j].rgbtBlue;

            //copy the value of the j(th) element of the left half
            //to the parallel element of the right half
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            //copy the value of the right half of the temp. variable
            //to its element of the left half
            image[i][width - j - 1].rgbtRed = tmpRed;
            image[i][width - j - 1].rgbtGreen = tmpGreen;
            image[i][width - j - 1].rgbtBlue = tmpBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE ogImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ogImage[i][j] = image[i][j];
        }
    }

    for (int i = 0, red, green, blue, counter; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = green = blue = counter = 0;

            //for all cases
            if (i >= 0 && j >= 0)
            {
                red += ogImage[i][j].rgbtRed;
                green += ogImage[i][j].rgbtGreen;
                blue += ogImage[i][j].rgbtBlue;
                counter++;
            }
            //for cases that have pixels on the left side
            if (i >= 0 && j - 1 >= 0)
            {
                red += ogImage[i][j - 1].rgbtRed;
                green += ogImage[i][j - 1].rgbtGreen;
                blue += ogImage[i][j - 1].rgbtBlue;
                counter++;
            }
            //for cases that have pixels on the right side
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                red += ogImage[i][j + 1].rgbtRed;
                green += ogImage[i][j + 1].rgbtGreen;
                blue += ogImage[i][j + 1].rgbtBlue;
                counter++;
            }
            //for cases that have pixels above it
            if (i - 1 >= 0 && j >= 0)
            {
                red += ogImage[i - 1][j].rgbtRed;
                green += ogImage[i - 1][j].rgbtGreen;
                blue += ogImage[i - 1][j].rgbtBlue;
                counter++;
            }
            //for cases that have pixels in the upper left corner
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += ogImage[i - 1][j - 1].rgbtRed;
                green += ogImage[i - 1][j - 1].rgbtGreen;
                blue += ogImage[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            //for cases that have pixels in the upper right corner
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                red += ogImage[i - 1][j + 1].rgbtRed;
                green += ogImage[i - 1][j + 1].rgbtGreen;
                blue += ogImage[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            //for cases that have pixels under it
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                red += ogImage[i + 1][j].rgbtRed;
                green += ogImage[i + 1][j].rgbtGreen;
                blue += ogImage[i + 1][j].rgbtBlue;
                counter++;
            }
            //for cases that have pixels in the down left corner
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                red += ogImage[i + 1][j - 1].rgbtRed;
                green += ogImage[i + 1][j - 1].rgbtGreen;
                blue += ogImage[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            //for cases that have pixels in the down right corner
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                red += ogImage[i + 1][j + 1].rgbtRed;
                green += ogImage[i + 1][j + 1].rgbtGreen;
                blue += ogImage[i + 1][j + 1].rgbtBlue;
                counter++;
            }

            image[i][j].rgbtRed = round(red / (counter * 1.0));
            image[i][j].rgbtGreen = round(green / (counter * 1.0));
            image[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }
    }

    return;
}
