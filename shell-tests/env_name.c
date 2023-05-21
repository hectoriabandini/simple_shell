#include <stdlib.h>
#include <stdio.h>

int main()
{
	char env_name[50];
	printf("Environment var name: ");
	scanf("%s", env_name);
	printf("Value is: %s", getenv(env_name));
	return (0);
}
