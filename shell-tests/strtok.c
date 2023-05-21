#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char *str = strdup("ls lk");
	int i;
	char *token;
	for (i = 1; ;i++, str = NULL)
	{
		token = strtok(str, "");
		if (token == NULL)
			break;
		printf("%s\n", token);
	}
	return (0);
}
