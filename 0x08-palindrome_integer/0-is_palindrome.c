#include "palindrome.h"

/**
 * is_palindrome - Validate if (n) is a palindrome
 * @n: number
 * Return: 0 if not is a palindrome, else 1
 */
int is_palindrome(unsigned long n)
{
	unsigned long endNumber, reverse = 0, cpN = n;

	while (cpN > 0)
	{
		endNumber = cpN % 10;
		reverse = (reverse * 10) + endNumber;
		cpN = cpN / 10;
	}

	if (reverse == n)
		return (1);

	return (0);
}
