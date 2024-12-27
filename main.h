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
	ssize_t (*f)(const char *);
} op_t;
ssize_t (*get_op_func(const char *))(const char *);
ssize_t byte_count(const char *);
ssize_t line_count(const char *);
ssize_t word_count(const char *);
ssize_t char_count(const char *);

#endif
