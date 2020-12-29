from cs50 import get_string

# Get user input
text = get_string("Text: ")

# Initialisa variables
letters = 0
words = 1
sentences = 0

# Iterate over characters in text and count elements
for c in text:
    if c.isalpha():
        letters += 1
    if c == " ":
        words += 1
    if c in ['.', '!', '?']:
        sentences += 1

# Coleman-Liau formmula
L = 100 * letters / words
S = 100 * sentences / words

index = round(0.0588 * L - 0.296 * S - 15.8)

# Output
if index >= 16:
    print("Grade 16+")
elif index <= 0:
    print("Before Grade 1")
else:
    print(f"Grade {index}")