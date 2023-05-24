#ifndef _OURSHELL_
#define _OURSHELL_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define CMD_BUF_SIZE 1024
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>
#endif
#ifndef _PROTOTYPES
#define _PROTOTYPES
extern char **environ;
int chdr(char **commands);
int ext(char **commands);
int externals_boiler(char **commands, char *argv[]);
int child_exec(char **commands, char *argv[]);
void prompt(void);
#endif
