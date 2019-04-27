// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];





// Hash function
unsigned int hash(const char *word)
{
    int letter = tolower(word[0]) - 'a';
    return letter;
}





// Loads dictionary into memory, returning true if successful else false-----------------LOAD LOAD LOAD LOAD LOAD LOAD LOAD LOAD LOAD LOAD LOAD LOAD LOAD LOAD LOAD LOAD LOAD LOAD
bool load(const char *dictionary)
{



    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }





    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }





    char word[LENGTH + 1];

    // Read words from file
    while (fscanf(file, "%s", word) != EOF)
    {

        // make node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        // put word in node
        strcpy(new_node -> word, word);

        // hash word into an int
        int hashedWord = hash(word);

        // put node in the right bucket
        for (int i = 0; i < N; i++)
        {
            if (i == hashedWord)
            {
                new_node->next = hashtable[i];
                hashtable[i] = new_node;
            }
        }


    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}





// Returns number of words in dictionary if loaded else 0 if not yet loaded-------------------SIZE SIZE SIZE SIZE SIZE SIZE SIZE SIZE SIZE SIZE SIZE SIZE SIZE SIZE SIZE
unsigned int size(void)
{

    int totalWords = 0;

    // loop through all buckets
    for (int i = 0; i < N; i++)
    {

        node *cursor = hashtable[i];

        // loop through all nodes in bucket
        while (cursor != NULL)
        {

            //stop if words are too big (shows error happened when loading dictionary)
            if ((strlen(cursor->word)) > LENGTH + 1)
            {
                printf("Size error: word bigger than LENGTH");
                return 4;
            }

            // keep count of all nodes
            totalWords++;
            cursor = cursor->next;
        }
    }

    return totalWords;

}







// Returns true if word is in dictionary ------------- CHECK CHECK CHECK CHECK CHECK CHECK CHECK CHECK CHECK CHECK CHECK CHECK CHECK CHECK CHECK CHECK CHECK CHECK
bool check(const char *word)
{


    // hash text word into an int
    int hashedWord = hash(word);


    // create a cursor to point in the right bucket
    node *cursor = hashtable[hashedWord];



    // loop through the nodes in bucket
    while (cursor != NULL)
    {

        // compare strings and move to next node
        int foundWord = strcasecmp(word, cursor->word);
        cursor = cursor->next;

        if (foundWord == 0)
        {
            return true;
        }

    }

    return false;
}









// Unloads dictionary from memory, returning true if successful else false ------------ UNLOAD UNLOAD UNLOAD UNLOAD UNLOAD UNLOAD UNLOAD UNLOAD UNLOAD UNLOAD UNLOAD UNLOAD UNLOAD UNLOAD UNLOAD
bool unload(void)
{


    // loop through all buckets
    for (int i = 0; i < N; i++)
    {
        // find good bucket
        node *cursor = hashtable[i];

        // loop through all nodes in bucket
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

        // free the node pointing at
        free(cursor);
    }



    return true;
}
