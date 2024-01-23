#include "holberton.h"

int str_len(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

int power_of_ten(int y)
{
	int x = 1;

	for (y; y > 1; y--)
		x *= 10;

	return (x);
}

int main(int argc, char *argv[])
{
	char *a = argv[1], *b = argv[2];
	int size_a = str_len(a), size_b = str_len(b);
	int a_idx = 0, b_idx = 0;
	char *result = malloc(size_a + size_b);
	int orden = 0, orden_two = 0;

	for (b_idx = size_b - 1; b_idx >= 0; b_idx--)
	{
		orden_two = power_of_ten(size_b - b_idx);
		for (a_idx = 0; a_idx < size_a; a_idx++)
		{
			orden = power_of_ten(size_a - a_idx);
			result[0] = '1';
			printf("%s\n", result);
			printf("%d\n", ((a[a_idx] - '0') * orden) * ((b[b_idx] - '0') * orden_two));
		}
	}

	return (0);
}
