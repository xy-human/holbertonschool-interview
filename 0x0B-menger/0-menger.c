#include "menger.h"

/**
 * menger - Draw 2d menger form
 * @level: level of menger
 */
void menger(int level)
{
	int size, row, col;
	char character;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			character = get_character(row, col);
			printf("%c", character);
		}
		printf("\n");
	}
}

/**
 * get_character - character
 * @row: get row
 * @col: get column
 * Return: str '#'
 */
char get_character(int row, int col)
{
	while (row || col)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (' ');
		row /= 3;
		col /= 3;
	}
	return ('#');
}
