// Author: Spenser Desrochers, Josh Patnaude, Nicholas LaJoie
// ECE 477 - Lab 2
// Date: February 10, 2017
// Description: Implentation file for Tic-Tac-Toe program.

#include <stdlib.h>
#include "tictac.h"

char equalnumXO(const int TTT[3][3],char *numx,char *numy);
char xwins(const int TTT[3][3]);
char owins(const int TTT[3][3]);
// Implementation of functions

// Test the tic-tac-toe board in question
// Return true if board is valid and what type of validity
// 1 - game in progress
// 2 - x wins
// 3 - o wins
// 4 - game is a draw
char test_board(const int TTT[3][3])
{
	char numx=0,numy=0, xwin=0, owin=0;
// Function checks each state in this order:
    // --> At all points, there need to be an equal number of X's and O's, or 1 // more X than O (so, let's check this first)
	if(!equalnumXO(&TTT,&numx,&numy)) return 0;
    // --> NOTE: If one more X than O, go down one path where X could win, otherwise, go down path where O could win
	if (numx<3) return 1; // Check if there are fewer than 3 X's, if so, game in progress
	xwin = xwins(&TTT); // Check if xwins
	owin = owins(&TTT); // Check if owins
	if (numx==5 && !xwin && !owin) return 4; // If the board is full and no winner the game is a draw
	
	if(numx!=numy)){
		if (owin==1) return 0; // o can't win with more x's
		if (xwin==1) return 2; // x wins
	} else {
		if (xwin==1) return 0; // x can't win with equal o's
		if (owin==1) return 3; // o wins
	}
	return 1; // game in progress
}

char equalnumXO(const int TTT[3][3],char *numx,char *numy)
{
	int i=0,j=0;
	
	// Loop through the board
	for(i=0;i<3;i++){
		for(i=0;i<3;i++){
			if (TTT[i][j]==1) *numx++;	// Found an x
			else if (TTT[i][j]==2) *numy++; // Found a y
		}
	}
	
	// Make sure they are equal or x has one more
	if(*numx==*numy || *numx==*numy+1) return 1;
	// invalid board if not
	return 0;
}

char xwins(const int TTT[3][3])
{
	int i=0;
	// Check rows
	for(i=0;i<3;i++){
		if (TTT[i][1]==1 && TTT[i][2]==1 && TTT[i][3]=1) return 1;
	}
	// Check columns
	for(i=0;i<3;i++){
		if (TTT[1][i]==1 && TTT[2][i]==1 && TTT[3][i]=1) return 1;
	}
	// Check diagonals
	if (TTT[1][1]==1 && TTT[2][2]==1 && TTT[3][3]=1) return 1;
	if (TTT[3][1]==1 && TTT[2][2]==1 && TTT[1][3]=1) return 1;
	
	return 0; // x did not win
}
char owins(const int TTT[3][3])
{
		int i=0;
	// Check rows
	for(i=0;i<3;i++){
		if (TTT[i][1]==2 && TTT[i][2]==2 && TTT[i][3]=2) return 1;
	}
	// Check columns
	for(i=0;i<3;i++){
		if (TTT[1][i]==2 && TTT[2][i]==2 && TTT[3][i]=2) return 1;
	}
	// Check diagonals
	if (TTT[1][1]==2 && TTT[2][2]==2 && TTT[3][3]=2) return 1;
	if (TTT[3][1]==2 && TTT[2][2]==2 && TTT[1][3]=2) return 1;
	
	return 0; // o did not win
}
