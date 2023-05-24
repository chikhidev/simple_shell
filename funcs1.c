#include "main.h"

/**
* l_strip - Strip leading spaces from a string
* @str: The string to strip
*
* Return: A pointer to the stripped string
*/
char *l_strip(char *str)
{
char *striped = malloc(BUFFERSIZE);
int i = 0, j = 0;
int is_found_char = 0;

if (str[0] && !is_space(str[0]))
{
is_found_char = 1;
striped[j] = str[i];
j++;
i++;
}

while (str[i])
{
if (((j + 1) % BUFFERSIZE) == 0)
striped = realloc(striped, ((j / BUFFERSIZE) + 1) * BUFFERSIZE);

if (is_found_char)
{
striped[j] = str[i];
j++;
}
/* we found a character NOT A SPACE */
if (!is_space(str[i + 1]))
is_found_char = 1;
i++;
}
striped[j] = '\0';
return (striped);
}

/**
* handle_env - Handle the "env" command
* @command: The command to handle
*
* Return: 0 if the command is "env", 1 otherwise
*/
int handle_env(char *command)
{
char **env = environ;

if (strcmp(command, "env") == 0)
{
while (*env)
{
printf("%s\n", *env);
env++;
}
return (0);
}
return (1);
}

/**
* is_exit - Check if a command is "exit"
* @command: The command to check
*
* Return: 1 if the command is "exit", 0 otherwise
*/
int is_exit(char *command)
{
return (strcmp(command, "exit") == 0);
}

/**
* executer - Execute a command
* @args: The command arguments
* @env: The environment variables
*
* Return: 0 on success, or exit with an error
*/
int executer(char **args, char *env[])
{
int status;
pid_t pid;

pid = fork();

if (pid == 0)
{
if (execve(args[0], args, env) == -1)
{
perror("error execve");
exit(1);
}
}
if (pid == -1)
{
perror("error forking");
exit(1);
}
else
{
wait(&status);
}
return (0);
}

/**
* handle_sigint - Handle the SIGINT signal (Ctrl+C)
*/
void handle_sigint(void)
{
/*ignore*/
}

