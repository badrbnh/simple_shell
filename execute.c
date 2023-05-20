#include "main.h"

int execute(char **argv) {
    pid_t id, status;
    char *path;
    char **env;
    if (argv == NULL) {
        return(-1);
    }
    if ((id = fork()) == -1) {
        perror("Error while creating a process");
        exit(EXIT_FAILURE);
    }
    if (id == 0)    {
        path = get_path(argv[0]);
        if (path == NULL) {
            perror("Error path not found:");
            return(-1);
        }
        env = get_env_var();
        if (execve(path, argv, env) == -1) {
            perror("Error while executing command:");
            free(path);
            return(-1);
        }
        free(path);
    }
    else {
        if (waitpid(id, &status, 0) == -1) {
            perror("Error : Failed to wait\n");
        }
        else {
            if (WIFEXITED(status)) {
                return (WEXITSTATUS(status));
            }
        }
    }
    return(0);
}
