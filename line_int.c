#include "ourshell.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: always success
 */

int _main(__attribute__((unused)) int argc, char *argv[])
{
	char *read_chars;
	/**ssize_t nc_read;**/
	size_t init = 0;
	char **commands;
	char *constant = "-c";
	char *path = "/bin/sh";
	int buffer_s = CMD_BUF_SIZE;
	ssize_t nc_read;

	while (1)
	{
		prompt();
		nc_read = getline(&read_chars, &init, stdin);

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
	free(read_chars);
	return (0);
}
