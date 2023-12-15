#include "main.h"

/**
  * main - main function/source code.
  * @argc: argument count
  * @argv: strings/commands passed (Argument Vector)
  * @envp: enviroment variable.
  * Return: Always 0 Success.
  */
int main(int argc, char **argv, char **envp)
{
	char command[120];

	(void)argc;

	while (1)
	{
		infinite_prompt();
		read_input(command, sizeof(command));

		if (strlen(command) > 0)
		{
			exe(command, argv, envp);
		}
	}

	return (0);
}
