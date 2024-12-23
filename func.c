#include "main.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
/**
 * byte_count -  Outputs the number of byte in a file
 * @fd:  File descriptor for file to be read
 *
 * Return: Byte count on success otherwise -1 on error
 */
int byte_count(const char *filename)
{
	int fd;
	off_t file_size;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	file_size = lseek(fd, 0, SEEK_END);
	if (file_size == -1)
	{
		perror("lseek");
		return (-1);
	}
	printf("\t%lu %s\n", file_size, filename);
	if (close(fd) == -1)
	{
		perror("close");
		return (-1);
	}
	return (0);
}
