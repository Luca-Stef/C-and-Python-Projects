import csv
from sys import argv, exit

# Check number of command-line arguments
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit()

# Read in database and relevant Short Tandem Repeats
with open(argv[1]) as file:
    reader = csv.DictReader(file)
    data = [dict(row) for row in reader]
    STRs = {STR: 0 for STR in list(data[0].keys())[1:]}

# Convert STR values from strings to integers in data
for persn in data:
    for STR in STRs:
        persn[STR] = int(persn[STR])

# Read in sequence to be analysed
with open(argv[2]) as file:
    sequence = file.read().rstrip()

# Search for every STR in the given sequence
for STR in STRs.keys():
    for i in range(1 + len(sequence) - len(STR)):
        if sequence[i:i + len(STR)] == STR:

            # After matching STR, iterate over sequence in steps of len(STR) and keep checking if sequence matches
            for j in range(i + len(STR), 1 + len(sequence) - len(STR), len(STR)):

                # Only overwrite value in STR dictionary if it is the maximmum number of STRs
                if sequence[j:j + len(STR)] == STR:
                    if (j - i) / len(STR) > STRs[STR]:
                        STRs[STR] = int((j - i) / len(STR))

                # Don't care if the next match is not consecutive
                else:
                    break

# Check if all STRs match
for persn in data:
    if list(STRs.values()) == list(persn.values())[1:]:
        print(persn['name'])
        exit()

# Otherwise no match
print("No match")