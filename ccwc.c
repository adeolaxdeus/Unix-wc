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
	int (*func_ptr)(const char *);
	(void) ac;

	func_ptr = get_op_func(option);
	if (func_ptr == NULL)
	{
		printf("Invalid option %s\n", option);
		return (-1);
	}
	return (func_ptr(filename));
}
