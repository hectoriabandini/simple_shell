#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
	//Read chars from the stream
	char *read_chars;
	//Number of characters read
	size_t nc_read;
	//Initail number of chars, to be used by getline()
	size_t init = 0;
	//Command table
	//char **commands = malloc(64 * sizeof(char *));
	//loop counters
	size_t i, j;
	//Child process
	pid_t pid, wpid;
	int status;
	//Path to binary file
	char *bin;
	char *token;
	char *cleantoken;
	//Print sighn and read characters from stdin
	//char *command[] = {NULL};
	while(printf("$") && (nc_read = getline(&read_chars, &init, stdin)) != -1)
	{
		char **commands = malloc(64 * sizeof(char *));
		//Print read characters
		//printf("Chars read = %zd\n", nc_read);
		//Write characters to stdout
		//fwrite(read_chars, nc_read, 1, stdout);
		for (i = 0;;read_chars = NULL, i++)
		{
			//Save commands to the command table
			//char *com = malloc(sizeof(read_chars) + 3);
			//com = strcat(read_chars, " ");
			//token = read_chars;
			token = strtok(read_chars, " \t\r\n\a");
		//	strcpy(commands[i], token);
			commands[i] = token;
			//printf("%s\n", commands[i]);
			//token = strtok(NULL, " ");
			if (commands[i] == NULL)
				break;
			//token = strtok(NULL, " ");
		//	printf("%s\n", commands[i]);
		}
		bin = commands[0];
		//execvp(bin, NULL);
		//for (j = 0; commands[j] != NULL; j++)
		//{
		//	command[j] = strdup(commands[j]);
		//	printf("%s", commands[j]);
		//}
		//command[j] = NULL;
		//Command execution
		//i = 0;
		//while(commands[i] != NULL)
		//{
		//	bin = commands[i];
		//	//printf("%s\t", bin);
		//	i++;
		//}
		//printf("%d", i);
		//bin = commands[0];
		//printf("%s", bin);
		pid = fork();
		//wait(NULL);
		if(pid == 0)
		{
			//bin = strdup(commands[0]);
			//wait(NULL);
			//code to be executed
			//char *ptr = "ls";
			//char *args[] = {"ls", "-la", NULL};
			if (execvp(bin, commands) == -1)
			{
				perror("ERROR!");
			};
			exit(EXIT_FAILURE);
		} else if(pid < 0)
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
		free(read_chars);
		free(commands);
	}
	return (0);
}
