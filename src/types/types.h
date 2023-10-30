#ifndef TYPES_TYPES_H_
#define TYPES_TYPES_H_

typedef int column_t;
typedef int row_t;
typedef char board_t;
typedef char token_t;

typedef struct
{
	column_t col;
	row_t row;
}location_t;

typedef enum
{
	FALSE = 0,
	TRUE
}bool_t;

typedef enum
{
	CONTINUE = 0x10,
	WIN,
	DRAW,

	NONE
}game_state_t;

typedef enum
{
	PLAYER_ONE = 1,
	PLAYER_TWO
}player_t;

typedef enum
{
	COLUMN_ONE     = 1,
	COLUMN_TWO     = 2,
	COLUMN_THREE   = 3,
	COLUMN_FOUR    = 4,
	COLUMN_FIVE    = 5,
	COLUMN_SIX     = 6,
	COLUMN_SEVEN   = 7
}player_column_t;

typedef enum
{
	FIRST_COLUMN      = 0,
	LAST_COLUMN       = 6,
	FIRST_ROW         = 0,
	LAST_ROW          = 5,
	GAME_BOARD_ROWS   = 6,
	GAME_BOARD_COLUMS = 7
}board_dimensions_t;

#endif /* TYPES_TYPES_H_ */
