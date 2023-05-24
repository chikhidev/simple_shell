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
 * my_strchr - Locate the first occurrence of a character in a string
 * @s: The string to search
 * @c: The character to locate
 *
 * Return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
const char *my_strchr(const char *s, int c)
{
int i = 0;
while (s[i])
{
if (s[i] == c)
return (&s[i]);
i++;
}
return (NULL);
}

/**
 * _strtok - Split a string into tokens
 * @s: The string to tokenize
 * @delim: The delimiter string
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found
 */
char *_strtok(char *s, const char *delim)
{
static char *olds;
char *token;
if (s == NULL)
{
s = olds;
}
while (*s && my_strchr(delim, *s))
{
++s;
}

if (*s == '\0')
{
return (NULL);
}
token = s;
while (*s && !my_strchr(delim, *s))
++s;
/* Terminate the token and make OLDS point past it. */
*s = '\0';
olds = s + 1;
return (token);
}
