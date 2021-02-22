import csv
import sys
from sys import argv
import re
from itertools import islice

#a function to slice the dna sequences
def split_by_n(seq, n):
    #A generator to divide a sequence into chunks of n units.
    while seq:
        yield seq[:n]
        seq = seq[n:]

#check correct command line argument
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

#get the file path from the command line argument
csv_path = argv[1]
seq_path = argv[2]

#open the csv file
with open(csv_path, newline='') as csvfile:
    readcsv = csv.reader(csvfile)

rows_csv = list(readcsv)

# for i in len(rows_csv):
#     print(rows_csv[i])


# #open the file of the dna sequence
with open(seq_path, 'r') as strfile:
    str_seq = strfile.read()

# STR = dict(AGATC=0, AATG=0, TATC=0)
# tmp = dict()



def longest_seq(aSeq, code):

    maxCount = 0
    actualCount = 0
    i = 0
    l = len(aSeq)
    code_len = len(code)

    while i < l:

        j = i + code_len

        if aSeq[i: j] in code:
            actualCount += 1
            if i <= len(aSeq) - code_len:
                i = j
        for k, v in STR():
            if k == code and actualCount > v:
                v = actualCount

            else:
                print(False)
            STR.update({code:9})
        else:
            i += 1

        if actualCount > maxCount:
            maxCount = actualCount

    return maxCount