#include "main.h"

/**
  * read_input - takes input from the user.
  * @command: commands passed.
  * @size: amount of the commands.
  * @stream: buf used to store the strinds passed by the user.
  * Return: Always 0 Success.
  */

int read_input(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			marve_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';

	return (0);
}
