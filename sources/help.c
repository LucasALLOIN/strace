/*
** EPITECH PROJECT, 2019
** help.c
** File description:
** help
*/

#include "strace.h"

int error(int argc, char **argv)
{
    if (argc <= 1) {
        printf("no argument, see --help\n");
        return 1;
    }
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        help();
        return 0;
    }
    return 0;
}


void help(void)
{
    printf("USAGE: ./strace [-s] [-p <pid>|<command>]\n");
}