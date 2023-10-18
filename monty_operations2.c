#include "monty.h"

/**
 * swap_stack - Swaps the top two elements of the stack.
 * @line_number: Line number of the command in monty file
 * @actual_head: Address of the head
 *
 */

void swap_stack(stack_t **actual_head, unsigned int line_number)
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
		tmp_value = tmp_node->n;
		tmp_node->n = tmp_node->next->n;
		tmp_node->next->n = tmp_value;
	}
	else
		error_function(8, NULL, line_number);
}

/**
 * add_stack - Add the top two elements of the stack.
 * @line_number: Line number of the command in monty file
 * @actual_head: Address of the head
 *
 */

void add_stack(stack_t **actual_head, unsigned int line_number)
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
		tmp_value = tmp_node->n + tmp_node->next->n;
		tmp_node->next->n = tmp_value;
		pop_stack(actual_head, line_number);
	}
	else
		error_function(9, NULL, line_number);
}

/**
 * do_nothing - Doesn’t do anything.
 * @line_number: Line number of the command in monty file
 * @actual_head: Address of the head
 *
 */

void do_nothing(stack_t **actual_head, unsigned int line_number)
{
	(void)line_number;
	(void)actual_head;
}

/**
 * sub_stack - Subtracts top element from the second.
 * @line_number: Line number of the command in monty file
 * @actual_head: Address of the head
 *
 */

void sub_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node = *actual_head;
	int count, tmp_value = 0;

	while (tmp_node)
	{
		tmp_node = tmp_node->next;
		count++;
	}
	if (count >= 2)
	{
		tmp_node = *actual_head;
		tmp_value = tmp_node->next->n - tmp_node->n;
		tmp_node->next->n = tmp_value;
		pop_stack(actual_head, line_number);
	}
	else
		error_function(10, NULL, line_number);
}

/**
 * div_stack - Divides second top element by the top of stack.
 * @line_number: Line number of the command in monty file
 * @actual_head: Address of the head
 *
 */

void div_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node = *actual_head;
	int count, tmp_value = 0;

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
		tmp_value = tmp_node->next->n / tmp_node->n;
		tmp_node->next->n = tmp_value;
		pop_stack(actual_head, line_number);
	}
	else
		error_funct_2(11, line_number);
}
