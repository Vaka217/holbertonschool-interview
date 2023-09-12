#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
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
 * sandpile_topple - Stabelize the given grid
 * @grid: the unstable grid to be stabelized
 *
 */
void sandpile_topple(int grid[3][3])
{
	int i, j, order;
	int topple_order[3][3] = {
	    {0, 1, 0},
	    {1, 2, 1},
	    {0, 1, 0}};

	print_grid(grid);
	for (order = 0; order < 3; order++)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid[i][j] > 3 && topple_order[i][j] == order)
				{
					grid[i][j] -= 4;
					if (i > 0)
						grid[i - 1][j]++;
					if (i < 2)
						grid[i + 1][j]++;
					if (j > 0)
						grid[i][j - 1]++;
					if (j < 2)
						grid[i][j + 1]++;
				}
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				printf("=\n");
				sandpile_topple(grid);
			}
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	sandpile_topple(grid1);
}
