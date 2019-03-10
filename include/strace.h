/*
** EPITECH PROJECT, 2019
** strace.h
** File description:
** strace
*/

#ifndef STRACE_H_
#define STRACE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <asm/ptrace-abi.h>
#include <sys/user.h>

int error(int argc, char **argv);
void help(void);
int pid(char **argv);
int trace_prog(pid_t pid);
int launch_child(char **argv);
void trace_syscall(struct user_regs_struct *registers, pid_t pid, int *status);

typedef struct syscall_list_s {
    char *name;
    unsigned char arg_nbr;
} syscall_list_t;

#endif
