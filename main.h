#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
/**
 * struct op - Struct op
 * @op: The operator
 * @f:  The function associated
 */
typedef struct op
{
	char *op;
	ssize_t (*f)(int);
} op_t;
ssize_t (*get_op_func(const char *))(int);
ssize_t byte_count(int);
ssize_t line_count(int);
ssize_t word_count(int);
ssize_t char_count(int);

#endif
