#include "main.h"

/**
  * main - main function/source code.
  * @argc: argument count
  * @argv: strings/commands passed (Argument Vector)
  * Return: Always 0 Success.
  */
int main(int argc, char **argv, char **envp)
{
	char command[1024];
	int i;

	if (argc == 1)/* If no commands enter interactive mode*/
	{
		if (isatty(STDIN_FILENO))
		{
			while (1)/*while always true for blinking prompt*/
			{
				infinite_prompt();/* call prompt function*/
				if (read_input(command, sizeof(command), stdin) == -1)
				{
					break;
				}
				/* Implements the exit function*/
				if (strcmp(command, "exit") == 0)
				{
					exit(EXIT_SUCCESS);
				}
				else if (strcmp(command, "env") == 0)
				{
					for (i = 0 ; envp[i] != NULL; i++)
					{
						write(STDOUT_FILENO, envp[i], strlen(envp[i]));
						write(STDOUT_FILENO, "\n", 1);
					}
				}
				else
				{
					exe(command, argv[0]);/* If no error, execute*/
				}
			}
		}
		else
		{
			while (read_input(command, sizeof(command), stdin) != -1)
			{
				if (strcmp(command, "exit") == 0)
				{
					exit(EXIT_SUCCESS);
				}
				else if (strcmp(command, "env") == 0)
				{
					for (i = 0 ; envp[i] != NULL ; i++)
					{
						write(STDOUT_FILENO, envp[i], strlen(envp[i]));
						write(STDOUT_FILENO, "\n", 1);
					}
				}
				else
				{
					exe(command, argv[0]);
				}
			}
		}
	}
	else
	{
		for (i = 1 ; i < argc ; i++)
		{
			strncpy(command, argv[i], sizeof(command));
			if (strcmp(command, "exit") == 0)
			{
				exit(EXIT_SUCCESS);
			}
			else if (strcmp(command, "env") == 0)
			{
				for (i = 0 ; envp[i] != NULL ; i++)
				{
					write(STDOUT_FILENO, envp[i], strlen(envp[i]));
					write(STDOUT_FILENO, "\n", 1);
				}
			}
			else
			{
				exe(command, argv[0]);
			}
		}
	}

	return (0);
}
