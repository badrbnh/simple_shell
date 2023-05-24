#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024

extern char **environ;
int execute(char *cmd, char **argv, char **av, char **envp);
void hundle_ctrl(int signal);
int prompt(char **argv, char **envp);
char **split(char *line);
void handle_signal(int signum);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
int path(char *cmd, char **full_path);
void exit_shell(int status);
void print_environment(char **envp);
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _strlen1(const char *str);




#endif
