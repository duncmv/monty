#include "main.h"

int run_status;
char *elem;

/**
 * main - main func
 * @ac: arg count
 * @av arg vector
 * Return: 0
 */
int main(int ac, char **av)
{
	extern int run_status;
	extern char *elem;
	FILE *f = fopen(av[1], "r");
	int x;
	unsigned int line_number = 0;
	char line[MAX_LINE], *cmd;
	void (*p)(stack_t **, unsigned int);
	stack_t *top = NULL;

	if (ac != 2)
		_dprintf(2, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	if (f == NULL)
	{
		_dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		*(&run_status) = 0;
		x = _getline(line, MAX_LINE, f);
		if (x == -1 || x == 0) /* end of file */
		{
			fclose(f);
			free_stack(top);
			break;
		}
		line_number++;
		cmd = strtok(line, "\n ");
		if (cmd != NULL)
		{
			elem = strtok(NULL, "\n ");
			p = get_op(cmd);
			run_op(&top, p, line_number, cmd);
		}
		if (run_status == -1)
		{
			fclose(f);
			free_stack(top);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

/**
 * get_op - function that selects the correct function
 * @s: operator passed
 * Return: pointer to corresponding func
 */
void (*get_op(char *s))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
	    {"push", push},
	    {"pall", pall},
	    {NULL, NULL},
	};
	int i = 0;

	while (i < 2)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
/**
 * run_op - runs the operation
 * @top: top of stack
 * @f: op function
 * @l: line number
 * @cmd: command
 */
void run_op(stack_t **top, void (*f)(stack_t **, unsigned int), unsigned int l, char *cmd)
{
	if (f == NULL)
	{
		_dprintf(2, "L%d: unknown instruction %s\n", l, cmd);
		*(&run_status) = -1;
		return;
	}
	f(top, l);
}

typedef void (*f)(stack_t **, unsigned int), opt;
