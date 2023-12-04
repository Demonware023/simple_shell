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

	token = strtok(command, delim);/* Tokenize*/
	while (token != NULL)
	{
		if (strcmp(token, "-l") == 0)/* Removes -l argument*/
		{
			fprintf(stderr, "%s: No such file or directory\n", shell);
			return (-1);/* Error but doesnt exit program*/
		}
		argv[argc++] = token;
		token = strtok(NULL, delim);/* Next command*/
	}

	argv[argc] = NULL;

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
