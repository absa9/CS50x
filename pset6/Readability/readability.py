import math

#a function to round the index to nearest integer

def proper_round(num):

    num_s = str(num)
    arr = num_s.split('.')
    if (arr.count==1):
        return num
    dec = arr[1]
    dec1 = int(dec[0])
    if dec1 < 5:
        return math.floor(num)
    else:
        return math.ceil(num)


# def proper_round(num, dec=0):
#     num = str(num)[:str(num).index('.')+dec+2]
#     if num[-1]>='5':
#         return float(num[:-2-(not dec)]+str(int(num[-2-(not dec)])+1))
#     return float(num[:-1])

#counters of charachters, words and sentences
ch = sent = 0
words = 1
end_sent = {'?', '!', '.'}

#get the text from the user
text = input("Text: ")

#iterate through the text
for c in text:
    if c.isalpha():
        ch += 1
    elif c.isspace():
        words += 1
    elif c in end_sent:
        sent += 1

#avg numbers of letters per 100 word
L = (ch / words) * 100

#avg num of sentences per 100 word
S = (sent / words) * 100

#Coleman-Liau index
index = 0.0588 * L - 0.296 * S - 15.8

#round the number to nearest integer
index = proper_round(index)

if index < 1:
    print("Before Grade 1")

elif index > 16:
    print("Grade 16+")

else:
    print(f"Grade {int(index)}")
