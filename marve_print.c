#include "main.h"

/**
  * marve_print - written printf function.
  * @amessage: string passed to the command.
  * Return: void.
  */

void marve_print(const char *amessage)
{
	write(STDOUT_FILENO, amessage, strlen(amessage));
}
