#include <stdio.h>
/**
 * count_char - Count number of character in a file.
 * @fp - Pointer to a file stream
 * @filename: Name of file.
 *
 */
void count_char(FILE *fp, char *filename)
{
	unsigned char c;
	unsigned long int i = 0;

	while (fread(&c, sizeof(unsigned char), 1, fp) == 1)
	{
		i++;
	}
	printf("%lu %s\n", i, filename);
}
/**
 * count_line - Count number of newline in a file.
 * @fp - Pointer to a file stream
 * @filename: Name of file.
 *
 */
void count_line(FILE *fp, char *filename)
{
	char c;
	unsigned long int i = 0;

	while (fread(&c, sizeof(unsigned char), 1, fp) == 1)
	{
		if (c == '\n')
			i++;
	}
	printf("%lu %s\n", i, filename);
}
/**
 * main - Entry point.
 * @argc: Number of command-line args passed.
 * @argv: Pointers to command-line args passed.
 *
 * Description: This program is a utility that behaves exactly
 * as the UNIX wc command.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	FILE *file_ptr;
	char *filename;
	char *__option;

	if (argc >= 1)
	{
		filename = argv[2];
		__option = argv[1];
		file_ptr = fopen(filename, "rb");
		if (file_ptr == NULL)
		{
			printf("ccwc: %s: No such file or directory\n", filename);
			return (1);
		}
		if (argc > 1)
		{
			if (__option[1] == 'c')
				count_char(file_ptr, filename);
			else if (__option[1] == 'l')
				count_line(file_ptr, filename);
		}
		fclose(file_ptr);
	}
	return (0);
}
