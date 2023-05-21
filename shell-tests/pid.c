#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	pid_t pid = fork();
	if (pid == 0)
	{
		printf("Parent created");
	}
	if (pid > 0)
	{
		printf("Child created");
	}
	return (0);
}
