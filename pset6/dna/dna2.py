import sys
from sys import argv
import csv

#check correct command line argument
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

#get the file path from the command line argument
csv_path = argv[1]
seq_path = argv[2]


# Opens csv file
with open(csv_path, newline='') as csvfile:
    readcsv = csv.reader(csvfile)

# Gets accsess to STR names
    csv_rows = list(readcsv)
    str_names = csv_rows[0]

# Opens the DNA sequence
seqtxt = open(seq_path, "r")
str_seq = seqtxt.read()

#Dict so store the counting of str
STR_max = {}

#iterate over the STR of the database
for str_name in str_names[1:]:
    maxCount = 0
    actualCount = 0
    str_name_len = len(str_name)
    str_seq_len = len(str_seq)
    i = 0
    found = False

    #iterate over the DNA Seq and count the str_name
    while i < str_seq_len:
        #find the STR in range of str_name[i : i+str_name_len]
        find = str_seq.count(str_names, i, i + str_name_len)

        #if the 1st STR found then start counting from it
        if find > 0 and found == False:
            actualCount = 1
            i = i + str_name_len
            found = True

        #if another STR is found again next to the previous one
        elif find > 0 and found == True:
            actualCount += 1
            i = i + str_name_len

        else:
            i += 1
            found = False

        if actualCount > maxCount:
            maxCount = actualCount


    #adding the STR and its maxCount to a buffer dict
    STR_max[str_name] = maxCount

#for each kmer in STR_max we need to know the csv column it corresponds to
# returns { "AGATC": 1, "AATG": 2,...}
def kmer_to_column_map():
    with open(csv_path) as csv:
        for line in csv:
            return { kmer: i for i, kmer in enumerate(line.strip().split(",")) }

#Then we need to get the column data from the csv file.
#Write a helper function that extracts a column from the csv file
#make a function to extract a column of values from the csv file

#returns the list of values from a column given an index
def get_csv_column( column_index ):
    column = []
    with open(csv_path) as csv:
        for i, line in enumerate(csv):
            if i == 0: continue
            column.append( line.strip().split(",")[column_index] )
    return column

#now we lets grab what we need to iterate through kmers and print the names
#STR_max = {'AATG': 8 , 'TATC': 10 , 'AGATC': 9 , 'AGAG': 13}
names = get_csv_column(0)

for kmer, value in STR_max.items():
    # don't print if there is no data in csv file with this kmer
    if kmer not in kmer_to_column_map(): continue

    #get the column number in the csv file for this kmer
    column_index = STR_max[kmer]

    #get the column data for this kmer - note that names and values have the same indices.
    values = get_csv_column( column_index )

    #find the column values that are equal to STR_max value - i is the index of the value that matches which will be the index in names of the name that matches
    matches = [ i for i, patientval in enumerate( values ) if value == int(patientval)]

    #print the name of the person for each match -
    if matches:
        print( kmer )
        for match in matches:
            print( f"-> {names[match]}" )
        print()