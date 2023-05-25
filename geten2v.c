#include "shell.h"

char *get_env(const char *var) {
        extern char **environ;
        char *path = NULL, *token, *rval;
        int len = 0;
        if (var == NULL) {
            return (NULL);
        }
        while (environ[len]) {
            if (ncontain(var, environ[len])) {
                path = _strdup(environ[len]);
                if (path == NULL) {
                    free(path);
                    return (NULL);
                }
                token = strtok(path, "=");
                if (token) {
                    token = strtok(NULL, "\0");
                    rval = _strdup(token);
                    if (rval == NULL) {
                        free(rval);
                        free(path);
                        return (NULL);
                    }
                    }
                    free(path);
                    return (rval); /*memory leak problem*/
            }
            len++;
        }
        free(path);
        return (NULL);
    }

char **get_env_var(void) {
        extern char **environ;
        char **lenviron;
        int i, len = 0;
        while (environ[len]) {
            len++;
        }
        lenviron = (char **)malloc(((sizeof(char *) * len) + 1));
        if (lenviron == NULL) {
            perror("failed to allocate memory\n");
            return (NULL);
        }
        for (i = 0; i < len; i++) {
            lenviron[i] = environ[i];
        }
        lenviron[len] = NULL;
        return(lenviron);
        
    }
