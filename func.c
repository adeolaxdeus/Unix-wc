#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#define BUF_SIZE 1024
/**
 * byte_count -  Outputs the number of byte in a file
 * @filename:  File to be read
 *
 * Return: 0 on success otherwise -1 on error
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

/**
 * line_count - Output the number of lines in a file
 * @filename: File to be read
 *
 * Return: 0 on success otherwise -1 on error
 */
int line_count(const char *filename)
{
	int fd;
	size_t newline_count = 0;
	char *buffer;
	ssize_t numread, i = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	buffer = malloc(BUF_SIZE * sizeof(char));
	if (buffer == NULL)
		return (-1);
	/* read a byte at a time */
	while ((numread = read(fd, buffer, BUF_SIZE)) > 0)
	{
		while (i < numread)
		{
			if (buffer[i] == '\n') /* check if current byte is a '\n' character */
				newline_count++;
			i++;
		}
		i = 0; /* reset i to 0 index of buffer */
	}
	if (numread == -1)
	{
		free(buffer);
		perror("read");
		return (-1);
	}
	free(buffer);
	printf("\t%lu %s\n", newline_count, filename);
	if (close(fd) == -1)
	{
		perror("close");
		return (-1);
	}
	return (0);
}
