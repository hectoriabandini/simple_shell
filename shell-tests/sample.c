#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int parseArguments(char *command, char **arguments) {
    int argCount = 0;
    char *token = strtok(command, " ");

    while (token != NULL) {
        arguments[argCount++] = token;
        token = strtok(NULL, " ");
    }

    return argCount;
}

void executeCommand(char **arguments, int inputFd, int outputFd) {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process

        // Set input/output file descriptors
        if (inputFd != STDIN_FILENO) {
            dup2(inputFd, STDIN_FILENO);
            close(inputFd);
        }

        if (outputFd != STDOUT_FILENO) {
            dup2(outputFd, STDOUT_FILENO);
            close(outputFd);
        }

        execvp(arguments[0], arguments);
        printf("Command not found: %s\n", arguments[0]);
        exit(1);
    } else {
        // Parent process
        wait(NULL);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Shell> ");
        fgets(command, sizeof(command), stdin);

        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        // Exit the shell if the user enters "exit"
        if (strcmp(command, "exit") == 0) {
            break;
        }

        int numPipes = 0;
        char *pipeCommands[MAX_ARGUMENTS];

        // Split commands based on pipes
        char *token = strtok(command, "|");

        while (token != NULL) {
            pipeCommands[numPipes++] = token;
            token = strtok(NULL, "|");
        }

        int inputFd = STDIN_FILENO;
        int pipefd[2];

        for (int i = 0; i < numPipes; i++) {
            char *arguments[MAX_ARGUMENTS];
            int argCount = parseArguments(pipeCommands[i], arguments);

            if (i < numPipes - 1) {
                // Create pipe
                if (pipe(pipefd) == -1) {
                    printf("Pipe failed.\n");
                    exit(1);
                }

                // Set output file descriptor to the write end of the pipe
                int outputFd = pipefd[1];
                executeCommand(arguments, inputFd, outputFd);

                // Set input file descriptor to the read end of the pipe for the next command
                inputFd = pipefd[0];

                // Close the write end of the pipe
                close(outputFd);
            } else {
                // Last command, no need for piping
                executeCommand(arguments, inputFd, STDOUT_FILENO);
            }
        }
    }

    return 0;
}
