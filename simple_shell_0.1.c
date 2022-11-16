#include "./shell.h"

/**
* main - simple shell
* Return: always 0 (on success)
*/
int main(void)
{
    char *buff = NULL, **tokens;
    ssize_t nchars;
    char *delim = " ", *flag = "^C";
    bool check = false;
    pid_t pid;
    int argc, status;

    while (check == false)
    {
        /* GET INPUT */
        nchars = _getline(&buff);
        buff[nchars - 1] = '\0';

        /* TOKENIZE INPUT */
        tokens =  _strtok(buff, delim);
        argc = 0;
        while (tokens[argc] != NULL)
            argc = argc + 1;
        if (_strcmp(tokens[0], flag) == 0)
        {
            check = true;
            free(buff);
        }
        else
        {
            if (argc != 1)
            {
                write(STDOUT_FILENO, "./sh: No such file or directory\n", 32);
                free(buff);
            }
            else
            {
                pid = fork();
                if (pid == 0)
                {
                    if (execve(tokens[0], tokens, environ) == -1)
                    {
                        perror("./sh");
                        return (1);
                    }
                }
                wait(&status);
                free(buff);
            }
        }
    }
    free(buff);
    return (0);
}