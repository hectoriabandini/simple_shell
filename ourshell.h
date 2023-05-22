#ifndef _OURSHELL_
#define _OURSHELL_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define CMD_BUF_SIZE 1024
#include <string.h>
#include <sys/wait.h>
#endif
int chdr(char **commands);
int ext(char **commands);
int externals_boiler(char **commands);
int child_exec(char **commands);
