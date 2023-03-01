#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_line - slide and merge array integers
 * @size: line size
 * @line: current line
 * Return: 1 success else 0 failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, j = 0;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		for (i = 1; i < size; i++)
		{
			if (line[i] != 0)
			{
				if (line[i] == line[j] && j != i)
				{
					line[j] *= 2;
					line[i] = 0;
					j++;
				}
				else if (line[j] == 0)
				{
					line[j] = line[i];
					line[i] = 0;
				}
				else if (line[j + 1] == 0)
				{
					line[j + 1] = line[i];
					line[i] = 0;
					j++;
				}
				else
					j++;
			}
		}
	}
	else
	{
		for (i = 1; i < size; i++)
		{
			if (line[size - 1 - i] != 0)
			{
				if (line[size - 1 - i] == line[size - 1 - j] && j != i)
				{
					line[size - 1 - j] *= 2;
					line[size - 1 - i] = 0;
					j++;
				}
				else if (line[size - 1 - j] == 0)
				{
					line[size - 1 - j] = line[size - 1 - i];
					line[size - 1 - i] = 0;
				}
				else if (line[size - 1 - j - 1] == 0)
				{
					line[size - 1 - j - 1] = line[size - 1 - i];
					line[size - 1 - i] = 0;
					j++;
				}
				else
					j++;
			}
		}
	}

	return (1);
}
