#include <shell.h>

/**
 * _strtok - tokenize string
 * @str: string to be tokenized
 * @del: string of delimiters
 * return: pointer to token, NULL if no token can be estracted
*/


char *_strtok(char *str, const char *del) {
    static char *ptr = NULL;
    int i;
    int chk = 1;
    if (str) {
        ptr = str;
    }

    if (ptr == NULL || *ptr == '\0') {
        return NULL;
    }

    while (ptr++ && chk) {
        i = 0;
        while(del[i]) {
            if (*ptr == del[i]) {
                chk = 0;
                break;    
            }
            i++;
        }
        ptr++;
    }
    ptr += _strspn(ptr, del);

    if (*ptr == '\0') {
        return NULL;
    }

    char *token = ptr;
    ptr = strpbrk(ptr, del);

    if (ptr != NULL) {
        *ptr = '\0';
        ptr++;
    }

    return (token);
}
