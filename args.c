#include "main.h"

/**
  * arg_handler - handles arguments
  * @command: command to be executed
  * @argv: argument vector
  * @envp: enviroment variable.
  * Return: Always 0 Success.
  */

int arg_handler(char *command, char *argv[], char *envp[])
{
	char **args;
	pid_t child_pid;
	int i, arg_count = 0;

	for (i = 0 ; argv[i] != NULL ; i++)
	{
		arg_count++;
	}
	
	args = malloc(sizeof(char*) * (arg_count + 2));

	args[0] = strdup(command);

	for (i = 1 ; i < arg_count ; i++)
	{
		args[i] = strdup(argv[i]);
	}

	args[arg_count] = NULL;

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

	for (i = 0 ; i < arg_count + 1 ; i++)
	{
		free(args[i]);
	}
	free(args);

	return (0);
}
