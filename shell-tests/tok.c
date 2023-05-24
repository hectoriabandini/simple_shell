#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *string = "cd /usr/bin";
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
	printf("%s\n", dir);
        //chdir(dir);
        return 1;
}
