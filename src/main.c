/*
 ============================================================================
 Name        : main.c
 Author      : Hesham Elnabtity
 Version     : Version 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "board/board.h"
#include "types/types.h"
#include "array_operations/arrays.h"

#define NUM_OF_SLOTS  (42U)

int main(void)
{
	column_t column = -1; // invalid column
	player_t player = PLAYER_ONE;
	game_state_t game_state = CONTINUE;
	int counter = 0;

	printf("---- WELCOME TO THE GAME ----\n\n");

	// initialize the game
	init_the_game();

//	do
//	{
//		printf("   -- Player %d --\n", player);
//		printf("Enter the column:");
//		fflush(stdout); // Flush the output buffer
//		scanf("%d", &column);
//		fflush(stdout); // Flush the output buffer
//		game_state = place_tokens(column, player);
//
//		if(game_state == CONTINUE)
//		{
//			counter++;
//			// Switch to the other player for the next turn
//			player = (player == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
//		}
//
//	}while(WIN != game_state && counter <= NUM_OF_SLOTS);
//
//	if (game_state == DRAW)
//	{
//		printf("The game is a draw!\n");
//	}
//}

	place_tokens(1, PLAYER_ONE);
	place_tokens(2, PLAYER_ONE);
	place_tokens(4, PLAYER_ONE);
	place_tokens(3, PLAYER_ONE);
}
