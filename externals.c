#include "ourshell.h"
/**
 * chdr - change dirrectory
 * @commands: recieves user command
 * Return: returun success
 */

int chdr(char **commands)
{
	char *string = commands[2];
	char *dir;
	size_t i = 0;
	char *command = malloc(strlen(string) * sizeof(char) + 1);

	strcpy(command, string);
	for (i = 0; i < 2; command = NULL, i++)
	{
		dir = strtok(command, " \n\a\r\t");
		if (i == 1)
			break;
	}
	if (dir == NULL)
	{
		chdir("$HOME");
	} else
	{
		chdir(dir);
	}
	return (1);
}

/*****Exit function******/
/**
 * ext - exit funcion
 * @commands: recieves user commands
 * Return: always success
 *
 */

int ext(char **commands)
{
	free(commands);
	exit(EXIT_SUCCESS);
}
/**
 * _env - environment function
 * @commands: recieves user commands
 * Return: always success
 */
int _env(char **commands)
{
	char **env_list = environ;

	while (*env_list != NULL)
	{
		fprintf(stdout, "%s\n", *env_list);
		env_list++;
	}
	return (0);
}

int (*externals_exec[])(char **) = {
	&chdr,
	&ext,
	/*	&_setenv,*/
	/*	&_unsetenv,*/
	&_env
};
/**
 * externals_boiler - controls the external function
 * @argv: argument vector
 * @commands: recieve commands
 * Return: args
 */
int externals_boiler(char **commands, char *argv[])
{
	size_t i;
	size_t ext_count = sizeof(externals) / sizeof(char *);
	char *string = commands[2];
	size_t j;
	char *command;
	char *cmd = malloc(strlen(string) * sizeof(char) + 1);

	strcpy(cmd, string);
	for (j = 0; j < 2; string = NULL, j++)
	{
		if (j == 1)
			break;
		command = strtok(cmd, " \n\a\r\t");
	}
	if (command == NULL)
	{
		return (1);
		prinf("command does not exist");
	}

	for (i = 0; i < ext_count; i++)
	{
		if (strcmp(command, externals[i]) == 0)
		{
			return ((*externals_exec[i])(commands));
		}
	}

	return (child_exec(commands, argv));
}
