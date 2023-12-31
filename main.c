#include "monty.h"

/**
 * main - main func
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	FILE *f = fopen(av[1], "r");
	int x;
	unsigned int line_number = 0;
	char line[MAX_LINE], *cmd;
	operator p;
	stack_t *top = NULL;

	if (ac != 2)
		_dprintf(ERR_C, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	if (f == NULL)
	{
		_dprintf(ERR_C, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	data.push_stack = push_stack; /* The default is stack */
	while ((x = _getline(line, MAX_LINE, f)) > 0)
	{
		*(&data.run_status) = 0;
		line_number++;
		cmd = strtok(line, "\n ");
		if (cmd && cmd[0] == '#')
			continue;
		if (cmd != NULL)
		{
			data.elem = strtok(NULL, "\n ");
			p = get_op(cmd);
			run_op(&top, p, line_number, cmd);
		}
		if (data.run_status == -1)
			break;
	}
	if (data.run_status == -1 || x <= 0) /* if x is EOF or an error occured */
		fclose(f), free_stack(top);
	if (data.run_status == -1)
		exit(EXIT_FAILURE);
	return (0);
}

/**
 * get_op - function that selects the correct function
 * @s: operator passed
 * Return: pointer to corresponding func
 */
operator get_op(char *s)
{
	instruction_t ops[] = {
	    {"push", push},
	    {"pall", pall},
	    {"pint", pint},
	    {"pop", pop},
	    {"swap", swap},
	    {"add", add},
	    {"sub", sub},
	    {"div", divi},
	    {"mul", mul},
	    {"mod", mod},
	    {"nop", nop},
	    {"pchar", pchar},
	    {"pstr", pstr},
	    {"rotl", rotl},
	    {"rotr", rotr},
	    {"queue", queue},
	    {"stack", stack},
	    {NULL, NULL},
	};

	int i, len;

	for (len = 0; ops[len].opcode != NULL; len++)
		;
	for (i = 0; i < len; i++)
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].f);
	return (NULL);
}

/**
 * run_op - runs the operation
 * @top: top of stack
 * @f: op function
 * @l: line number
 * @cmd: command
 */
void run_op(stack_t **top, operator f, unsigned int l, char *cmd)
{
	if (f == NULL)
	{
		_dprintf(ERR_C, "L%d: unknown instruction %s\n", l, cmd);
		*(&data.run_status) = -1;
		return;
	}
	f(top, l);
}
