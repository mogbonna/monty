#include "monty.h"

/**
 * mul_stack -  Multiplies second element by top element
 * @line_number: Line number of the command in monty file
 * @actual_head: Address of the head
 *
 */

void mul_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node = *actual_head;
	int count = 0, tmp_value = 0;

	while (tmp_node)
	{
		tmp_node = tmp_node->next;
		count++;
	}
	if (count >= 2)
	{
		tmp_node = *actual_head;
		tmp_value = tmp_node->next->n * tmp_node->n;
		tmp_node->next->n = tmp_value;
		pop_stack(actual_head, line_number);
	}
	else
		error_funct_2(13, line_number);
}

/**
 * mod_stack - Computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @line_number: Line number of the command in monty file
 * @actual_head: Address of the head
 *
 */

void mod_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node = *actual_head;
	int count = 0, tmp_value = 0;

	while (tmp_node)
	{
		tmp_node = tmp_node->next;
		count++;
	}
	if (count >= 2)
	{
		tmp_node = *actual_head;
		if (tmp_node->n == 0)
			error_funct_2(12, line_number);
		tmp_value = tmp_node->next->n % tmp_node->n;
		tmp_node->next->n = tmp_value;
		pop_stack(actual_head, line_number);
	}
	else
		error_funct_2(14, line_number);
}

/**
 * print_char_stack -  Prints the char at the top of the stack
 * @actual_head: Head of the dlistint
 * @line_number: Line number of the command
 *
 */

void print_char_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node;

	tmp_node = *actual_head;
	if (*actual_head != NULL)
		if (tmp_node->n >= 32 && tmp_node->n <= 126)
			printf("%c\n", tmp_node->n);
		else
			error_funct_2(16, line_number);
	else
		error_funct_2(15, line_number);
}

/**
 * print_str_stack - Prints the string starting at the top of the stack
 * @actual_head: Head of the dlistint
 * @line_number: Line number of the command
 *
 */

void print_str_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node;

	(void)line_number;
	tmp_node = *actual_head;
	if (tmp_node == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp_node != NULL)
	{
		if (tmp_node->n == 0)
			break;
		if (tmp_node->n < 32 || tmp_node->n > 126)
			break;
		printf("%c", tmp_node->n);
		tmp_node = tmp_node->next;
	}
	printf("\n");
}

/**
 * rotate_top - Rotates the stack to the top.
 * @actual_head: Head of the dlistint
 * @line_number: Line number of the command
 *
 */

void rotate_top(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node;
	int tmp_value = 0, count = 0;

	(void)line_number;
	tmp_node = *actual_head;
	while (tmp_node)
	{
		tmp_node = tmp_node->next;
		count++;
	}
	tmp_node = *actual_head;
	if (count > 1)
	{
		tmp_value = tmp_node->n;
		while (tmp_node->next)
		{
			tmp_node->n = tmp_node->next->n;
			tmp_node = tmp_node->next;
		}
		tmp_node->n = tmp_value;
	}
}
