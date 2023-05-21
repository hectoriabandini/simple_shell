#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 * vfork - creates a child process that blicks the parent
 */
int main()
{
	pid_t stat;
	stat = vfork();
	printf("Parent with id %d excecuting\n", getpid());
	if (stat == 0)
	{
		printf("Child with is %d has overidden parent\n", getpid());
	}
}
