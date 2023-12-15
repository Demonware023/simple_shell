#include "main.h"

/**
  * print_error - Function to print error messages.
  * @argv: argv[0] is the name of the program.
  * @args: args[0] is the command that was attempted to execute.
  * Return: void.
  */

void print_error(char *argv[], char *args[])
{
	if (!isatty(STDIN_FILENO))
	{
		marve_print(argv[0]);
		marve_print(": 1: ");
		marve_print(args[0]);
		marve_print(": not found\n");
	}
	else
	{
		marve_print("./");
		marve_print(argv[0]);
		marve_print(": No such file or directory\n");
	}
}
