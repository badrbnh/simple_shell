#include "shell.h"

/**
 * _strncmp - compare a number of chars of 2 strings
 * @str1: string to be compared
 * @str2: string to be compared
 * @len: number of chars to be compared
 * return: 0 if equals, or the the diff of ASCII value
*/

int _strncmp(const char * str1, const char * str2, size_t len)
{
    while ( len && *str1 && ( *str1 == *str2 ) )
    {
        --len;
        ++str1;
        ++str2;
    }
    if (len == 0)
    {
        return 0;
    }
    else
    {
        return (*str1 - *str2);
    }
}
