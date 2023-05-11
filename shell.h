#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>


#define MAX_INPUT_SIZE 1024


int execute(char *cmd, char *argv[]);
void hundle_ctrl(int signal);


#endif
