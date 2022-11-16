#include "./shell.h"

/**
* _strlen - computes the length of string
* @s: input string
* Return: len
*/
int _strlen(char *s)
{
    int len = 0;

    while (*s != '\0')
    {
        len = len + 1;
        s = s + 1;
    }
    return (len);
}