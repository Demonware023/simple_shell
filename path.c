#include "main.h"

int path_handler(char *command, char *argv[], char *envp[])
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char *full_path = malloc(512);
    char *command_copy = strdup(command);
    char *command_name = strtok(command_copy, " ");

    while (dir != NULL)
    {
        sprintf(full_path, "%s/%s", dir, command_name);

        if (access(full_path, X_OK) == 0)
        {
            argv[0] = full_path;
            exe(argv[0], argv, envp);
            free(path_copy);
            free(command_copy);
            return (0);
        }

        dir = strtok(NULL, ":");
    }

    free(path_copy);
    free(full_path);
    free(command_copy);

    marve_print(command);
    marve_print(": command not found\n");

    return (-1);
}
