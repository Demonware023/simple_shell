#include "main.h"

/**
  * exe - function to execute commands in the shell.
  * @command: command to execute.
  * @shell: Shell name that produces argv[0], the first argument, as-
  * a prompt for all error messages.
  * Return: Always 0 Success.
  */

int exe(char *command, char *shell)
{
	char *delim = " ";/* Delimiter that tokenizes with spaces*/
	int argc = 0;
	char *token;/* Stores tokenized inputs*/
	char *argv[100];
	pid_t child;/* Creates a child process if a coommand is executed.*/
	char *path;
	char *path_copy;
	char *dir;
	char full_path[1024];

	token = strtok(command, delim);/* Tokenize*/
	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, delim);/* Next command*/
	}

	argv[argc] = NULL;

	path = getenv("PATH");
	path_copy = strdup(path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, argv[0]);
		if (access(full_path, F_OK) == 0)
		{
			argv[0] = full_path;
			break;
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);

	child = fork();/* Creates a child process to run the command*/
	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)/* PID executes if successful*/
		{
			fprintf(stderr, "%s: No such file or directory\n", shell);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);/* Parents for child to finish executing*/
	}

	return (0);
}
