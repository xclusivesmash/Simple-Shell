#include "./shell.h"

/**
* _strcat - concatenates two strings
* @dest: string to append to
* @src: string to append
* Return: dest
*/
char *_strcat(char *dest, char *src)
{
    int dest_len, i = 0;
    
    if (dest == NULL || src == NULL)
        return (dest);

    dest_len = _strlen(dest);
    /* PUT CONTENTS OF SRC INT DEST */
    while (src[i] != '\0')
    {
        dest[dest_len + i] = src[i];
        i = i + 1;
    }
    /* REMEMBER TO ADD NULL POINTER */
    dest[i] = '\0';
    return (dest);
}