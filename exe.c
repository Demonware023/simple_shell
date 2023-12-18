#include "main.h"

/**
  * exe - function to execute commands in the shell.
  * @command: command to execute.
  * @argv:Argument vector.
  * @envp: Enviroment variable.
  * Return: Always 0 Success.
  */

char *search_path(char *file) {
    char *PATH = strdup(getenv("PATH"));
    char *p = strtok(PATH, ":");
    char *fullpath = malloc(512);
    
    while(p != NULL) {
        sprintf(fullpath, "%s/%s", p, file);
        if(access(fullpath, F_OK) != -1) {
			free(PATH);
            return fullpath;
        }
        p = strtok(NULL, ":");
    }
    
	free(PATH);
	return NULL;
}

int exe(char *command, char *argv[], char *envp[])
{
    	char *args[64];
    	pid_t child_pid;
	char *command_copy = strdup(command);
    	char *token;
    	int j, i = 0;
	char *fullpath;
	/* char error_message[] = ": No such file or directory\n";*/
	
	token = strtok(command_copy, " ");
    while(token != NULL) {
        args[i] = strdup(token);
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL;
	
	if (args[0][0] == '/')
	{
		fullpath = strdup(args[0]);
	}
	else
	{
		fullpath = search_path(args[0]);
	}

	if(fullpath == NULL) {
        write(1, argv[0], strlen(argv[0]));
	write(1, ": 1: ", 5);
	write(1, args[0], strlen(args[0]));
	write(1, ": not found\n", 12);
	free(command_copy);
        return 1;
    }

    child_pid = fork();

    if (child_pid == -1)
    {
        marve_print(argv[0]);
        marve_print(": Error forking process.\n");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        execve(fullpath, args, envp);
        print_error(argv, args);
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }

    free(fullpath);
    for (j = 0; j < i; j++) {
        free(args[j]);
    }

    return (0);
}
