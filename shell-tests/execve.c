#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	char *path = "/bin/bash";
	extern char **environ;
	char **env_list = environ;
	char *const args[] = {path, "-c", "ls -la", NULL};
	execve(path, args, env_list);
	return (0);
}
