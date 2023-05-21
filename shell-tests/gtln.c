#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	char *lineptr;
	size_t n;
	size_t len = 0;

	while (printf("$ ") && (n = getline(&lineptr, &len, stdin)) != -1)
	{
		printf("Read %zd Characters\n", n);
		fwrite(lineptr, n, 1, stdout);
	}
	return (0);
}
