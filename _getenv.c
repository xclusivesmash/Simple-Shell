#include "shell.h"

/**
 * _getenv - searches environment list for name
 * and return the value of the variable name
 * @name: name of the variable to search for
 * Return: pointer to the corresponding value
*/
char *_getenv(const char *name)
{
    char *value = NULL, *token;
    unsigned int i = 0, j = 0, m = 0, k = 0;

    while (environ[i] != NULL)
    {
        value = malloc(sizeof(char) * (strlen(environ[i]) - strlen(name)) + 1);
        if (value == NULL)
            return (NULL);
        /* PERFORM STRING COMPARISON */
        while (environ[i][j] == name[j])
        {
            if (name[j + 1] == '\0')
            {
                /* GET TO THE INDEX OF = */
                while (environ[i][m] != '=')
                {
                    m = m + 1;
                }
                /* LOOP THROUGH AND COPY CHARACTERS */
                while (environ[i][m + 1] != '\0')
                {
                    value[k] = environ[i][m + 1];
                    k = k + 1;
                    m = m + 1;
                }
                /* DON'T FORGET THE NULL BYTE AT THE END*/
                value[k] = '\0';
                return (value);
            }
            j = j + 1;
        }
        i = i + 1;
        free(value);
    }
}