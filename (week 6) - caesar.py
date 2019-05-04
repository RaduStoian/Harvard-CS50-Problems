#   Gets a key from user (integer)
#   Gets a string from user
#   Spits back out crypted string based on the key
#
#
from sys import argv
from cs50 import get_string
import sys

# get key as integer from command line arg
while True:
    if (len(argv) == 2) and (int(argv[1]) > 0):
        break
    print("Usage: python caesar.py k")
    sys.exit(1)
    break


key = int(argv[1])
plaintext = get_string("plaintext: ")

# make list to hold cyphertext
cyphertext = []

# iterate over plaintext chars
for i in plaintext:

    # append non alphabetic characters
    if not i.isalpha() == True:
        cyphertext.append(i)

    else:  # append and keep chars uppercase and in bounds
        if (ord(i) >= 65 and ord(i) <= 90) and ord(i) + key > 90:
            i = chr(((((ord(i) + key) - 65) % 26) + 65))
            cyphertext.append(i)

          # append and keep chars lowercase and in bounds
        elif (ord(i) >= 97 and ord(i) <= 122) and ord(i) + key > 122:
            i = chr(((((ord(i) + key) - 97) % 26) + 97))
            cyphertext.append(i)

        else:  # append all the rest letters
            cyphertext.append(chr((ord(i)+key)))

result = "".join(cyphertext)

print(f"ciphertext: {result}")