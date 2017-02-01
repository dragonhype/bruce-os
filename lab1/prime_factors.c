// Author: Spenser Desrochers, Josh Patnaude, Nicholas LaJoie
// ECE 477 - Lab 1 (Something Cool!) 
// Date: February 1, 2017 
// Description: Program takes a positive integer as a command line argument and largest prime factor.

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int lpfactor(int x);

int main(int argc, char * argv[])
{
    // Variable Declarations
    int input, result; 

    // Verify command line argument is valid
    if (argc != 2) {
        perror("Incorrect number of arguments passed!\n");
        return 1; 
    }
    input = atoi(argv[1]); 
    if (input <= 0) {
        perror("Invalid input!\n"); 
        return 2; 
    }

    // Calculate the largest prime factor 
    result = lpfactor(input); 
    printf("The largest prime factor of %d is %d!\n", input, result);


    return 0; 
}

int lpfactor(int x) 
{
    // Calculation code goes here 
}
