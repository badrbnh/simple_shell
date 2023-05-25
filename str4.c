#include "main.h"

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
