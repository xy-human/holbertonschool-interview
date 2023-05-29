#include "holberton.h"

/**
 * _puts - prints a string, followed by a new line.
 * @ch: character string.
 */
void _puts(char *ch)
{
	if (*ch != '\0')
	{
		_putchar(*ch);
		_puts(ch + 1);
	}
	else
		_putchar('\n');
}

/**
 * is_number - verify if a charstring is a number.
 * @ch: character string.
 * Return: 1 if the charstring is a valid number, 0 otherwise.
 */
int is_number(char *ch)
{
	for (; *ch != '\0'; ch++)
	{
		if (*ch < '0' || *ch > '9')
			return (0);
	}

	return (1);
}

/**
 * multiply - multiply 2 numbers represented by a charstring.
 * @num1: first number charstring.
 * @num2: second number charstring.
 * @l1: length of the first number.
 * @l2: length of the second number.
 */
void multiply(char *num1, char *num2, int l1, int l2)
{
	char *product = NULL;
	int i, j, n, total_length = l1 + l2;

	product = malloc(sizeof(char) * total_length);
	if (!product)
	{
		_puts("Error");
		exit(98);
	}

	for (i = l1 - 1; i >= 0; i--)
	{
		for (j = l2 - 1; j >= 0; j--)
		{
			n = (num1[i] - '0') * (num2[j] - '0') + product[i + j + 1];
			product[i + j + 1] = n % 10;
			product[i + j] += n / 10;
		}
	}

	for (i = 0; i < total_length; i++)
		product[i] += '0';

	if (*product == '0')
		_puts(product + 1);
	else
		_puts(product);

	free(product);
}

/**
 * main - multiplies two positive numbers.
 * @argc: number of arguments.
 * @argv: arguments.
 * Return: 0 if success otherwise 98 and print Error.
 */
int main(int argc, char *argv[])
{
	int l1 = 0, l2 = 0;

	if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
	{
		_puts("Error");
		exit(98);
	}

	if (*argv[1] == '0' || *argv[2] == '0')
	{
		_puts("0");
		return (0);
	}

	while (argv[1][l1])
		l1++;
	while (argv[2][l2])
		l2++;

	multiply(argv[1], argv[2], l1, l2);

	return (0);
}
