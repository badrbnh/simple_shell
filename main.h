#ifndef MAIN_H
#define MAIN_H

#define MAX_PATH_SIZE 1024

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


size_t _strlen(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);
char *get_env(const char *var);
char **get_env_var(void);
char *get_path(const char *cmd);
int ncontain(const char *bigstr, const char *smlstr);
char **str_split(char *str);
int execute(char **argv);
int prompt(void);

#endif
