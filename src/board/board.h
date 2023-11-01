#ifndef BOARD_BOARD_H_
#define BOARD_BOARD_H_

#include "../types/types.h"
#include "../array_operations/arrays.h"

//-------------------------------------------------------------------
// Definitions
//-------------------------------------------------------------------
#define WIN_LENGTH  		(3U)

//-------------------------------------------------------------------
// Public functions
//-------------------------------------------------------------------

/*
 * 	Initialize our board with zeros '0'
 *
 * */
void init_the_game(void);

/*
 * 	Place the tokens for the players
 *	return: game state CONTINUE , WIN, DRAW.
 *
 * */
game_state_t place_tokens(column_t column, player_t player);


//-------------------------------------------------------------------
// Private functions
//-------------------------------------------------------------------

/*
 * 	Check if the entered column by the user has empty location
 *
 * */
bool_t _is_valid_location(const column_t* real_column, row_t* return_real_row);

/*
 * 	Display the board after placing the tokens
 *
 * */
void _display_updated_game_board(void);

/*
 * 	Get the token of the given player
 *	return: token_t* token.
 * */

void _get_player_token(player_t player,token_t* token);

/*
 * 	Check if still any slots exists
 *
 * */

bool_t _check_for_any_empty_slots(void);

/*
 * Checks all the possible directions, which can lead to win
 *
 * */
bool_t _check_win(player_t player,const location_t* current_location);

bool_t _check_horizontal(player_t player,const location_t* current_location);

bool_t _check_horizontal_right(player_t player,const location_t* current_location);
bool_t _check_horizontal_left(player_t player,const location_t* current_location);

bool_t _check_vertical_down(player_t player,const location_t* current_location);

bool_t _check_diagonal_right_down(player_t player,const location_t* current_location);
bool_t _check_diagonal_right_up(player_t player,const location_t* current_location);

bool_t _check_diagonal_left_down(player_t player,const location_t* current_location);
bool_t _check_diagonal_left_up(player_t player,const location_t* current_location);


#endif /* BOARD_BOARD_H_ */
