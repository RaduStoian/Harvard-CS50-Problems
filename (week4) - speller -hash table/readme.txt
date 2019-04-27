Spell Checker

Load = loads a dictionary into memory by using a hashtable
Size = iterates through all the buckets and nodes to count all nodes (words)
Check = checks each word of a given text file against the words in the hashtable
Unload = iterates through all the buckets and nodes in the hashtable and frees all memory.

Input = 1 dictionary file and 1 file to spell check

Output = ex: 
for the file lalaland.txt
	WORDS MISSPELLED:     955

	WORDS IN DICTIONARY:  143091

	WORDS IN TEXT:        17756

	TIME IN load:         0.04

	TIME IN check:        1.24

	TIME IN size:         0.00

	TIME IN unload:       0.00

	TIME IN TOTAL:        1.29



Program has 3 files: 

dictionary.h - contains mostly function prototypes and cons
dictionary.c - contains the load, size, check and unload functions
speller.c - contains the main part of the program and the benchmarking method