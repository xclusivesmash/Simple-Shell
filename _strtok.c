#include "./shell.h"

/**
 * _strtok - tokenizes a string
 * @string: string to be tokenized
 * Return: array of strings
*/
char **_strtok(char *string, char *delim)
{
    char **tokens, *token;
    int ntokens = 0, i = 0, k = 0;
    size_t m;

    while (string[i] != '\0')
    {
        if (string[i] != ' ' && (string[i + 1] == ' ' || string[i + 1] == '\0'))
            ntokens = ntokens + 1; /* WORD COUNT */
        i = i + 1;
    }
    /* RESERVE SPACE FOR POINTERS TO WORDS */
    tokens = malloc(sizeof(char *) * ntokens + 1);
    if (tokens == NULL)
        return (NULL);

    token = strtok(string, delim);
    while (token != NULL)
    {
        tokens[k] = malloc(sizeof(char) * (strlen(token) + 1));
        if (tokens[k] == NULL)
            return (NULL);
        m = 0;
        while (m < strlen(token))
        {
            tokens[k][m] = token[m];
            m = m + 1;
        }
        tokens[k][m] = '\0';
        k = k + 1;
        token = strtok(NULL, delim);
    }
    tokens[k] = NULL; /* FREE TOKENS WHEN USED */
    return (tokens);
}