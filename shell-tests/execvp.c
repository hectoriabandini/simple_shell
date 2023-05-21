#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	char *program_name = "ls";
	char *args[] = {NULL};
	execvp(program_name, NULL);
	return (0);
}
