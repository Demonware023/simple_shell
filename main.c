#include "main.h"

/**
  * main - main function/source code.
  * @argc: argument count
  * @argv: strings/commands passed (Argument Vector)
  * Return: Always 0 Success.
  */
int main(int argc, char **argv)
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
				exe(command, argv[0]);/* If no error, execute*/
			}
		}
		else
		{
			while (read_input(command, sizeof(command), stdin) != -1)
			{
				exe(command, argv[0]);
			}
		}
	}
	else
	{
		for (i = 1 ; i < argc ; i++)
		{
			strncpy(command, argv[i], sizeof(command));
			exe(command, argv[0]);
		}
	}

	return (0);
}
