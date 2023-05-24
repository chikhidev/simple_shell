#include "main.h"

/**
 * main - Calculate the length of a string
 *
 * Return: The length of the string
 */

int main()
{
size_t bytes;
char *env_path, *e_p_d, *execve_env[] = {NULL}, *cmd = NULL, **args, *arg;
int last_exit_status = 0, arg_len = 1, exec_status;

signal(SIGINT, handle_sigint);
while (1)
{
if (!check_and_process_cmd(&cmd, &bytes))
continue;
env_path = getenv("PATH");
e_p_d = strdup(env_path);
args = malloc(sizeof(char *) * (arg_len * 2));
args[0] = _strtok(cmd, " \n");
arg = args[0];
cmd[bytes - 1] = '\0';
if (cmd[0] == '/')
{
if (cmd[0] == '/' && !cmd[1])
print_and_exit("Permission denied\n", 1);
process_args(arg, &args, &arg_len);
exec_status = executer(args, execve_env);
if (exec_status == 0)
last_exit_status = WEXITSTATUS(exec_status);
else
printf("Command failed with exit status: %d\n", WEXITSTATUS(exec_status));
}
else if (cmd[0] != '/')
{
if (handle_built_in(cmd, NULL) == 0)
continue;
else
{
process_args(arg, &args, &arg_len);
s_e_cmd(cmd, e_p_d, args, execve_env, &last_exit_status);
}
}
}
free(cmd);
return (last_exit_status);
}

