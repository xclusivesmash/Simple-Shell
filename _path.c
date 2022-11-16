#include "shell.h"

/**
 * _path - checks if command exists in PATH
 * @command: input command
 * Return: true if exist, false otherwise
*/
bool _path(char *command)
{
    char *value, **paths, *ncommand;
    char *name = "PATH";
    char *delim = ":";
    unsigned int i = 0, j, k, m = 0;
    bool check = false;

    value = _getenv(name);
    paths = _strtok(value, delim);
    ncommand = _malloc(command);
    while (paths[i] != NULL)
    {
        if (_strcmp(paths[i], ncommand) == 0)
        {
            check = true;
            break;
        }
        i = i + 1;
    }
    if (!check)
    {
        j = 0;
        while (paths[j] != NULL)
        {
            k = 0;
            while (paths[k] != NULL)
            {
                if (_strcmp(_strcat(paths[j], ncommand), paths[k]) == 0)
                {
                    check = true;
                    return (check);
                }
                k = k + 1;
            }
            j = j + 1;
        }
    }
    return (check);
}
