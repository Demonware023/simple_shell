#include "main.h"

/**
  * main - main function/source code.
  * @argc: argument count
  * @argv: strings/commands passed (Argument Vector)
  * @envp: enviroment variable.
  * Return: Always 0 Success.
  */
int main(int argc, char *argv[], char *envp[])
{
    char *command = NULL;
	size_t command_len = 0;
	ssize_t result;
	char **env;
	char *thisEnv;

	(void)argc;

    while (1)
    {
        infinite_prompt();
        result = get_line(&command, &command_len,stdin);
        
		if (result == -1)
		{
			break;
		}
		if (strlen(command) == 0)
		{
			break;
		}
		else if(strcmp(command, "exit") == 0)
		{
				break;
		}
		else if (strcmp(command, "env") == 0)
		{
			for (env = envp; *env != 0; env++)
			{
				thisEnv = *env;
				write(STDOUT_FILENO, thisEnv, strlen(thisEnv));
				write(STDOUT_FILENO, "\n", 1);
			}
			continue;
		}
		exe(command, argv, envp);
	}

    return (0);
}
