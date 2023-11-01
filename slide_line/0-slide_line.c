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
	int current, i, j, last = 0;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < (int)size; i++)
		{
			if (line[i] == 0)
				continue;
			current = line[i];
			for (j = i - 1; j >= last; --j)
			{
				if (line[j] != 0 && current <= line[j])
				{
					line[j] += current;
					line[i] = 0;
					last++;
					break;
				}
				if (j == last && line[last] == 0)
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
			for (j = i + 1; j <= (int)(size - 1 - last); j++)
			{
				if (line[j] != 0 && current >= line[j])
				{

					line[j] += current;
					line[i] = 0;
					last++;
					break;
				}
				if ((j == (int)(size - 1 - last) || (line[i] < line[j + 1])) && line[j] == 0)
				{
					line[j] = current;
					line[i] = 0;
				}
			}
		}
	}
	return (1);
}
