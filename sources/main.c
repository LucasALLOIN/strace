/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <ctype.h>
#include "strace.h"

int rpid = 0;

int trace_prog(pid_t pid)
{
    int status;
    struct user_regs_struct	registers;
    long instr;
    int ret = 0;

    waitpid(pid, &status, 0);
    while (1) {
        if (ptrace(PTRACE_GETREGS, pid, NULL, &registers) == -1)
            return (++ret);
        instr = ptrace(PTRACE_PEEKTEXT, pid, registers.rip, 0);
        if ((instr & 0xffff) == 0x050F)
            trace_syscall(&registers, pid, &status);
        if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1)
            return (ret);
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) || WIFSIGNALED(status))
            break;
    }
    return (0);
}

int pid(char **argv)
{
    pid_t child;

    child = fork();
    if (child == -1)
        return 1;
    if (child == 0)
        return launch_child(argv);
    else
        return trace_prog(child);
}

void sig_handler(int sig)
{
    (void) sig;
    ptrace(PTRACE_DETACH, rpid, NULL, NULL);
    ptrace(PTRACE_CONT, rpid, NULL, NULL);
    fprintf(stderr, "strace: Process %d detached\n", rpid);
    exit(84);
}

int strace_by_pid(char *pid)
{
    int mpid = atoi(pid);

    for (int i = 0; pid[i]; i++) {
        if (!isdigit(pid[i])) {
            fprintf(stderr, "strace: Invalid process id: '%s'",pid);
            exit (84);
        }
    }
    if (ptrace(PTRACE_ATTACH, mpid, NULL, NULL) == -1) {
        fprintf(stderr,
        "strace: attach: ptrace(PTRACE_SEIZE, %d): No such process", mpid);
        exit(84);
    }
    rpid = mpid;
    return (trace_prog(mpid));
}

int main(int argc, char **argv)
{
    int ret = 0;

    error(argc, argv);
    if (strncmp(argv[1], "-", 1) == 0) {
        if (strcmp(argv[1], "-p") == 0 && argc >= 3) {
            signal(SIGINT, &sig_handler);
            signal(SIGTERM, &sig_handler);
            signal(SIGQUIT, &sig_handler);
            ret = strace_by_pid(argv[2]);
        } else
            fprintf(stderr, "strace: invalid option -- '%c'\nTry 'strace -h'"
            " for more information.\n", argv[1][1]);
    } else {
        signal(SIGINT, &sig_handler);
        signal(SIGTERM, &sig_handler);
        signal(SIGQUIT, &sig_handler);
        ret = pid(argv);
    }
    fprintf(stderr, "+++ exited with %d +++\n", ret);
    return (0);
}