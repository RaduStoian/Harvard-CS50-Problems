from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""

    #   split each string into lines                                         https://docs.python.org/3/library/stdtypes.html#string-methods.
    aLines = a.split(sep='\n', maxsplit=-1)
    bLines = b.split(sep='\n', maxsplit=-1)

    compList = []

    #   compare each line from string a with lines from string b             https://docs.python.org/3/tutorial/datastructures.html
    for i in range(len(aLines)):

        for j in range(len(bLines)):

            if aLines[i] == bLines[j]:
                compList.append(aLines[i])

    #   return a list of lines that appear in both without duplicates
    compList = list(dict.fromkeys(compList))
    return compList


def sentences(a, b):
    """Return sentences in both a and b"""

    # split strings into sentences
    aSent = sent_tokenize(a)
    bSent = sent_tokenize(b)

    compList = []

    # make a list of sentences that appear in both a and b
    for i in range(len(aSent)):

        for j in range(len(bSent)):

            if aSent[i] == bSent[j]:
                compList.append(aSent[i])


#   return a list of sentences that appear in both without duplicates
    compList = list(dict.fromkeys(compList))

    return compList


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    compList = []

    if (a == b):
        for i in range(len(a)):
            compList.append(a[i:(n+i)])

    else:

        #   split both string a and b into lists of substrings of length n
        aSub = []
        for i in range(len(a)):
            if len(a) > n:
                aSub.append(a[i:(n+i)])

        bSub = []
        for i in range(len(b)):
            if len(a) > n:
                bSub.append(b[i:(n+i)])

        #   make a list of substrings that appear in both a and b

        for i in range(len(aSub)):

            for j in range(len(bSub)):

                if aSub[i] == bSub[j]:
                    compList.append(aSub[i])

    #   return the list with no duplicates
    compList = list(dict.fromkeys(compList))
    compList = [x for x in compList if len(x) == n]

    return compList