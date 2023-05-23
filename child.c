#include "ourshell.h"
/**
 * child_exec - A function to engage a new process
 * @commands: A pointer to a string of commands
 * Return: Always success
 */

int child_exec(char **commands)
{
	char *bin = commands[0];
	int status;
	pid_t wpid;

	wpid = fork();

	if (wpid == 0) {
		if (execvp(bin, commands) == -1) {
			perror("ERROR!");
		}
		exit(EXIT_FAILURE);
	}
	else if (wpid < 0) {
		printf("Child creation failed");
		exit(EXIT_FAILURE);
	}
	else {
		do {
			wpid = waitpid(wpid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
