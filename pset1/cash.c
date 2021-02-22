#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{

//asking the user for the amount of change in dollars
    float dollar;
    do
    {
        dollar = get_float("Enter the amount of Dollars $$: ");
    }
    while (dollar < 0);

//convert the amount to cents
    int cents = round(dollar * 100);

    int penny = 0;
    int nickels = 0;
    int dimes = 0;
    int quarter = 0;

//calaculating how many coins will  be returend
    while (cents > 0)
    {

        while (cents >= 25){
            quarter++;
            cents -= 25;
        }

        while (cents >= 10)
        {
            dimes++;
            cents -= 10;
        }

        while (cents >= 5)
        {
            nickels++;
            cents -= 5;
        }

        while (cents >= 1)
        {
            penny++;
            cents -= 1;
        }
    }

    int coins = penny + nickels + dimes + quarter;
    printf("%i", coins);

}