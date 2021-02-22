#include<stdio.h>
#include<cs50.h>
#include<math.h>
#include<stdlib.h>

int main(void)
{

//ask user enter a credit card number

    long long card_num = get_long("Enter your credit number: ");
    long long n = card_num;

//get the length of the carrd's number
    int length = floor(log10(llabs(n))) + 1;

    if (length == 13 || length == 15 || length == 16)
    {

        //convert the cardnumber into an array of didgits
        int card_num_arr[length];
        for (int i = 0 ; i < length ; i++)
        {
            card_num_arr [i] = card_num % 10;
            card_num /= 10;
        }

        //check the validation of the card's number
        int sum2 = 0;
        int check_sum = 0;
        int even_sum = 0;

        int i = 0;
        while (i < length)
        {
            even_sum += card_num_arr[i]; //add the numbers, which won't multiplied by 2

            //multiply each other num by 2 and add its digits to sum
            int num2 = 2 * card_num_arr [i + 1];
            sum2 += (num2 % 10) + (num2 / 10);
            i += 2;
        }

        check_sum = even_sum + sum2;

        if (check_sum % 10 == 0) //check if the last digit of check_sum is 0 then continue if true
        {

            //get the first digits of the card number to determine the card's type
            int visa = card_num_arr[length - 1];
            int amex = n / pow(10, 13);
            int master = n / pow(10, 14);

            if ((length == 13 || length == 16) && visa == 4)
            {
                printf("VISA\n");
            }
            else if (length == 16 && master >= 51 && master <= 55)
            {
                printf("MASTERCARD\n");
            }
            else if (length == 15 && (amex == 34 || amex == 37))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }

}