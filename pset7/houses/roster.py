import cs50
from sys import argv, exit

# Check number of comand-line arguments
if len(argv) != 2:
    print("Usage: python roster.py house")
    exit()

# Load roster from SQL database
db = cs50.SQL("sqlite:///students.db")
roster = db.execute("select * from students where house = ? order by last, first", argv[1])

# Iterate over roster
for student in roster:
    print(student['first'], end=" ")
    if student['middle'] == None:
        print("", end="")
    else:
        print(student['middle'], end=" ")
    print(student['last'] + f", born {student['birth']}")