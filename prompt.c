#include "main.h"

int prompt(void) {
    
    int i, cmd = 0;
    size_t len;
    ssize_t chk;
    char *str, **args, cwd[MAX_PATH_SIZE];
    
    while (1) {
        
        chk = -1;
        i = 0;
        len = 0;
        str = NULL;
        if (getcwd(cwd, sizeof(cwd))) {
            _strcat(cwd, "$ ");
        }
        else {
            perror("Couldn't get current working directory\n");
            return (-1);
        }
        while (chk < 2) {
            printf("%s", cwd);
            chk = getline(&str, &len, stdin);
            if (chk == -1) {
                write(1, "Exiting command line\n", _strlen("Exiting command line\n"));
                return (cmd);
            }
        }
        
        args = str_split(str);
        execute(args);
    /*
        while (args [i]) {
    
            printf ("Token %d: %s\n", i, args[i]);
            i++;
        } */
        while (i--) {
            if (args[i]) {
            free(args[i]);}
        }
        if (args) {
            free(args);
        }
        if (str) {
            free(str);
        }
        cmd++;
    }
    return(cmd);
}
