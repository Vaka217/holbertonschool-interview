#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple - Do the topple
 * @grid: the unstable grid
 * @buffer: the buffer
 */
static void topple(int grid[3][3], int buffer[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			buffer[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				buffer[i][j] -= 4;
				if (i > 0)
					buffer[i - 1][j]++;
				if (i < 2)
					buffer[i + 1][j]++;
				if (j > 0)
					buffer[i][j - 1]++;
				if (j < 2)
					buffer[i][j + 1]++;
			}
		}
	}
}

/**
 * is_stable - Check if the grid is stable
 * @grid: the grid to check
 *
 * Return: 1 if stable, 0 if not stable
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);

	return (1);
}

/**
 * grid_sum - sum of two grids
 * @grid1: the first grid
 * @grid2: the second grid
 */

static void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int buffer[3][3];

	grid_sum(grid1, grid2);
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1, buffer);
		grid_sum(grid1, buffer);
	}
}
