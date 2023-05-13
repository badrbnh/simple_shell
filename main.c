#include "shell.h"

int main(int argc, char *argv[])
{
    signal(SIGINT, hundle_ctrl);
    prompt(argv);
    return 0;
}
