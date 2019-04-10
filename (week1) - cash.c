#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //declaring variables for loops
    int i, j, k, l;
    
    // getting input
    float input = get_float("Change owed:");
    
    while (input < 0)
    {
        input = get_float("Change owed:");
    }
    
    //changing to integer
    int change = round(input * 100);
    
    //  i = number of 25c coins
    for (i = 0; change >= 25; i++)
    {
        change -= 25;
    }
    
    //  j = number of 10c coins
    for (j = 0; change >= 10; j++)
    {
        change -= 10;
    }
    
    //  k = number of 5c coins
    for (k = 0; change >= 5; k++)
    {
        change -= 5;
    }
    
    //  l = number of 1c coins
    for (l = 0; change >= 1; l++)
    {
        change -= 1;
    }
    
    int coins = i + j + k + l;
    
    printf("%i\n", coins);
}
