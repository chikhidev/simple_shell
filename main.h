#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFERSIZE 10

extern char **environ;

int _strlen(char *str);
int is_delim(char s, char *delim);
int is_new_line(char *str);
int has_space(char *str);
int is_empty(char *str);
int is_space(char c);
char *l_strip(char *str);
int handle_env(char *command);
int is_exit(char *command);
int executer(char **args, char *env[]);
void handle_sigint();
int is_delim(char s, char *delim);
const char *my_strchr(const char *s, int c);
char *_strtok(char *s, const char *delim);
int handle_built_in(char *cmd, char *path);
void print_and_exit(char *str, int exit_code);
void process_args(char *arg, char ***args, int *arg_len);
void s_e_cmd(char *cmd, char *epd, char **args, char **eenv, int *les);
int check_and_process_cmd(char **cmd, size_t *bytes);
#endif
