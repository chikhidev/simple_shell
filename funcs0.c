#include "main.h"

/**
* _strlen - Calculate the length of a string
* @str: The string
*
* Return: The length of the string
*/
int _strlen(char *str)
{
int i = 0;
while (str[i])
i++;
return (i);
}

/**
* is_new_line - Check if a string starts with a newline character
* @str: The string
*
* Return: 1 if the string starts with a newline, 0 otherwise
*/
int is_new_line(char *str)
{
if (*str == '\n')
return (1);
else
return (0);
}

/**
* has_space - Check if a string contains a space character
* @str: The string
*
* Return: 1 if the string contains a space, 0 otherwise
*/
int has_space(char *str)
{
int i = 0;
while (str[i])
{
if (str[i] == ' ')
return (1);
i++;
}
return (0);
}

/**
* is_empty - Check if a string is empty (contains only spaces)
* @str: The string
*
* Return: 1 if the string is empty, 0 otherwise
*/
int is_empty(char *str)
{
int i = 0;
while (str[i])
{
if (str[i] != ' ')
return (0);
i++;
}
return (1);
}

/**
* is_space - Check if a character is a whitespace character
* @c: The character
*
* Return: 1 if the character is a whitespace, 0 otherwise
*/
int is_space(char c)
{
if (c != ' ' && c != '\n' && c != '\t' && c != '\r' && c != '\f')
return (0);
return (1);
}
