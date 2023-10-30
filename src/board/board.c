#include "board.h"

static board_t _connect_four_arr[GAME_BOARD_ROWS][GAME_BOARD_COLUMS];

//-------------------------------------------------------------------
// Public functions
//-------------------------------------------------------------------
void init_the_game(void)
{
	for(int i = 0; i < GAME_BOARD_ROWS; i++)
	{
		for(int j = 0; j < GAME_BOARD_COLUMS; j++)
		{
			_connect_four_arr[i][j] = ' ';
		}
	}
	_display_updated_game_board();
}
//-------------------------------------------------------------------
game_state_t place_tokens(column_t column, player_t player)
{
	column_t real_column = column - 1;
	row_t real_row = -1; // will be updated by _is_valid_location()

	if(FALSE == _is_valid_location(&real_column, &real_row))
	{
		printf("Invalid column\n");

		// then display the last version of the game.
		_display_updated_game_board();

		return CONTINUE;
	}

	// to determine the token of the player
	token_t token = ' ';

	// get the token of the player
	_get_player_token(player,&token);

	// update the location with the player's token
	_connect_four_arr[real_row][real_column] = token;

	// display the board after updating the location
	_display_updated_game_board();

	// real current location
	location_t current_location = {.col = real_column, .row = real_row};

	if(TRUE == _check_win(player, &current_location))
	{
		printf("------------GAME ENDED---------------\n");
		return WIN;
	}

	if(FALSE == _check_for_any_empty_slots())
	{
		printf(" the game board is full");
		return DRAW;
	}

	return CONTINUE;
}
//-------------------------------------------------------------------
// Private functions
//-------------------------------------------------------------------
bool_t _is_valid_location(const column_t* real_column, row_t* return_real_row)
{
	if(*real_column < 0 || *real_column > GAME_BOARD_COLUMS-1)
	{
		printf("wrong column input\n");
		// check if the column is out of the bounds
		return FALSE;
	}

    for (int row = GAME_BOARD_ROWS-1/*5*/ ; row >= 0; row--)
    {
        if (_connect_four_arr[row][*real_column] == ' ')
        {

        	// return the real row number, so we can place the token in the correct place.
        	*return_real_row = row;

            // Found an empty spot in the specified column.
            return TRUE;
        }
    }

    // Column is full, not a valid location to place a token
    printf("column is full\n");
    return FALSE;
}
//-------------------------------------------------------------------
void _display_updated_game_board(void)
{
	for(int i = 0; i < GAME_BOARD_ROWS; i++)
	{
		for(int j = 0; j < GAME_BOARD_COLUMS; j++)
		{
			printf("| %c ", _connect_four_arr[i][j]);
		}
		printf("|\n");
		printf("-----------------------------");
		printf("\n");
	}
	printf("  1   2   3   4   5   6   7\n");
}
//-------------------------------------------------------------------
void _get_player_token(player_t player,token_t* token)
{
	switch(player)
	{
		case PLAYER_ONE:
		{
			*token = 'x';
			break;
		}
		case PLAYER_TWO:
		{
			*token = 'o';
			break;
		}
		default:
		{
			// should not be here
			*token = ' ';
			break;
		}
	}
}
//-------------------------------------------------------------------
bool_t _check_win(player_t player,const location_t* current_location)
{
    return (_check_horizontal_right(player, current_location) 	||
    		_check_horizontal_left(player, current_location) 	||
			_check_vertical_down(player, current_location)    	||
			_check_diagonal_right_down(player, current_location) ||
			_check_diagonal_right_up(player, current_location) 	||
			_check_diagonal_left_down(player, current_location)  ||
			_check_diagonal_left_up(player, current_location));
}
//-------------------------------------------------------------------
bool_t _check_horizontal_right(player_t player,const location_t* current_location)
{
	// our of boundaries
	if(current_location->col + WIN_LENGTH > LAST_COLUMN)
		return FALSE;

	// will be updated with the corresponding token of hte player
	token_t token;
	_get_player_token(player,&token);

	// check the right hand side
	for(int i = 1; i <= WIN_LENGTH; i++)
	{
		if(_connect_four_arr[current_location->row][current_location->col + i] != token)
		{
			return FALSE;
		}
	}
	printf(" horizontal check right is true\n");
	return TRUE;
}
//-------------------------------------------------------------------
bool_t _check_horizontal_left(player_t player,const location_t* current_location)
{
	// out of boundaries
	if(current_location->col - WIN_LENGTH < FIRST_COLUMN)
		return FALSE;

	// will be updated with the corresponding token of hte player
	token_t token;
	_get_player_token(player,&token);

	// check the right hand side
	for(int i = 1; i <= WIN_LENGTH; i++)
	{
		if(_connect_four_arr[current_location->row][current_location->col - i] != token)
		{
			return FALSE;
		}
	}
	printf(" horizontal check left is true\n");
	return TRUE;
}
//-------------------------------------------------------------------
bool_t _check_vertical_down(player_t player,const location_t* current_location)
{
	// out of boundaries
	if(current_location->row + WIN_LENGTH > LAST_ROW)
		return FALSE;

	// will be updated with the corresponding token of hte player
	token_t token;
	_get_player_token(player,&token);

	// check the right hand side
	for(int i = 1; i <= WIN_LENGTH; i++)
	{
		if(_connect_four_arr[current_location->row + i][current_location->col] != token)
		{
			return FALSE;
		}
	}
	printf(" vertical check down is true\n");
	return TRUE;
}
//-------------------------------------------------------------------
bool_t _check_diagonal_right_down(player_t player,const location_t* current_location)
{
	// out of boundaries
	if(current_location->col + WIN_LENGTH > LAST_COLUMN)
		return FALSE;

	// will be updated with the corresponding token of hte player
	token_t token;
	_get_player_token(player,&token);

	// check the right hand side
	for(int i = 1; i <= WIN_LENGTH; i++)
	{
		if(_connect_four_arr[current_location->row + i][current_location->col + i] != token)
		{
			return FALSE;
		}
	}
	printf(" diagonal right down check is true\n");
	return TRUE;
}
//-------------------------------------------------------------------
bool_t _check_diagonal_right_up(player_t player,const location_t* current_location)
{
	// out of boundaries
	if(current_location->col + WIN_LENGTH > LAST_COLUMN)
		return FALSE;

	if(current_location->row - WIN_LENGTH < FIRST_ROW)
		return FALSE;

	// will be updated with the corresponding token of hte player
	token_t token;
	_get_player_token(player,&token);

	// check the right hand side
	for(int i = 1; i <= WIN_LENGTH; i++)
	{
		if(_connect_four_arr[current_location->row - i][current_location->col + i] != token)
		{
			return FALSE;
		}
	}
	printf(" diagonal right up check is true\n");
	return TRUE;
}
//-------------------------------------------------------------------
bool_t _check_diagonal_left_up(player_t player,const location_t* current_location)
{
	// out of boundaries
	if(current_location->col - WIN_LENGTH < FIRST_COLUMN)
		return FALSE;

	if(current_location->row - WIN_LENGTH < FIRST_ROW)
		return FALSE;

	// will be updated with the corresponding token of hte player
	token_t token;
	_get_player_token(player,&token);

	// check the right hand side
	for(int i = 1; i <= WIN_LENGTH; i++)
	{
		if(_connect_four_arr[current_location->row - i][current_location->col - i] != token)
		{
			return FALSE;
		}
	}
	printf(" diagonal left up check is true\n");
	return TRUE;
}
//-------------------------------------------------------------------
bool_t _check_diagonal_left_down(player_t player,const location_t* current_location)
{
	// out of boundaries
	if(current_location->col - WIN_LENGTH < FIRST_COLUMN)
		return FALSE;

	if(current_location->row + WIN_LENGTH > LAST_ROW)
		return FALSE;

	// will be updated with the corresponding token of hte player
	token_t token;
	_get_player_token(player,&token);

	// check the right hand side
	for(int i = 1; i <= WIN_LENGTH; i++)
	{
		if(_connect_four_arr[current_location->row + i][current_location->col - i] != token)
		{
			return FALSE;
		}
	}
	printf(" diagonal left down check is true\n");
	return TRUE;
}
//-------------------------------------------------------------------
bool_t _check_for_any_empty_slots(void)
{
	for(int i = 0; i < GAME_BOARD_ROWS-1 ; i++)
	{
		for(int j = 0; j < GAME_BOARD_COLUMS-1; j++)
		{
			if(_connect_four_arr[i][j] == ' ')
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}
