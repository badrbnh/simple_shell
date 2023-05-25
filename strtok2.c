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


/**
 * _strpbrk - function that searches a string for any of a set of bytes
 * @s: string in which the character is to be found
 * @accept: character to be found
 * Return: pointer to the first occurrence of the character c
 * or NULL if not found
 */
char *_strpbrk(char *s, char *accept)
{
int j;
while (*s)
{
j = 0;
while (*(accept + j))
{
if (*s == *(accept + j))
{
return (s);
}
j++;
}
s++;
}
return (0);

}


/**
 * _strspn - function that gets the length of a prefix substring
 * @s: main 1st argument
 * @accept: 2nd argument
 * Return: number of bytes in the initial segment of s which
 * consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int m = 1, n = 0;
int i = 0, j;
while (s[i])
{
if (m == 0)
{
return (n);
}
j = 0;
while (accept[j])
{
if (s[i] == accept[j])
{
n++;
m = 1;
break;
}
j++;
m = 0;
}
i++;
}

return (n);
}


/**
 * _strstr - function that locates a substring
 * @haystack: string in which the character is to be found
 * @needle: character to be found
 * Return: pointer to the beginning of the located substring
 * or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
while (*haystack)
{
char *p1 = haystack;
char *p2 = needle;
while (*p1 == *p2 && *p2 != '\0')
{
p1++;
p2++;
}
if (*p2 == '\0')
return (haystack);
haystack++;
}
return (0);
}
