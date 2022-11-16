#include "./shell.h"

/**
 * _getline - reads data from stdin
 * @buffer: stores pointer to read text
 * Return: number of characters read
*/
ssize_t _getline(char **buffer)
{
    size_t n = 0;
    ssize_t nchars, nbtys;

    /* PROMPT */
    nbtys = write(STDOUT_FILENO, "stars$ ", 7);
    if (nbtys == -1)
    {
        perror("write");
        return (nbtys);
    }

    nchars = getline(buffer, &n, stdin);

    /* OUTPUT CHECK*/
    if (nchars == -1)
        return (-1);
    return (nchars);
}
