#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

 
int main(int argc, string argv[])
{    
    
    // only accepts 1 arguments
    if (argc != 2)
    {
        printf("Usage ./vigenere keyword\n");
        return 1;
    }
    else     
    {                         
        // checks to see if each character is a letter
        for (int i = 0, n = strlen(argv[1]) ; i < n; i++) 
        {
          
            if (!isalpha(argv[1][i]))
            {
                printf("Usage ./vigenere keyword\n"); 
                return 1;
            }
        }  
    }
    
    


    string keyword = argv[1];
    int keywordLength = strlen(keyword);
           
    
    // Changing keyword
    for (int i = 0; i < keywordLength; i++)
    {
        
        if (keyword[i] >= 97 && keyword[i] <= 122)
        {
            keyword[i] = keyword[i] - 97;
        }
        else if (keyword[i] >= 65 && keyword[i] <= 90)
        {
            keyword[i] = keyword[i] - 65;
        }
        else 
        {
            
        }
    }
    
    
    // get plaintext 
    string plaintext = get_string("plaintext: ");
    int plaintextLength = strlen(plaintext);
     
    
    int k = 0;
    // iterating through plaintext
    for (int j = 0; j < plaintextLength ; j++) 
    {    
        // leave !letters the same
        if (!isalpha(plaintext[j])) 
        {
            
        }
        
        // Continue the rest here
        else 
        {
        
            // for repeating the K 
            
            if (k >= keywordLength)
            {
                k = 0;
                if (islower(plaintext[j]))
                {
                    plaintext[j] = (((plaintext[j] + keyword[k]) - 97) % 26) + 97;
                }    
                else if (isupper(plaintext[j]))
                {
                    plaintext[j] = (((plaintext[j] + keyword[k]) - 65) % 26) + 65;
                }   

                k++;
            }
            
            // for repeating the keyword

            else if (j >= keywordLength)
            {
                if (islower(plaintext[j]))
                {
                    plaintext[j] = (((plaintext[j] + keyword[k]) - 97) % 26) + 97;
                }    
                else if (isupper(plaintext[j]))
                {
                    plaintext[j] = (((plaintext[j] + keyword[k]) - 65) % 26) + 65;
                }   

                k++;
            }
            
           
            
            // if keyword is long enough
            else if (islower(plaintext[j]))
            {
                plaintext[j] = (((plaintext[j] + keyword[j]) - 97) % 26) + 97;
            }    
            else if (isupper(plaintext[j]))
            {
                plaintext[j] = (((plaintext[j] + keyword[j]) - 65) % 26) + 65;
            }                                                                     
        }           
    }
    printf("ciphertext: %s\n", plaintext);
}
