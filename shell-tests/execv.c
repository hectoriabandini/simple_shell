#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char *args[] = {"./execvp", NULL};
	execv(args[0], args);
	return (0);
}
