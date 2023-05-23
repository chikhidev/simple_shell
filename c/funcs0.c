#include "main.h"

int _strlen(char *str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

int is_new_line(char *str)
{
    if (*str == '\n')
        return (1);
    else
        return (0);
}

int has_space(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int is_empty(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_space(char c)
{
    if (c != ' ' && c != '\n' && c != '\t' &&
        c != '\r' && c != '\f')
    {
        return 0;
    }
    return 1;
}