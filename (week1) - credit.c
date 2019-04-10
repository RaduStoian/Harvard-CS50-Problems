#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //getting input
    long input = get_long("Number:");

    
    //defining card variable
    string card = 0;
    
    // checking for visa
    if ((input > 4000000000000 && input < 4999999999999) || (input > 4000000000000000 && input < 4999999999999999))
    {
        card = "VISA";
    }
    
    //checking American Express
    else if ((input > 340000000000000 && input < 349999999999999) || (input > 370000000000000 && input < 379999999999999))
    {
        card = "AMEX";
    }
    
    //checking Mastercard
    else if (input > 5100000000000000 && input < 5599999999999999)
    {
        card = "MASTERCARD";
    }
   
    // Else it is invalid
    else 
    { 
        card = "INVALID";
    }
    
    // getting the first set of numbers and multiplying the numbers with 2
    int check1 = ((input % 100) / 10) * 2;
    int check2 = ((input % 10000) / 1000) * 2;
    int check3 = ((input % 1000000) / 100000) * 2;
    int check4 = ((input % 100000000) / 10000000) * 2;
    int check5 = ((input % 10000000000) / 1000000000) * 2;
    int check6 = ((input % 1000000000000) / 100000000000) * 2;
    int check7 = ((input % 100000000000000) / 10000000000000) * 2;
    int check8 = ((input % 10000000000000000) / 1000000000000000) * 2;
    int check9 = ((input % 1000000000000000000) / 100000000000000000) * 2;
    
    // getting each digit of first set of numbers
    int check11 = check1 % 10;
    int check12 = check1 / 10;  
    int check21 = check2 % 10;
    int check22 = check2 / 10;  
    int check31 = check3 % 10;
    int check32 = check3 / 10;  
    int check41 = check4 % 10;
    int check42 = check4 / 10;   
    int check51 = check5 % 10;
    int check52 = check5 / 10;   
    int check61 = check6 % 10;
    int check62 = check6 / 10;  
    int check71 = check7 % 10;
    int check72 = check7 / 10;  
    int check81 = check8 % 10;
    int check82 = check8 / 10;  
    int check91 = check9 % 10;
    int check92 = check9 / 10;
     
    // getting first checksum
    int checksum1 = check11 + check12 + check21 + check22 + check31 + check32 + check41 + check42 + check51 + check52 + check61 + 
                    check62 + check71 + check72 + check81 + check82 + check91 + check92;
    
    // getting the second set of numbers 
    int num1 = (input % 10);
    int num2 = (input % 1000) / 100;
    int num3 = (input % 100000) / 10000;
    int num4 = (input % 10000000) / 1000000;
    int num5 = (input % 1000000000) / 100000000;
    int num6 = (input % 100000000000) / 10000000000;
    int num7 = (input % 10000000000000) / 1000000000000;
    int num8 = (input % 1000000000000000) / 100000000000000;
    int num9 = (input % 100000000000000000) / 10000000000000000; 


    //getting the second checksum
    int checksum2 = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9;

    //adding them together to get the last number
    int checksum3 = checksum1 + checksum2;
    
    // if at the end, the number does not end in 0, the card is invalid
    if (checksum3 % 10 != 0) 
    {
        card = "INVALID";
    }
    
    printf("%s\n", card);
}
