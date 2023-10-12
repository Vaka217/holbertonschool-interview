#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned int is a palindrome
 * @n: the number to be checked
 *
 * Return: 1 if n is palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long int reverse = 0, n_copy = n;

	while (n_copy > 0)
	{
		reverse = reverse * 10 + n_copy % 10;
		n_copy = n_copy / 10;
	}

	if (n == reverse)
		return (1);
	return (0);
}
