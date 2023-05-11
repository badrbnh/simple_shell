#include "shell.h"

void hundle_ctrl(int signal)
{
    write(1, "\n$ ", 4);
}