#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char command[100];
    if (fgets(command, sizeof(command), stdin) != NULL) {
        // Remove newline character from the command
        char *newline = strchr(command, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }
        
        // Fork a child process
        pid_t pid = fork();
        if (pid == -1) {
            fprintf(stderr, "Fork failed\n");
            return 1;
        } else if (pid == 0) {
            // Child process
            char *exec_args[] = {command, NULL};
            
            // Execute the command
            execve(command, exec_args, NULL);
            
            // If execve returns, an error occurred
            fprintf(stderr, "%s: %s: not found\n", argv[0], command);
            _exit(1);
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}
