/*
** EPITECH PROJECT, 2019
** strace.c
** File description:
** strace
*/

#include "strace.h"

int pid(int argc, char **argv)
{
    pid_t child;
    long orig_rax;
    child = fork();
    char concat[] = "/bin/";
    char *var = getenv("PATH");
    strcat(var, "/");
    strcat(concat, argv[1]);
    if (child == 0) {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execl(concat, argv[1], NULL);
    }
    else {
        wait(NULL);
        orig_rax = ptrace(PTRACE_PEEKUSER, child, 8 * ORIG_RAX);
        printf("The child made a system call %ld\n", orig_rax);
        ptrace(PTRACE_CONT, child, NULL, NULL);
    }
    return 0;
}