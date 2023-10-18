#include "monty.h"

/**
 * push_stack - Pushes an element to the stack.
 * @value: Value to add to the node
 * @actual_head: Address of the head
 *
 */

void push_stack(stack_t **actual_head, unsigned int value)
{
	stack_t *new_node;
	stack_t *current = *actual_head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		error_function(4, NULL, value);
	new_node->n = value;
	new_node->next = *actual_head;
	new_node->prev = NULL;
	if (current != NULL)
		current->prev = new_node;
	head = new_node;
}

/**
 * print_stack - Prints all the values on the stack
 * starting from the top of the stack.
 * @line_number: line number with the command
 * @actual_head: address of the head
 *
 */
void print_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node;

	(void)line_number;

	if (actual_head != NULL)
	{
		tmp_node = *actual_head;
		while (tmp_node != NULL)
		{
			printf("%d\n", tmp_node->n);
			tmp_node = tmp_node->next;
		}
	}
}

/**
 * free_dlistint - Free a double linked list
 * @head: Address of the head of doubly linked list
 *
 */

void free_dlistint(stack_t *head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
			free_dlistint(head->next);
		free(head);
	}
}

/**
 * pint_stack - Prints top element of stack
 * @actual_head: Head of the dlistint
 * @line_number: Line number of the command
 *
 */

void pint_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp_node;

	(void)line_number;
	tmp_node = *actual_head;
	if (*actual_head != NULL)
		printf("%i\n", tmp_node->n);
	else
		error_function(6, NULL, line_number);
}

/**
 * pop_stack - Deletes the node at top in the stack
 * @actual_head: Pointer to begin
 * @line_number: Indicate the line number of command
 *
 */

void pop_stack(stack_t **actual_head, unsigned int line_number)
{
	stack_t *tmp, *erase;

	tmp = *actual_head;
	if (tmp == NULL)
		error_function(7, NULL, line_number);
	erase = *actual_head;
	*actual_head = tmp->next;
	tmp = tmp->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	free(erase);
}
