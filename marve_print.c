#include "main.h"

/**
  * marve_print - written printf function.
  * @amessage: string passed to the command.
  * Return: void.
  */

void marve_print(const char *amessage)
{
	write(1, amessage, strlen(amessage));
}
