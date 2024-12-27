#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * @ac: Number of command line argument passed
 * @av:  Pointer to to command line arguments
 *
 * Return: 0 on success otherwise -1
 */
int main(int ac, char **av)
{
	const char *filename = av[2];
	const char *option = av[1];
	ssize_t (*func_ptr)(const char *);

	if (ac == 2 && av[1] != NULL)
	{
		filename = av[1];
		printf(" %lu %lu %lu %s\n", line_count(filename), word_count(filename),
				byte_count(filename), filename);
		return (0);
	}
	func_ptr = get_op_func(option);
	if (func_ptr == NULL)
	{
		printf("Invalid option %s\n", option);
		return (-1);
	}
	printf("%lu %s\n", func_ptr(filename), filename);
	return (0);
}
