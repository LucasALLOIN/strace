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
        fprintf(stderr, "no argument, see --help\n");
        exit(1);
    }
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        help();
        exit(0);
    }
    return 0;
}

void help(void)
{
    fprintf(stderr, "USAGE: ./strace [-s] [-p <pid>|<command>]\n");
}