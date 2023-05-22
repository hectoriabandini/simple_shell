#include "ourshell.h"

int main()
{
	//Read chars from the stream
	char *read_chars;
	//Number of characters read
	size_t nc_read;
	//Buffer to be used by getline()
	size_t init = 0;
	//loop counters
	size_t i;
	//tokens to be copied to the command table
	char *token;
	//Print sign and read characters from stdin
	int buffer_s = CMD_BUF_SIZE;
	while(printf("$") && (nc_read = getline(&read_chars, &init, stdin)) != -1)
	{
		//command table
		char **commands = malloc(buffer_s * sizeof(char *));
		if (!commands)
		{
			fprintf(stderr, "Allocation error");
			exit(EXIT_FAILURE);
		}
		for (i = 0;;read_chars = NULL, i++)
		{
			//Save commands to the command table
			token = strtok(read_chars, " \t\r\n\a");
			commands[i] = token;
			if (commands[i] == NULL)
				break;
			//Reallocate to prevent buffer overflow
			if (i >= buffer_s)
			{
				buffer_s += CMD_BUF_SIZE;
				commands = realloc(commands, buffer_s * sizeof(char *));
				if(!commands)
				{
					fprintf(stderr, "Allocation error\n");
					exit(EXIT_FAILURE);
				}
			}
		}
		externals_boiler(commands);
		free(read_chars);
		free(commands);
	}
	return (0);
}
