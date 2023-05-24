#include "ourshell.h"
/**
 * our_getline - checks for end of line
 * Return: always success
 */

char *our_getline(void)
{
	char buffer[CMD_BUFFER_SIZE];
	size_t buffer_index = 0;
	ssize_t chars_in_buffer = 0;

	char *liner = NULL;
	size_t line_index = 0;
	char current_char;

	while (1)
	{
		if (buffer_index >= chars_in_buffer)
		{
			buffer_index = 0;
			chars_in_buffer = read(STDIN_FILENO, buffer, CMD_BUFFER_SIZE);
			if (chars_in_buffer <= 0)
			{
				break;
			}
		}

		current_char = buffer[buffer_index++];
		if (current_char == '\n' || current_char == '\0')
		{
			break;
		}
		liner = realloc(liner, (line_index + 1) * sizeof(char));
		liner[line_index++] = current_char;
	}
	liner = realloc(liner, (line_index + 1) * sizeof(char));
	liner[line_index] = '\0';

	return (liner);
}
