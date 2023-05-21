#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	char *path = "bin/bash";
	char *const args[] = {path, "echo Hello", NULL};
	execve(path, args, NULL);
	return (0);
}
