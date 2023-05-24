#include "simple.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: always success
 */
int main(int argc, char *argv[])
{
	char *path = "/bin/sh";
	pid_t child;
	int status;
	char *myfile = argv[0];
	char **env_list = environ;
	char *commands[] = {myfile, "-s", NULL};

	if (argc == 0)
	{
		exit(0);
	}
	child = fork();
	if (child == 0)
	{
		execve(path, commands, env_list);
	} else
	{
		wait(&status);
	}
	return (0);
}
