#include "shell.h"

/**
 * _command- checks if command exists in PATH
 * @command: input command
 * Return: absolute path of command is exist
*/
char *_command(char *command)
{
    char *value, **paths, *ret = NULL;
    char *name = "PATH", *ncommand;
    char *delim = ":";
    unsigned int i = 0, j, m;
    int len1, len2, total;

    value = _getenv(name);
    paths = _strtok(value, delim);
    ncommand = _malloc(command);
    i = 0;
    len1 = _strlen(ncommand);
    while (paths[i] != NULL)
    {
        len2 = _strlen(paths[i]);
        total = len1 + len2;
        ret = malloc(sizeof(char) * (total + 1));
        if (ret == NULL)
            return (NULL);
        for (j = 0; j < len2; j++)
        {
            ret[j] = paths[i][j];
        }
        m = 0;
        while (j < total)
        {
            ret[j] = ncommand[m];
            m = m + 1;
            j = j + 1;
        }
        ret[j] = '\0';
        if (access(ret, F_OK) == 0)
        {
            return (ret);
        }
        i = i + 1;
        free(ret);
    }
}