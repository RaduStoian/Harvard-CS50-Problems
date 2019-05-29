

#   split both string a and b into lists of substrings of length n
a = "#include <cs50.h>int main(void){    // get two strings    string s = get_string(" ");    string t = get_string(" ");    // compare strings' addresses    if (s == t)    {        printf("");    }    else    {        printf("");   }"
b = "#include <cs50.h>#include <stdio.h>int main(void){    // get two strings    char *s = get_string(" ");    char *t = get_string(" ");    // compare strings' addresses    if (s == t)    {        printf("");    }    else    {        printf("");    }}"
a = "foobar"
b = "foobar"
n = 6

compList = []

if a == b:
    compList.append(a)
else:

    aSub = []
    for i in range(len(a)):
        if len(a) >= n:
            aSub.append(a[i:(n+i)])



    bSub = []
    for i in range(len(b)):
        if len(a) >= n:
            bSub.append(b[i:(n+i)])


    # removing substrings smaller than n



    #   make a list of substrings that appear in both a and b


    for i in range(len(aSub)):

        for j in range(len(bSub)):

            if aSub[i] == bSub[j]:
                compList.append(aSub[i])


    #   return the list with no duplicates
    compList = list(dict.fromkeys(compList))
    compList = [x for x in compList if len(x) == n]

print(compList)




