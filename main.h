#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

size_t _strlen(const char *str);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);
int ncontain(const char *bigstr, const char *smlstr);
void handle_path(char **ab_path);
char **str_split(char *str);
int execute(char **argv) ;
int prompt(void);

#endif
