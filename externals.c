#include "ourshell.h"
char *externals[] = {
	"cd",
	"exit"
};

int chdr(char **commands)
{
	chdir(commands[1]);
	return 1;
}

int ext(char **commands)
{
	free(commands);
	exit(0);
}


int (*externals_exec[])(char **) = {
	&chdr,
	&ext
};

int externals_boiler(char **commands)
{
	size_t i;
	size_t ext_count = sizeof(externals) / sizeof(char *);

	if (commands[0] == NULL) {
		return 1;
	}

	for (i = 0; i < ext_count; i++) {
		if (strcmp(commands[0], externals[i]) == 0) {
			return (*externals_exec[i])(commands);
		}
	}

	return child_exec(commands);
}
