#   It's run with one command line argument (dictionary file of cuss words)
#   Asks for a string
#   Spits back the string with the words in dictionary censored with *
#
#
from cs50 import get_string
from sys import argv
import sys


def main():

    # accept one command line argument
    while True:
        if (len(argv) == 2):
            break
        print("Usage: python bleep.py dictionary")
        sys.exit(1)
        break

    inputFile = argv[1]

    # open dictionary
    infile = open(inputFile, 'r')
    words = []

    # Read all words and append to a list
    for line in infile:
        word = infile.readline()
        words.append(line[:-1])
        words.append(word[:-1])

    # Working on the user inputed string to censor
    sentence = get_string("What message would you like to censor?\n")
    sentence.lower()

    censorList = sentence.split()
    censorListCopy = sentence.lower().split()

    # iterating over banned words
    for i in range(len(words)):

        # iterating over words in string
        for j in range(len(censorListCopy)):

            if words[i] == censorListCopy[j]:

                # making a censored copy of the word
                copy = censorList[j]
                copyLength = len(copy)
                copy = ""
                print(f"copy: {copyLength}")

                # replace word with *
                for i in range(copyLength):
                    copy = copy + '*'

                censorList[j] = copy

    # print back sentence with censored words
    my_lst_str = " ".join(map(str, censorList))
    print(my_lst_str)


if __name__ == "__main__":
    main()