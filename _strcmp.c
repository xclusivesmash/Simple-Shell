#include "./shell.h"

/**
* _strcmp - compares two strings
* @s1: first string
* @s2: second string
* Return: int
*/
int _strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i])
    {
        i = i + 1;
    }
    if (s2[i])
    {
        /* s1 < s2 OR VICE VERSA */
        return (s1[i] - s2[i]);
    }
    else
    {
        /* MATCHING STRINGS */
        return (0);
    }
}