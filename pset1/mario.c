#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

//asking user for the height and check if it between 1 & 8 included
    do
    {
        height = get_int("Enter a positive number: ");
    }
    while (height < 1 || height > 8);

//print the pyramid
    for (int row = 1 ; row <= height ; row++)
    {
        //print spaces
        for (int space = 0 ; space < height - row ; space++)
        {
            printf(" ");
        }

        //print hash of first colum
        for (int hash = 1 ; hash <= row ; hash++)
        {
            printf("#");
        }

        printf("  ");

        //print hash of second colum
        for (int hash = 1 ; hash <= row ; hash++)
        {
            printf("#");
        }

        printf("\n");
    }


}


