#include "./shell.h"

/**
* _putchar - prints out c to stdout
* @c: character
* Return: integer
*/
int _putchar(char c)
{
    return (write(1, &c, 1));
}