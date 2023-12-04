#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

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
  * @stream: Buf or stream to save the input.
  * Return: Always 0 Success.
  */
int read_input(char *command, size_t size, FILE *stream);

/**
  * exe - Execute the shell.
  * @command: Command to execute.
  * @shell: Name of the shell for printing errors.
  * Return: Always 0 Sucess.
  */
int exe(char *command, char *shell);

#endif/* MAIN_H */
