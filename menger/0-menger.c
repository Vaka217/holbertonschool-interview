#include "menger.h"

/**
 * print_sponge - prints a level N Menger Sponge of given size
 */
void print_sponge(int size)
{
	int row, column, print_pound = 1;
	int divisor, r_remain, c_remain;

	for (row = 0; row < size; row++)
	{
		for (column = 0; column < size; column++)
		{
			print_pound = 1;

			for (divisor = 1; divisor < size; divisor *= 3)
			{
				r_remain = ((row / divisor) % 3) == 1;
				c_remain = ((column / divisor) % 3) == 1;

				if (r_remain && c_remain && print_pound)
					print_pound = 0;
			}

			if (print_pound)
				printf("#");
			else
				printf(" ");
		}

		printf("\n");
	}
}

/**
 * menger - draws a 2D Menger Sponge of given level
 * @level: level of the Menger Sponge to draw
 * if level is less than 0, nothing happens
 * level 0 sponge is represented by #
 * level N sponge is represented by 3x3 square of level N-1 sponges,
 * with an empty center
 */
void menger(int level)
{
	int size = pow(3, level);

	if (level < 0)
		return;

	if (level == 0)
	{
		printf("#\n");
	}
	else
	{
		print_sponge(size);
	}
}
