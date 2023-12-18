#include "main.h"

#define BUFFER_SIZE 1024

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
    static char buffer[BUFFER_SIZE];
    static char *p;
    static ssize_t len;
    char *newline;

    if (lineptr == NULL || n == NULL || stream != stdin)
    {
        return -1;
    }

    if (!*lineptr)
    {
        *lineptr = malloc(BUFFER_SIZE);
        if (!*lineptr)
        {
            return -1;
        }
        *n = BUFFER_SIZE;
    }

    (*lineptr)[0] = '\0';

    while (1)
    {
        if (p && *p)
        {
            size_t remaining = strlen(p);
            if (remaining >= *n)
            {
                char *temp = realloc(*lineptr, *n + remaining + 1);
                if (!temp)
                {
                    free(*lineptr);
                    return -1;
                }
                *lineptr = temp;
                *n += remaining + 1;
            }
            strcat(*lineptr, p);

            newline = strchr(*lineptr, '\n');
            if (newline)
            {
                *newline = '\0';
                p = newline + 1;
                return strlen(*lineptr);
            }
            else
            {
                p = NULL;
            }
        }
        else
        {
            p = buffer;
            len = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
            if (len <= 0)
            {
                return len;
            }
            buffer[len] = '\0';
        }
    }
}
