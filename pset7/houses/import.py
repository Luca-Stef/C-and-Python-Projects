from sys import argv, exit
import csv
import cs50

# Check command-line arguments
if len(argv) != 2:
    print("Usage: python import.py file.csv")
    exit()

db = cs50.SQL("sqlite:///students.db")

# Open csv file and insert rows in SQL database
with open(argv[1], 'r') as file:
    reader = csv.DictReader(file)
    for row in reader:
        # Insert NULL if there is no middle name
        if len(row['name'].split()) == 2:
            db.execute("insert into students (first, middle, last, house, birth) values (?, NULL, ?, ?, ?)",
                       row['name'].split()[0], row['name'].split()[1], row['house'], row['birth'])
        else:
            db.execute("insert into students (first, middle, last, house, birth) values (?, ?, ?, ?, ?)",
                       row['name'].split()[0], row['name'].split()[1], row['name'].split()[2], row['house'], row['birth'])
