#include "ourshell.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: always success
 */

int main(int argc, char *argv[])
{
	char *read_chars;
	/**ssize_t nc_read;**/
	size_t init = 0;
	int i;
	char **commands;
	char *constant = "-c";
	char *path = "/bin/sh";
	char *token;
	int buffer_s = CMD_BUF_SIZE;

	while (1)
	{
		prompt();
		ssize_t nc_read = getline(&read_chars, &init, stdin);

		if (nc_read == -1)
		{
			exit(0);
		}
		commands = malloc(buffer_s * sizeof(char *));

		if (!commands)
		{
			fprintf(stderr, "Allocation error");
			exit(EXIT_FAILURE);
		}
		commands[0] = path;
		commands[1] = constant;
		commands[2] = read_chars;
		externals_boiler(commands, argv);
		free(commands);
	}
	return (0);
}
