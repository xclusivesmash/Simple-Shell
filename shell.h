#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <fcntl.h>

/**
 * struct dirs - structure for path directories
 * @directory: path directory
 * @next: pointer to next dir
 * Return: head node
*/
typedef struct dirs
{
    char *directory;
    struct dirs *next;
} list_t;

extern char **environ;

int _putchar(char c);
int _strlen(char *s);
ssize_t _getline(char **buffer);
char **_strtok(char *string, char *delim);
char *_getenv(const char *name);
void built_ins(char **tokens);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
bool _path(char *command);
char *_command(char *command);
char *_malloc(char *string);

#endif /* SHELL_H */