#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //getting user input into height
    int height = get_int("Height:");
            
    while (height < 1 || height > 8)
    {
        height = get_int("Height:");
    }
   
    //printing pyramids
          
    //printing new lines
    for (int i = 0; i < height; i++) 
    {
    
        //print spaces
        for (int spaces = 1; spaces < height - i ; spaces++)
        {
            printf(" ");
        }
        //print hashes
        for (int hashes1 = 0; hashes1 <= i; hashes1++)
        {
            printf("#");
        }
           
        // print middle spaces 
        printf("  ");
            
            
        //print right hashes
        for (int hashes2 = 0; hashes2 <= i; hashes2++)
        {
            printf("#");
        }
          
        printf("\n");
    }

}
