import sys
import csv


#Creates some helping buffer lists
results = []
rowbuffer = []

# Opens the DNA sequence
inputseq = open(sys.argv[2], "r")
bufferstorage = inputseq.read()

# Opens csv file
with open(sys.argv[1], newline='') as database:
    readfile = csv.reader(database)

# Gets accsess to STR names
    rows = list(readfile)
    titles = rows[0]

# Checks and counts STRs in DNA sequence
    for strname in titles[1:]:
        counter = 1
        n = 0
        check = False

        while n in range(len(bufferstorage)):
            x = bufferstorage.count(strname, n, n + len(strname))
            if x > 0 and check == False:
                n = n + len(strname)
                check = True
            elif x > 0 and check == True:
                counter += 1
                n = n + len(strname)
            else:
                n += 1
                check = False
        results.append(str(counter))

# Some temporary check of code work
    print(results)
    print()

# Checks if STRs match with data in csv file
with open(sys.argv[1], newline='') as database:
    checkreadfile = csv.reader(database)

    for rows in checkreadfile:
        rowbuffer.append(rows)

    matchcheck = False

    for line in rowbuffer[1:]:
        line[1:].sort
        results.sort
        if line[1:] == results:
            print(line[0])
            matchcheck = True

    if matchcheck == False:
        print('No match.')

inputseq.close()
