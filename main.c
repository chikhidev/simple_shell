#include "main.h"

/**
* is_delim - Check if a character is a delimiter
* @s: The character to check
* @delim: The delimiter string
*
* Return: 1 if the character is a delimiter, 0 otherwise
*/
int is_delim(char s, char *delim)
{
int i = 0;
while (delim[i])
{
if (s == delim[i])
{
return (1);
}
i++;
}
return (0);
}

/**
* handle_input - Handle user input and execute commands
* @cmd: User input command
* @environ: Array of environment variables
*/
void handle_input(char *cmd, char **environ)
{
char *arg, **args = malloc(sizeof(char *) * 2);

cmd = l_strip(cmd);
arg = strtok(cmd, " \n");
if (arg != NULL && arg[0] == '/')
{
if (arg[0] == '/' && !arg[1])
{
printf("Permission denied\n");
exit(1);
}

args[0] = arg;
args[1] = NULL;
executer(args, environ);
free(args);
}
}

/**
* shell_loop - The main loop of the shell
* @environ: Array of environment variables
*/
void shell_loop(char **environ)
{
size_t size = 50;
char *cmd = malloc(size);
ssize_t bytes;
int running = 1;

while (running)
{
if (isatty(STDIN_FILENO))
_print_str("#cisfun$ ", 1);
else
running = 0;

signal(SIGINT, handler_function);
if (signal(SIGINT, SIG_IGN) == SIG_ERR)
{
perror("signal");
exit(1);
}

bytes = getline(&cmd, &size, stdin);

if (bytes == -1)
{
printf("\nexit\n");
exit(1);
}

if (is_empty(cmd) || is_new_line(cmd))
continue;

handle_input(cmd, environ);
}

free(cmd);
}

/**
* main - Entry point of the program
* @argc: Number of command-line arguments
* @argv: Array of command-line argument strings
* @environ: Array of environment variables
*
* Return: Always 0
*/
int main(int argc, char **argv, char **environ)
{
char *path = malloc(50);

(void)argc;
(void)argv;

shell_loop(environ);

free(path);

return (0);
}

