#include "ourshell.h"
/**
 * main - entry point
 *
 * Return: always success
 */

int main(int argc, char *argv[])
{
	char *read_chars;
	//ssize_t nc_read;
	size_t init = 0;
	int i;
	char **commands;
	char *constant = "-c";
	char *path = "/bin/sh";
	char *token;
	int buffer_s = CMD_BUF_SIZE;

	//extern char **environ;
	//char **env_list = environ;
	//nc_read = getline(&read_chars, &init, stdin);
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
//		execve(path, commands, env_list);
//
//		for (i = 2;;read_chars = NULL, i++)
//		{
//			/**Save commands to the command table**/
//			token = strtok(read_chars, " \t\r\n\a");
//			commands[i] = token;
//			if (commands[i] == NULL)
//				break;
			/**Reallocate to prevent buffer overflow**/
//			if (i >= buffer_s)
//			{
//				buffer_s += CMD_BUF_SIZE;
//				commands = realloc(commands, buffer_s * sizeof(char *));
//				if (!commands)
//				{
//					fprintf(stderr, "Allocation error\n");
//					exit(EXIT_FAILURE);
//				}
//			}
//		}
		externals_boiler(commands, argv);
		free(commands);
	}
	return (0);
}
