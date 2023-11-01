#include "arrays.h"

bool_t _check_for_four_consecutive_tokens(bool_t* array, int size)
{
	int counter = 0;
	for(int i = 0; i < size; i++)
	{
		if(TRUE == array[i])
		{
			counter++;

			if(4 == counter)
			{
				return TRUE;
			}
		}
		else
		{
			counter = 0;
		}

	}
	if( 4 != counter)
		return FALSE;
}
