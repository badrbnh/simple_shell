#include "main.h"

void handle_path(char **ab_path) {
    
    const char *path = "/bin/";
    char *full_path = NULL;
    if (!ab_path[0]) {
        return;
    }
    //if ab_path[0] is a full path, do nothing
    //if ab_path[0] is not a full path, add /bin/ at the start of it
    if (!ncontain(ab_path[0], path)) {
        full_path = malloc(_strlen(path) + _strlen(ab_path[0]) + 1);
        if (full_path == NULL) {
            return;
        }
        _strcpy(full_path, path);
        _strcat(full_path, ab_path[0]);
        free(ab_path[0]);
        ab_path[0] = full_path;
    }
    
}
