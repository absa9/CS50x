#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//this is program do convert a message entered from the user bz shifiting evrey charachter
//of the message by number (key) that the user should enter it while
//running the programm within the command line argument

int main(int argc, string argv[])
{
    int k;

    //check the validation of the key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int length = strlen(argv[1]);   //get the length of the key

        for (int i = 0 ; i < length ; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            else
            {
                k = atoi(argv[1]);
            }
        }
    }


    //get the plaintext
    string ptext = get_string("Plaintext: ");

    //get the length of the plaintext
    int textlen = strlen(ptext);

    printf("ciphertext: ");

    for (int i = 0 ; i < textlen ; i++)
    {
        int x;
        int c;

        if (islower(ptext[i]))
        {
            //convert the lower charachters
            x = ptext[i];
            c = ((x - 97 + k) % 26) + 97;
            printf("%c", c);
        }
        else if (isupper(ptext[i]))
        {
            //convert the upper charachters
            x = ptext[i];
            c = ((x - 65 + k) % 26) + 65;
            printf("%c", c);
        }
        else
        {
            //print anz other symboles or numbers
            printf("%c", ptext[i]);

        }
    }

    printf("\n");
    return 0;
}