#include "main.h"
#include <string.h>
#include <stdlib.h>
/**
 * get_func - Get fucntion associated to command line option
 * @option: Command line option for wc command
 *
 * Return: Pointer to associated function
 */
ssize_t (*get_op_func(const char *option))(const char *)
{
	op_t ops[] = {
		{"-c", byte_count},
		{"-l", line_count},
		{"-w", word_count},
		{"-m", char_count},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL)
	{
		if (strcmp(ops[i].op, option) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
