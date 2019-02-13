#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{    
    // only accepts 1 arguments
    if (argc != 2)
    {
        printf("Usage ./caesar key\n");
        return 1;
    }
    else     
    {  
        // checks to see if each character is a digit
        for (int i = 0, n = strlen(argv[1]) ; i < n; i++) 
        {
          
            if (!isdigit(argv[1][i]))
            {
                printf("Usage ./caesar key\n"); 
                return 1;
            }
        }
        
        // if only 1 argument and all chars are digits, convert to int and print
        int inputKey = atoi(argv[1]);
        
        //getting input string from user
        string input = get_string("plaintext: ");
        
        // running through inputed string
        for (int i = 0; i < strlen(input); i++)
        {
            //if char is not letter, then leave the same
            if (!isalpha(input[i]))
            {
               
            }
            else
            {    
                //if letter is going out of bounds,     
                if ((input[i] >= 65 && input[i] <= 90) && input[i] + inputKey > 90)
                    
                {
                    //wrap back around.
                    int distance = 90 - input[i];
                    int remainingKey = inputKey - distance;
                    input[i] = 64 + remainingKey;                                                     
                }
      
                //if letter is going out of bounds, 
                else if ((input[i] >= 97 && input[i] <= 122) && input[i] + inputKey > 122)
                    
                {
                    //wrap back around.
                    int distance = 122 - input[i];
                    int remainingKey = inputKey - distance;
                    input[i] = 97 + remainingKey;            
                }
                
                else
                    
                {
                    input[i] += inputKey; 
                }
                    
           
            
            }
        }   
       
        
        printf("ciphertext: %s\n", input); 
        return 0;
    }
}

