#include "monty.h"

/**
  * get_op_func - Find the specific opcode function to use
  * @s: String with monty instruction
  *
  * Return: Always pointer to function on NULL
  */

void (*get_op_func(char *s))(stack_t **, unsigned int)
{
	instruction_t _functions[] = {
		{"push",  push_stack},
		{"pall", print_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{"nop", do_nothing},
		{"sub", sub_stack},
		{"div", div_stack},
		{"mul", mul_stack},
		{"mod", mod_stack},
		{"pchar", print_char_stack},
		{"pstr", print_str_stack},
		{"rotl", rotate_top},
		{"rotr", rotate_bottom},
		{NULL, NULL}
	};
	int i = 0;

	while (_functions[i].opcode)
	{
		if (!(strcmp(_functions[i].opcode, s)))
			return (_functions[i].f);
		i++;
	}
	return (NULL);
}
