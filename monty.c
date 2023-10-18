#include "monty.h"
stack_t *head = NULL;

/**
 * main - Function main for begin the program
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
		error_function(1, argv[1], argc);
	if (access(argv[1], R_OK) == -1)
		error_function(2, argv[1], argc);
	file = fopen(argv[1], "r");
	if (file == NULL)
		error_function(2, argv[1], argc);
	read_file(file);
	fclose(file);
	free_dlistint(head);
	return (0);
}

/**
 * read_file - Function to read the file
 * @file: Pointer to file to read
 *
 */
void read_file(FILE *file)
{
	char *lineprt = NULL;
	size_t n = 0;
	int line_number = 1;
	int flag = 0;

	while (read_line(&lineprt, &n, file))
	{
		flag = split_string(lineprt, line_number, flag);
		line_number++;
	}
	free(lineprt);
}

int read_line(char **lineptr, size_t *n, FILE *file)
{
	const int buffer_size = 128;
	size_t len;

	if (*lineptr == NULL)
	{
		*n = buffer_size;
		*lineptr = (char *)malloc(buffer_size * sizeof(char));
		
		if (*lineptr == NULL)
		{
			fprintf(stderr, "Memory allocation error\n");
			exit(EXIT_FAILURE);
		}
	}
	
	if (fgets(*lineptr, buffer_size, file) == NULL)
	{
		return 0;
	}
	
	len = strlen(*lineptr);
	if ((*lineptr)[len - 1] == '\n')
	{
		(*lineptr)[len - 1] = '\0';
		return 1;
	}

	*n += buffer_size - 1;
	*lineptr = (char *)realloc(*lineptr, *n);

	if (*lineptr == NULL)
	{
		fprintf(stderr, "Memory reallocation error\n");
		exit(EXIT_FAILURE);
	}
	return read_line(lineptr, n, file);
}

/**
 * split_string - Separates by lines to determinate the function to use
 * @lineptr: String representing a line in a file.
 * @line_number: Line number for the opcode.
 * @flag: Flag to know if is stack or queue
 *
 * Return: 0 if is stack or 1 if is queue
 */
int split_string(char *lineptr, int line_number, int flag)
{
	char *delim;
	char *opcode;
	char *value;

	delim = "\n ";
	opcode = strtok(lineptr, delim);
	value = strtok(NULL, delim);

	if (opcode != NULL)
	{
		if (opcode[0] == '#')
			return (flag);
		if (strcmp(opcode, "stack") == 0)
		{
			flag = 0;
			return (flag);
		}
		if (strcmp(opcode, "queue") == 0)
		{
			flag = 1;
			return (flag);
		}
		opcode_func(value, opcode, line_number, flag);
	}
	return (flag);
}

/**
  * opcode_func - Find the specific opcode function to use
  * @value: Value to manipulate
  * @monty_opcode: String with monty instruction
  * @line_number: The line where is the instruction
  * @flag: Flag to know if is stack or queue
  *
  */
void opcode_func(char *value, char *monty_opcode, int line_number, int flag)
{
	void (*operation)(stack_t **, unsigned int);
	int signo = 1, j = 0;
	unsigned int int_value = 0;

	operation = get_op_func(monty_opcode);
	if (operation)
	{
		if (strcmp(monty_opcode, "push") == 0)
		{
			if (value == NULL)
				error_function(5, monty_opcode, line_number);
			else if (value[0] == '-')
			{
				value = value + 1;
				signo = (signo * -1);
			}
			while (value[j])
			{
				if (isdigit(value[j]) == 0)
					error_function(5, monty_opcode, line_number);
				j++;
			}
			int_value = atoi(value) * signo;
			if (flag == 0)
				operation(&head, int_value);
			if (flag == 1)
				push_queue(&head, int_value);
		}
		else
			operation(&head, line_number);
		return;
	}
	error_function(3, monty_opcode, line_number);
}
