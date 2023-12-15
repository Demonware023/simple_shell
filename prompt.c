#include "main.h"

/**
  * infinite_prompt - prompt always ready to take user input.
  * Return: void.
  */

void infinite_prompt(void)
{
	/* If its the terminal*/
	if (isatty(STDIN_FILENO))
	{
		marve_print("demonshell($) ");
	}
}
