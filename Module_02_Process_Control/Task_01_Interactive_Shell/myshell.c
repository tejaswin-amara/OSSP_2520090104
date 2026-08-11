#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

void strip_newline(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS];

    while (1) {
        printf("myShell> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nExiting shell...\n");
            break;
        }

        strip_newline(input);

        if (strlen(input) == 0) {
            continue;
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int i = 0;
        char *token = strtok(input, " ");

        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        if (i == 0) {
            continue;
        }

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }
        else if (pid == 0) {
            if (execvp(args[0], args) < 0) {
                perror("Command execution failed");
            }
            exit(1);
        }
        else {
            int status;
            waitpid(pid, &status, 0);

            printf("Child PID: %d\n", pid);
            printf("Command execution completed.\n");
        }
    }

    return 0;
}
