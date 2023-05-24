#include "main.h"

/**
* s_e_cmd - Search and execute the command
* @cmd: The command to search and execute
* @epd: The duplicated environment path
* @args: The argument array
* @eenv: The execve environment
* @les: The last exit status
*/
void s_e_cmd(char *cmd, char *epd, char **args, char **eenv, int *les)
{
char *dir, *path = NULL;
int exec_status, child_status;
pid_t child_pid;
dir = _strtok(epd, ":");
while ((dir = _strtok(NULL, ":")) != NULL)
{
path = malloc(strlen(dir) + strlen(cmd) + 2);
strcpy(path, dir);
strcat(path, "/");
strcat(path, cmd);
args[0] = path;
if (access(path, F_OK) == 0)
{
child_pid = fork();
if (child_pid == -1)
print_and_exit("fork\n", 1);
else if (child_pid == 0)
{
exec_status = executer(args, eenv);
exit(exec_status);
}
else
{
waitpid(child_pid, &child_status, 0);
*les = WEXITSTATUS(child_status);
break;
}
}
free(path);
path = NULL;
}
}

/**
* handle_built_in - Handle built-in commands
* @cmd: The command to handle
* @path: The path
*
* Return: 0 to continue, 1 to exit
*/
int handle_built_in(char *cmd, char *path)
{
if (handle_env(cmd) == 0)
return (0);
if (is_exit(cmd) == 1)
{
char *exit_status_str = _strtok(NULL, " \n");
if (exit_status_str != NULL)
{
int exit_status = atoi(exit_status_str);
printf("%d\n", exit_status);
free(path);
free(cmd);
exit(exit_status);
}
else
{
free(path);
free(cmd);
exit(0);
}
}
return (1);
}

/**
* print_and_exit - Print a string and exit
* @str: The string to print
* @exit_code: The exit code
*/
void print_and_exit(char *str, int exit_code)
{
printf("%s", str);
exit(exit_code);
}

/**
* check_and_process_cmd - Check and process the command
* @cmd: The command to check and process
* @bytes: The number of bytes read
*
* Return: 0 if the command is empty or a newline, 1 otherwise
*/
int check_and_process_cmd(char **cmd, size_t *bytes)
{
if (signal(SIGINT, SIG_IGN) == SIG_ERR)
print_and_exit("signal", 1);
printf("($) ");
*bytes = getline(cmd, bytes, stdin);
if (*bytes == (size_t)-1)
print_and_exit("\nexit\n", 1);
if (is_empty(*cmd) || is_new_line(*cmd))
return (0);
*cmd = l_strip(*cmd);
return (1);
}

/**
* process_args - Process the arguments
* @arg: The argument
* @args: The argument array
* @arg_len: The length of the argument array
*/
void process_args(char *arg, char ***args, int *arg_len)
{
*arg_len = 1;
while (arg != NULL)
{
arg = _strtok(NULL, " ");
if (arg && *arg != '\0')
{
(*args)[*arg_len] = arg;
(*arg_len)++;
*args = realloc(*args, (*arg_len + 1) * sizeof(char *));
}
}
(*args)[*arg_len] = NULL;
}
