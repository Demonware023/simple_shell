#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
  * marve_print - built printf function
  * @amessage: message to be displayed by the built printf function.
  * Return: void.
  */
void marve_print(const char *amessage);

/**
  * infinite_prompt - blinking prompt.
  * @void: This takes void as an argument.
  * Return: void.
  */
void infinite_prompt(void);

/**
  * read_input - reads user input from the keyboard.
  * @command: command passed.
  * @size: size of commands
  * Return: Always 0 Success.
  */
int read_input(char **command, size_t *size);

/**
  * exe - Execute the shell.
  * @command: Command to execute.
  * @argv: Name of the shell for printing errors.
  * @envp: enviroment variable.
  * Return: Always 0 Sucess.
  */
int exe(char *command, char *argv[], char *envp[]);

/**
  * print_error - function to print error messages.
  * @argv: argv[0] is the name of the program.
  * @args: args[0] is the command taht was attempted to execute.
  * Return: void.
  */
void print_error(char *argv[], char *args[]);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
int arg_handler(char *command, char *argv[], char *envp[]);
int path_handler(char *command, char *argv[], char *envp[]);

#endif/* MAIN_H */
