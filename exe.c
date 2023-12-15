#include "main.h"

/**
  * exe - function to execute commands in the shell.
  * @command: command to execute.
  * @argv:Argument vector.
  * @envp: Enviroment variable.
  * Return: Always 0 Success.
  */

int exe(const char *command, char *argv[], char *envp[])
{
	char *args[2];
	pid_t child_pid;

	args[0] = strdup(command);
	args[1] = NULL;

	child_pid = fork();

	if (child_pid == -1)
	{
		marve_print(argv[0]);
		marve_print(": Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(args[0], args, envp);
		print_error(argv, args);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	free(args[0]);

	return (0);
}
