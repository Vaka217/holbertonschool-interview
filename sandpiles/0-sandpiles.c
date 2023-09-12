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
 */
static void topple(int grid[3][3])
{
	int i, j, order;
	int topple_order[3][3] = {
	    {0, 1, 0},
	    {1, 2, 1},
	    {0, 1, 0}};

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
}

/**
 * sandpile_topple - Stabilize the given grid
 * @grid: the unstable grid to be stabilized
 */
static void sandpile_topple(int grid[3][3])
{
	int i, j, status = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				printf("=\n");
				print_grid(grid);
				status++;
				break;
			}
		}
		if (status > 0)
			break;
	}

	topple(grid);

	if (status > 0)
		sandpile_topple(grid);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	sandpile_topple(grid1);
}
