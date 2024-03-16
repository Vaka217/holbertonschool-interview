#include "sort.h"

/**
 * calculate_power_of_ten - Calculates the power of 10.
 * @exponent: Exponent to which 10 is raised.
 *
 * This function calculates and returns 10 raised to the power of the given
 * exponent.
 *
 * Returns: The result of 10 raised to the power of the given exponent.
 */
int calculate_power_of_ten(int exponent)
{
	int i, result = 1;

	for (i = 0; i < exponent; i++)
		result *= 10;
	return (result);
}

/**
 * free_matrix_memory - Frees memory allocated for a matrix.
 * @matrix: Double pointer to the matrix to be freed.
 *
 * This function frees the memory allocated for a matrix.
 * It takes a double pointer to the matrix as input.
 *
 * Returns: No return value.
 */
void free_matrix_memory(int **matrix)
{
	int i;

	for (i = 0; i < 10; i++)
		free(matrix[i]);
	free(matrix);
}
/**
 * sort_by_digit - Sorts an array by a specific digit position.
 * @array: The array to be sorted.
 * @temp: Temporary matrix to store sorted numbers.
 * @size: Size of the array.
 * @digit_position: The position of the digit to apply sorting.
 *
 * This function sorts the elements of the array based on the digit at the
 * specified position.
 * It places the sorted numbers in the temporary matrix.
 *
 * Returns: 0 if the digit is the rightmost digit, otherwise 1.
 */
int sort_by_digit(int *array, int **temp, size_t size, int digit_position)
{
	int digit, index[10] = {0}, k, max = 0;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		digit = (array[i] % calculate_power_of_ten(digit_position)) /
			  calculate_power_of_ten(digit_position - 1);
		temp[digit][index[digit]++] = array[i];
		if (array[i] > max)
			max = array[i];
	}
	k = 0;
	j = 0;
	for (i = 0; i < 10; i++)
	{
		while (index[i] != 0 && k < index[i])
		{
			array[j + k] = temp[i][k];
			k++;
		}
		j += k;
		k = 0;
	}
	print_array(array, size);

	if (max / calculate_power_of_ten(digit_position) == 0)
		return (0);
	return (1);
}

/**
 * apply_radix_sort - Apply radix sort algorithm to an array.
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * This function applies the radix sort algorithm to sort the given array.
 *
 * Returns: No return value.
 */
void radix_sort(int *array, size_t size)
{
	int **temp, flag = 1, digit_position = 1;
	size_t i;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(int *) * 10);
	for (i = 0; i < 10; i++)
		temp[i] = malloc(sizeof(int) * size);
	while (flag)
		flag = sort_by_digit(array, temp, size, digit_position++);
	free_matrix_memory(temp);
}
