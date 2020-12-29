from cs50 import get_int, get_string

# get user input as string
number = get_string("Number: ")

# Create list of integers
l = [int(n) for n in number]

# Create variable for sum
s = 0

# Every other digit starting with the second-to-last
for n in range(len(l) - 2, -1, -2):
    if 2 * l[n] > 9:
        s += int(str(l[n] * 2)[0]) + int(str(l[n] * 2)[1])
    else:
        s += 2 * l[n]

# Every other digit starting with last
for n in range(len(l) - 1, -1, -2):
    if l[n] > 9:
        s += int(str(l[n])[0]) + int(str(l[n])[1])
    else:
        s += l[n]

# Check if remainder is 0
if not s % 10:

    # Check for American Express
    if len(l) == 15 and l[0] == 3 and l[1] in [4, 7]:
        print("AMEX")

    # Check for MasterCard
    elif len(l) == 16 and l[0] == 5 and l[1] in [1, 2, 3, 4, 5]:
        print("MASTERCARD")

    # Check for Visa
    elif len(l) in [13, 16] and l[0] == 4:
        print("VISA")

    # Else invalid
    else:
        print("INVALID")

# Else it is invalid
else:
    print("INVALID")