from cs50 import get_int

# Get height
while True:
    h = get_int("Height: ")
    if 0 < h and h < 9:
        break

# print appropriate amount of spaces and hash signs
for i in range(h):
    print(" " * (h - i - 1) + "#" * (i + 1) + "  " + "#" * (i + 1))