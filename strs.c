i#include "main.h"

size_t _strlen(const char *str) {
    size_t len = 0;
    while (str[len]) {
        len++;
    }
    return (len);
}

int ncontain(const char *bigstr, const char *smlstr) {
    
    size_t len = _strlen(smlstr);
    int i;
    
    for (i = 0; i < len && bigstr[i] && smlstr[i]; i++) {
        if (bigstr[i] != smlstr[i]) {
            return (0);
        }
    }
    return (1);
}

char *_strcat(char *dest, const char *src)
{
int i = 0, n = 0;
while (dest[i])
{
i++;
}
while (src[n])
{
dest[i] = src[n];
n++;
i++;
}
dest[i] = src[n];
return (dest);
}

char *_strcpy(char *dest, const char *src)
{
int i = 0;
while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = src[i];
return (dest);
}

char *_strdup(char *str)
{
unsigned int size = 1, i = 0;
char *new_str;
if (str == 0)
return (0);
while (str[size])
{
size++;
}
if (size == 0)
return (0);
new_str = malloc(sizeof(char) * (size + 1));
if (new_str == 0)
return (0);
while (i <= size)
{
new_str[i] = str[i];
i++;
}
return (new_str);
}

int _strcmp(char *s1, char *s2)
{
int i = 0, n;
while (s1[i] != '\0')
{
n = s1[i] - s2[i];
if (n != 0)
{
break;
}
i++;
}
n = s1[i] - s2[i];
return (n);
}
