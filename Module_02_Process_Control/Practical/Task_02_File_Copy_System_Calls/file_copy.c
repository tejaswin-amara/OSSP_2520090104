#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main(void) {
    int src, dest;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    src = open("File1.txt", O_RDONLY);
    if (src < 0) {
        perror("Error opening File1.txt");
        return 1;
    }

    dest = open("File2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        perror("Error opening File2.txt");
        close(src);
        return 1;
    }

    while ((bytes_read = read(src, buffer, sizeof(buffer))) > 0) {
        ssize_t total_written = 0;

        while (total_written < bytes_read) {
            ssize_t bytes_written = write(
                dest,
                buffer + total_written,
                bytes_read - total_written
            );

            if (bytes_written < 0) {
                perror("Error writing to File2.txt");
                close(src);
                close(dest);
                return 1;
            }

            total_written += bytes_written;
        }
    }

    if (bytes_read < 0) {
        perror("Error reading File1.txt");
        close(src);
        close(dest);
        return 1;
    }

    if (close(src) < 0) {
        perror("Error closing File1.txt");
        close(dest);
        return 1;
    }

    if (close(dest) < 0) {
        perror("Error closing File2.txt");
        return 1;
    }

    printf("File copied successfully from File1.txt to File2.txt.\n");
    return 0;
}
