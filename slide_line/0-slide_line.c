#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_line - Prints out an array of integer, followed by a new line
 *
 * @line: Array of integers to be slide and merge
 * @size: Number of elements in line array
 * @direction: Direction to slide. Can be SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int current, i, j, juan = 0;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < (int)size; i++)
		{
			if (line[i] == 0)
				continue;
			current = line[i];
			for (j = i - 1; j >= juan; --j)
			{
				if (line[j] != 0 && current <= line[j])
				{
					line[j] += current;
					line[i] = 0;
					juan++;
					break;
				}
				if (j == juan && line[juan] == 0)
				{
					line[j] = current;
					line[i] = 0;
				}
			}
		}
	}
	if (direction == SLIDE_RIGHT)
	{
		for (i = (int)(size - 1); i >= 0; i--)
		{
			if (line[i] == 0)
				continue;
			current = line[i];
			for (j = i + 1; j <= (int)(size - 1 - juan); j++)
			{
				if (line[j] != 0 && current <= line[j])
				{
					line[j] += current;
					line[i] = 0;
					juan++;
					break;
				}
				if (j == (int)(size - 1 - juan) && line[(int)(size - 1 - juan)] == 0)
				{
					line[j] = current;
					line[i] = 0;
				}
			}
		}
	}
	return (1);
}
