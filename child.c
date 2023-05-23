#include "ourshell.h"
/**
 * child_exec - A function to engage a new process
 * @commands: A pointer to a string of commands
 * Return: Always success
 */
int child_exec(char **commands)
{
	/**Path to binary file to be executed**/
	char *bin;
	/**Status of child process**/
	int status;
	/**Child process**/

	pid_t wpid,
	bin = commands[0];

	/**Create child**/
	wpid = fork();
	/**externals_boiler(commands);**/
	if (wpid == 0)
	{
		if (execvp(bin, commands) == -1)
		{
			perror("ERROR!");
		};
		exit(EXIT_FAILURE);
	}
	else if (wpid < 0)
	{
		printf("Child creation failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
