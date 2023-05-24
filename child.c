#include "ourshell.h"
/**
 * child_exec - A function to engage a new process
 * @commands: A pointer to a string of commands
 * Return: Always success
 */

int child_exec(char **commands, char *argv[])
{
	char *bin = commands[0];
	int status;
	pid_t wpid;
	extern char **environ;
	char **env_list = environ;

	wpid = fork();

	if (wpid == 0) {
		commands[0] = argv[0];
		if (execve(bin, commands, env_list) == -1)
		{
			exit(EXIT_FAILURE);
		}
		fflush(stdout);
	}
	else if (wpid < 0) {
		fprintf(stderr, "Child creation failed\n");
		exit(EXIT_FAILURE);
	}
	else {
		do {
			wpid = waitpid(wpid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		//waitpid(wpid, &status, 0);
	}

	return (1);
}
