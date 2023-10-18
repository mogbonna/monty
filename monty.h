#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

void read_file(FILE *file);
int read_line(char **lineptr, size_t *n, FILE *file);
void error_function(int error_number, char *file_name, int line_number);
int split_string(char *lineptr, int line_number, int flag);
void opcode_func(char *value, char *opcode, int line_number, int flag);
void  push_stack(stack_t **new_node, unsigned int value);
void print_stack(stack_t **actual_head, unsigned int line_number);
void free_dlistint(stack_t *head);
void pint_stack(stack_t **actual_head, unsigned int line_number);
void pop_stack(stack_t **actual_head, unsigned int line_number);
void swap_stack(stack_t **actual_head, unsigned int line_number);
void add_stack(stack_t **actual_head, unsigned int line_number);
void do_nothing(stack_t **actual_head, unsigned int line_number);
void (*get_op_func(char *s))(stack_t **, unsigned int);
void sub_stack(stack_t **actual_head, unsigned int line_number);
void div_stack(stack_t **actual_head, unsigned int line_number);
void error_funct_2(int error_number, int line_number);
void mul_stack(stack_t **actual_head, unsigned int line_number);
void mod_stack(stack_t **actual_head, unsigned int line_number);
void print_char_stack(stack_t **actual_head, unsigned int line_number);
void print_str_stack(stack_t **actual_head, unsigned int line_number);
void rotate_top(stack_t **actual_head, unsigned int line_number);
void rotate_bottom(stack_t **actual_head, unsigned int line_number);
void push_queue(stack_t **actual_head, unsigned int value);

#endif /* MONTY_H */
