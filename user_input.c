#include "main.h"

/**
  * read_input - takes input from the user.
  * @command: commands passed.
  * @size: amount of the commands.
  * Return: Always 0 Success.
  */

int read_input(char **command, size_t *size)
{
    ssize_t result = get_line(command, size, stdin);
    if (result == -1)
    {
        if(feof(stdin))
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            marve_print("Error while reading input.\n");
            exit(EXIT_FAILURE);
        }
    }
    (*command)[strcspn(*command, "\n")] = '\0';

    return (0);
}
