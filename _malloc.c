#include "shell.h"

/**
* _malloc - mallocs some spaces and put characters
* @string: input string
* Return: pointer to string
*/
char *_malloc(char *string)
{
    char *new = NULL;
    int len, i;

    if (!(_strcmp(&string[0], "/") == 0))
    {
        len = _strlen(string);
        new = malloc(sizeof(char) + (len + 1));
        if (new == NULL)
            return (NULL);
        new[0] = '/';
        for (i = 1; i <= len; i++)
            new[i] = string[i - 1];
        new[i] = '\0';
        return (new);
    }
    return (string);
}