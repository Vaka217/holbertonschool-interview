/**
 * str_len - Computes the length of a string.
 * @str: Pointer to the string to be measured.
 *
 * Return: Length of the string.
 */
int str_len(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * print_error - Prints "Error" followed by a newline character.
 */
void print_error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
}

/**
 * is_digit - Checks if a string consists only of numeric digits.
 * @str: Pointer to the string to be checked.
 *
 * Return: 1 if string contains only digits, 0 otherwise.
 */
int is_digit(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of pointers to the arguments.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char *argv[])
{
	char *s_a, *s_b;
	int size_a, size_b;
	int *a, *b;
	int *result;
	int sa_i, sb_i, a_i = 0, b_i = 0, r_i = 0, carry = 0;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_error();
		exit(98);
	}
	s_a = argv[1], s_b = argv[2];
	size_a = str_len(s_a), size_b = str_len(s_b);
	a = malloc(sizeof(int) * size_a), b = malloc(sizeof(int) * size_b);
	result = malloc(sizeof(int) * (size_a + size_b));
	for (a_i = size_a - 1, sa_i = 0; a_i >= 0; a_i--, sa_i++)
		a[a_i] = s_a[sa_i] - '0';
	for (b_i = size_b - 1, sb_i = 0; b_i >= 0; b_i--, sb_i++)
		b[b_i] = s_b[sb_i] - '0';
	for (b_i = 0; b_i < size_b; b_i++)
	{
		for (a_i = 0; a_i < size_a; a_i++)
			result[a_i + b_i] += a[a_i] * b[b_i];
	}
	for (r_i = 0; r_i < (size_a + size_b); r_i++)
	{
		carry = result[r_i] / 10;
		result[r_i] = result[r_i] % 10;
		result[r_i + 1] += carry;
	}
	for (r_i = (size_a + size_b - 1); r_i >= 0; r_i--)
	{
		if (result[r_i] != 0)
			break;
	}
	for (; r_i >= 0; r_i--)
		_putchar(result[r_i] + '0');
	_putchar('\n');
	return (0);
}
