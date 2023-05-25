#include "main.h"

/**
 * _print_str - prints a string
 * @s: string
 * @fd: buffer
 */
void _print_str(char *s, int fd)
{
	write(fd, s, _strlen(s));
}

/**
* handler_function - Handle the SIGINT signal (Ctrl+C)
* @i: int
* return: nothin
*/
void handler_function(int i __attribute__((unused)))
{
	_print_str("\n$ ", 1);
}

