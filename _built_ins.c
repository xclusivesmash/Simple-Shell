#include "./shell.h"

/**
* built_ins - handles built-in commands
* @tokens: array of arguments
* Return: nothing
*/
void built_ins(char **tokens)
{
    char *value1 = "exit";
    char *value2 = "env";
    int i;


    if (_strcmp(tokens[0], value1) == 0)
    {
        /* EXIT BUILT-IN */
        _exit(0);
    }
    else if (_strcmp(tokens[0], value2) == 0)
    {
        /* ENV BUILT-IN */
        i = 0;
        while (environ[i] != NULL)
        {
            write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
            write(STDOUT_FILENO, "\n", 1);
            i = i + 1;
        }
    }
}