import sys
from sys import argv
from csv import reader, DictReader

#a program that detects a person through matching a dna sequence with a dna database
#the programm use a csv file that contains dna data of some persons and ..
# a txt file which contains the DNA sequence

#check correct command line argument
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

#get the file path from the command line argument
csv_path = argv[1]
seq_path = argv[2]


# Opens csv file
with open(csv_path) as csvfile:
    readcsv = reader(csvfile)
    for row in readcsv:
        seq = row
        seq.pop(0) #remove the 1st item of each row
        break

#Dict so store the counting of str
STR = {}

#copy the STR(keys) to a dictionary
for item in seq:
    STR[item] = 1

# Opens the DNA sequence
with open(seq_path) as dnaSeq:
    dna_seq = reader(dnaSeq)
    for row in dna_seq:
      str_list = row

# store it in a string
dna = str_list[0]



#iterate over the STR of the database
for key in STR:
    key_len = len(key)
    maxCount = 0
    actualCount = 0

    for i in range(len(dna)):
        while actualCount > 0:
            actualCount -= 1
            continue

        # if the segment of dna corresponds to the key and there is a repetition of it we start counting
        if dna[i: i + key_len] == key:
            while dna[i - key_len: i] == dna[i: i + key_len]:
                actualCount += 1
                i += key_len

            # it compares the value to the previous longest sequence and if it is longer it overrides it
            if actualCount > maxCount:
                maxCount = actualCount

    # store the longest sequences of STR in the dictionary
    STR[key] += maxCount

# Opens csv file to iterate over the people
with open(csv_path, newline='') as csvfile:
    persons = DictReader(csvfile)
    for person in persons:
        match = 0
        # compares the STR to every person and print the matching results
        for dna in STR:
            if STR[dna] == int(person[dna]):
                match += 1
        if match == len(STR):
            print(person['name'])
            exit()

    print("No match")