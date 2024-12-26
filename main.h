#ifndef MAIN_H
#define MAIN_H
/**
 * struct op - Struct op
 * @op: The operator
 * @f:  The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(const char *);
} op_t;
int (*get_op_func(const char *))(const char *);
int byte_count(const char *);
int line_count(const char *);
int word_count(const char *);

#endif
