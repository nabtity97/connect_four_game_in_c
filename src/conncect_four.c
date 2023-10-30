/*
 ============================================================================
 Name        : conncect_four.c
 Author      : Hesham Elnabtity
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "board.h"

#define NUM_OF_SLOTS  (42U)

int main(void) {

	printf(" WELCOME TO THE GAME\n");
	init_the_game();

	// PLAYER_TWO
	player_t player = PLAYER_ONE;


	place_tokens(COLUMN_ONE, PLAYER_ONE);

	place_tokens(COLUMN_TWO, PLAYER_ONE);
	place_tokens(COLUMN_TWO, PLAYER_ONE);
	place_tokens(COLUMN_TWO, PLAYER_TWO);
	place_tokens(COLUMN_TWO, PLAYER_TWO);

	place_tokens(COLUMN_THREE, PLAYER_ONE);
	place_tokens(COLUMN_THREE, PLAYER_ONE);
	place_tokens(COLUMN_THREE, PLAYER_ONE);

	place_tokens(COLUMN_FOUR, PLAYER_TWO);
	place_tokens(COLUMN_FOUR, PLAYER_TWO);
	place_tokens(COLUMN_FOUR, PLAYER_TWO);
	place_tokens(COLUMN_FOUR, PLAYER_ONE);


	return EXIT_SUCCESS;
}
