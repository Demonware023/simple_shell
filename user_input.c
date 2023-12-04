#include "main.h"

/**
  * user_input - takes input from the user.
  * @command: commands passed.
  * @size: amount of the commands.
  * @stream: buf used to store the strinds passed by the user.
  * Return: Always 0 Success.
  */

int read_input(char *command, size_t size, FILE *stream)
{
	ssize_t read = 0;
	char *cmd = NULL;

	read = getline(&cmd, &size, stream);
	/* This gets the user input using getline*/
	if (read == -1)
	{
		if (feof(stream))/*Checks for end of file*/
		{
			marve_print("\n");/*prints new line if at eof*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	strncpy(command, cmd, size);
	command[strcspn(command, "\n")] = '\0';/* Removes \n character.*/
	free(cmd);

	return (0);
}
