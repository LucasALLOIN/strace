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
//#include <sys/reg.h>
#include <asm/ptrace-abi.h>

int error(int argc, char **argv);
void help(void);
int pid(int argc, char **argv);

#endif
