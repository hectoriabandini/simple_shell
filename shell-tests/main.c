#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
void read_command(char cmd[], char *par[])
{
	char line[1024];
	int count = 0, i = 0, j = 0;
	char *array[100], *pch;
	//Read one line
	for (;;)
	{
		int c = fgetc(stdin);
		line[count++] = (char) c;
		if (c == '\n') break;
	}
	if (count == 1) return;
	pch = strtok(line, " \n");

	//Parse the line into words
	while (pch != NULL)
	{
		array[i++] = strdup(pch);
		pch = strtok(NULL, " \n");
	}
	//First word is the command
	strcpy(cmd, array[0]);
	//Other parameters
	for (int j = 0; j < i; j++)
	{
		par[j] = array[j];
		par[i] = NULL;//terminate parameter list
	}
}
void type_prompt()
{
	static int first_time = 1;
	if (first_time)
	{
		const  char* CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";
		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
		first_time = 0;
	}
	printf("$");//display prompt
}

int main()
{
	char cmd[100], command[100], *parameters[20];
	// environment variables
	char *envp
[] = {(char *) "PATH=/bin", 0};
	while (1)
	{
		type_prompt();//Type prompt
		read_command (command, parameters);//Read the coommand
		if (fork() != 0)//parent
		{
			wait(NULL);//wait for child
		}
		else
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
			execve(cmd, parameters, envp);//execute
		}
		if (strcmp(command, "exit") == 0)
			break;
	}
	return (0);
}
