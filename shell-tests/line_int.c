#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_LEN 100
/**
 * main - entry point a UNIX command line interpreter.
 * @ child: PID
 * @buff: Buffer to store user input
 * @my_prompt: print a prompt
 * argc: holds the number of command line arguments passed to the program
 * envp: an array of pointers to character strings
 * argv: an array of pointers to character strings
 */

int main(int argc, char **argv, char **envp)
{
	pid_t child;
	char buf[MAX_LEN];
	int status;
	const char *my_prompt = "> ";

	while(true)
	{
		printf("%s", my_prompt);
		fflush(stdout);

		if (fgets(buf, MAX_LEN, stdin) == NULL)
		{
			break;
		}
		buf[strcspn(buf, "\n")] = '\0';
		child = fork();
		if (child < 0)
		{
			perror("file not found");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			if (execlp(buf, buf, (char *) NULL) == -1)
			{
				printf("%s: No such file or directory\n", buf);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(child, &status, 0);
		}
	}
	return (0);
}
