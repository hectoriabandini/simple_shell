#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CMD_BUF_SIZE 1024

char **tokenize(char *commands)
{
	char *token;
	size_t buffer_s;
        char **cmd;
        size_t i;
        buffer_s = CMD_BUF_SIZE;
        cmd = malloc(1024 * sizeof(char *));
	char *tk = strdup(commands);
        for (i = 0;;commands = NULL, i++)
              {
                      /**Save commands to the command table**/
                      token = strtok(tk, " \t\r\n\a");
                      cmd[i] = token;
                      if (cmd[i] == NULL)
                              break;
                        /**Reallocate to prevent buffer overflow**/
                      if (i >= buffer_s)
                      {
                              buffer_s += CMD_BUF_SIZE;
                              cmd = realloc(commands, buffer_s * sizeof(char *));
                              if (!cmd)
                              {
                                      fprintf(stderr, "Allocation error\n");
                                      exit(EXIT_FAILURE);
                              }
                      }
              }
        return (cmd);

}

int main(void)
{
	int i;
	char **mycmd = tokenize("Hello world");
	for (i = 0;mycmd[i] != NULL; i++)
	{
		printf("%s\n", mycmd[i]);
	};
	return (0);
}
