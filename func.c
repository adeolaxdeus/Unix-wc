#include "main.h"
#include <ctype.h>
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
		close(fd);
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
	size_t newline_count = 0, i = 0;
	char *buffer;
	ssize_t numread;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	buffer = malloc(BUF_SIZE * sizeof(char));
	if (buffer == NULL)
	{
		close(fd);
		return (-1);
	}
	/* read a byte at a time */
	while ((numread = read(fd, buffer, BUF_SIZE)) > 0)
	{
		while (i < (size_t)numread)
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

/**
 * word_count - Find the number of words in a file
 * @filename: File to be read
 *
 * Return: Number of words in a file on success otherwise -1 on failure
 */
int word_count(const char *filename)
{
	int fd, in_word = 0;
	char *buffer;
	size_t word_num = 0, i = 0;
	ssize_t numread;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	buffer = malloc(BUF_SIZE * sizeof(char));
	if (buffer == NULL)
	{
		close(fd);
		return (-1);
	}
	while ((numread = read(fd, buffer, BUF_SIZE)) > 0)
	{
		while (i < (size_t)numread)
		{
			if (isspace(buffer[i]))
			{
				if (in_word)
				{
					word_num++;
					in_word = 0; /* End of word */
				}
			}
			else
			{
				in_word = 1; /* inside a word */
			}
			i++;
		}
		i = 0;
	}
	/*  Account for last word in a file */
	if (in_word)
		word_num++;
	if (numread == -1)
	{
		perror("read");
		free(buffer);
		return (-1);
	}
	free(buffer);
	printf("\t%lu %s\n", word_num, filename);
	if (close(fd) == -1)
	{
		perror("close");
		return (-1);
	}
	return (0);
}

int char_count(const char *filename)
{
	char *c;
	int fd;
	size_t file_char;
	ssize_t numread;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	while ((numread = read(fd, &c, 1)) > 0)
	{
		file_char++;
	}
	if (numread == -1)
	{
		perror("read");
		return (-1);
	}
	printf("\t%lu %s\n", file_char, filename);
	return (0);
}
