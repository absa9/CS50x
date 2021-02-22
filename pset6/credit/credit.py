from cs50 import get_int
import math

card_num = get_int("Enter your credit number: ")
n = str(card_num)

#get the length of the carrd's number
length = len(n)

if length == 13 or length == 15 or length == 16:
    sum2 = 0;
    check_sum = 0;
    even_sum = 0;

    i = 0
    while i < length:
        count = length - i
        even_sum += int(n[count - 1]) #add the numbers, which won't multiplied by 2

        #multiply each other num by 2 and add its digits to sum
        if count > 1:
            num2 = 2 * int(n[count - 2])
            sum2 += (num2 % 10) + int((num2 / 10))
        i += 2

    check_sum = even_sum + sum2

    #check if the last digit of check_sum is 0 then continue if true
    if check_sum % 10 == 0:
        #get the first digits of the card number to determine the card's type
        visa = int(n[0])
        amex = int(card_num / math.pow(10, 13))
        master = int(card_num / math.pow(10, 14))

        if length == 13 or length == 16 and visa == 4:
            print("VISA")

        elif length == 16 and master >= 51 and master <= 55:
            print("MASTERCARD")

        elif length == 15 and (amex == 34 or amex == 37):
            print("AMEX")

        else:
            print("INVALID")

else:
    print("INVALID")


