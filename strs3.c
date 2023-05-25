#include "shell.h"

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

