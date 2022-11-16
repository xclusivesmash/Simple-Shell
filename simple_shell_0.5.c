#include "./shell.h"

/**
* main - simple shell
* Return: always 0 (on success)
*/
int main(void)
{
    char *buff = NULL, **tokens, *ret;
    ssize_t nchars;
    char *delim = " ", *flag = "^C";
    bool check = false, trace;
    pid_t pid;
    int status;
    char *value1 = "exit", *value2 = "env";

    while (check == false)
    {
        /* GET INPUT */
        nchars = _getline(&buff);
        buff[nchars - 1] = '\0';

        /* TOKENIZE INPUT */
        tokens =  _strtok(buff, delim);
        if ((_strcmp(tokens[0], value1) == 0) || (_strcmp(tokens[0], value2) == 0))
            built_ins(tokens);
        else
        {
            if (_strcmp(tokens[0], flag) == 0)
            {
                check = true;
                free(buff); free(tokens);
            }
            else
            {
                trace = _path(tokens[0]);
                if (trace == true)
                {
                    ret = _command(tokens[0]);
                    pid = fork();
                    if (pid == 0)
                    {
                        if (execve(ret, tokens, environ) == -1)
                        {
                            perror("./sh");
                            return (1);
                        }
                    }
                    free(ret);
                    wait(&status);
                    free(buff); free(tokens);
                }
                else
                {
                    free(buff); free(tokens);
                    write(STDOUT_FILENO, "./sh: No such file or directory\n", 32);
                }
            }
        }
    }
    free(buff);
    free(tokens);
    return (0);
}