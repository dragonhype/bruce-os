// Author: Spenser Desrochers, Josh Patnaude, Nicholas LaJoie
// ECE 477 - Lab 1 (Something Cool!)
// Date: February 1, 2017
// Description: Program takes a positive integer as a command line argument and largest prime factor.
// Note: Due to hardware constraints, numbers larger than 2^31 - 1 are rejected.

//! This is where you include various libraries used by your program.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define __STDC_FORMAT_MACROS

//! Function prototypes, so the compiler knows what other functions you wrote for your program!
uint64_t lpfactor(uint64_t x);

//! The begining of the main program, where it all begins!
int main(int argc, char * argv[])
{
    // Variable Declarations
    uint64_t input, result;

    // Verify command line argument is valid (make sure only one number is passed)
    if (argc != 2) {
        perror("Incorrect number of arguments passed!\n");
        return 1;
    }

    // Convert the command line argument from a string to an interger using a fancy function
    input = atoi(argv[1]);

    // Check to see if the number falls within a valid range
    if (input <= 0 || input >= 2147483648) {
        perror("Invalid input!\n");
        return 2;
    }

    // Calculate the largest prime factor by calling the function declared above main()
    result = lpfactor(input);

    // Print it to the console!
    printf("The largest prime factor of %"PRIu64" is %"PRIu64"!\n", input, result);

    return 0;
}

//! This is where the declared function is defined - it's an algorithm that calculates the largest
//  prime factor for the given number
uint64_t lpfactor(uint64_t x)
{
    uint64_t cdiv = 2;
    uint64_t ldiv;

    while (x != 1 || ((cdiv*cdiv) < x)) {
        if (x % cdiv == 0) {
            x /= cdiv;
            ldiv = cdiv;
        }
        else {
            cdiv++;
        }
    }
    return ldiv;
}
