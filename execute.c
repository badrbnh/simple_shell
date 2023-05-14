#include "main.h"

int execute(char **argv) {
    pid_t id, status;
    if (argv == NULL) {
        return (0);
    }
    if ((id = fork()) == -1) {
        perror("Error while creating a process");
        return (1);
    }
    if (id == 0)    {
        if (execve(argv[0], argv, NULL) == -1) {
            perror("Error while executing command:");
            return(2);
        }
    }
    else {
        if (waitpid(id, &status, 0) == -1) {
            perror("Error : Failed to wait\n");
        }
        else {
            if (WIFEXITED(status)) {
                return (WEXITSTATUS(status));
            }
            else {
                perror("Child process terminated abnormally\n");
                return(-1);
            }
        }
    
        write(1, "Execution success\n", _strlen("Execution success\n"));
    }
    return(0);
}
