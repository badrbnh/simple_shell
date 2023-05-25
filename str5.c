#include "main.h"

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
