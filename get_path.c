#include "main.h"

char *get_path(const char *cmd) {
    
        char *token, path[MAX_PATH_SIZE], temp[MAX_PATH_SIZE], *ab_path;
        struct stat stats;
        
        _strcpy(path, get_env("PATH"));
        _strcpy(temp, path);
        token = strtok(temp, ":");
        while (token) {
            ab_path = malloc(strlen(token) + strlen(cmd) + 2);
            if (!ab_path) {
                perror("failed to allocate memory\n");
                return (NULL);
            }
            _strcpy(ab_path, token);
            _strcat(ab_path, "/");
            _strcat(ab_path, cmd);
            _strcat(ab_path, "\0");
            if (stat(ab_path, &stats) == 0) {
                return (ab_path);
            }
            token = strtok(NULL, ":");
        }
        free(ab_path);
        return(NULL);
    }
