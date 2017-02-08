// Author: Spenser Desrochers, Josh Patnaude, Nicholas LaJoie
// ECE 477 - Lab 2
// Date: February 10, 2017
// Description: Main program that determines the following tic-tac-toe stats:
  // 1. Game in Progress
  // 2. X Wins
  // 3. O Wins
  // 4. No Winner
    // It'll also output total number of valid combinations

#include <stdio.h>
#include <stdlib.h>
// #include "tictac.h"

#define LIMIT 19683
// Receives command line argument to write to that file - CSV file (or to terminal otherwise)

// Function prototypes
void print_board(int ttt[3][3]);
void print_string(int ttt[3][3]);

int main(int argc, char * argv[])
{
  // Variable Declarations
  int TTT[3][3];  // The tic-tac-toe board in question
  int x, row, col, total;  // Counter variables

  // Determine Output
  if (argc == 1) {
    // Output to the command line
  }
  else if (argc == 2) {
    // Determine if valid file/path/.CSV
    // If so, determine if it already exists or create a new one
  }
  else {
    perror("Invalid arguments passed.\n");
    return 1;
  }

  // Function that returns all possible legal states that can be passed to the output

  // For loop that iterates in trinary up to 3^9 = 19683
  for (x = 0; x < LIMIT; x++) {
	total = x; 
	for (row = 2; row >= 0; row--) {
		for (col = 2; col >= 0; col--) {
			TTT[row][col] = total%3;
			total /= 3;
		}
	}
	print_board(TTT);
	printf("\n");
	print_string(TTT);
	printf("\n"); 
  } 
  /*for (i = 0; i < 3; i++) {
    for (j = 0; j < 3 ; j++) {
      TTT[i][j] = j;
    }
  }*/

  // Test print:
  // print_board(TTT);
  // print_string(TTT);

  return 0;

  // Function that checks each state in this order:
    // --> At all points, there need to be an equal number of X's and O's, or 1 // more X than O (so, let's check this first)
    // --> NOTE: If one more X than O, go down one path where X could win, otherwise, go down path where O could win
      // --> If this isn't the case, invalid board
      // --> If this passes, check if there are fewer than 3 X's, if so, game in progress
      // --> Else if there are fewer than 6 X's, determine if there's a winner
        // --> Apply winning masks
        // --> If none of these pass, no winner
        // --> Otherwise, winner! (X or O)
      // --> Else, if there are great than 5 X's, invalid board
}

// Function definitions
void print_board(int ttt[3][3]) {
  int x, y;
  for (x = 0; x < 3; x++) {
    for (y = 0; y < 3; y++) {
      printf("%d ", ttt[x][y]);
    }
    printf("\n");
  }
}
void print_string(int ttt[3][3]) {
  int x, y;
  for (x = 0; x < 3; x++) {
    for (y = 0; y < 3; y++) {
      printf("%d,", ttt[x][y]);
    }
  }
  printf("\n");
}
