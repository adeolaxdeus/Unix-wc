#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
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
	ssize_t (*func_ptr)(int);
	int fd;
	ssize_t res;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	(void) ac;
/**	if (ac == 2 && av[1] != NULL)
	{
		filename = av[1];
		printf(" %lu %lu %lu %s\n", line_count(filename), word_count(filename),
				byte_count(filename), filename);
		return (0);
	}**/
	func_ptr = get_op_func(option);
	if (func_ptr == NULL)
	{
		printf("Invalid option %s\n", option);
		return (-1);
	}
	res = func_ptr(fd);
	if (res == -1)
		return (-1);
	printf("%lu %s\n", res, filename);
	if (close(fd) == -1)
	{
		perror("close");
		return (-1);
	}
	return (0);
}
