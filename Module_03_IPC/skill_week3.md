Task 1: To Create Main Loop, Display Prompt, Read User Input, Handle Exit Conditions, Design Control Flow Diagram, Test Interactive Loop



Task 2: Using the following system calls, copy the content from File1.txt to File2.txt. 

Open()

Read()

Write()

Close()

open()

	syntax: open(“ filename.txt”, modes, permissons)

	Example: open(“First_Prgm.txt”, O_CREAT | O_WRONLY, 0644);

	

Table 1: Modes of Open system call

Flag

Purpose

O_RDONLY

Open for read only

O_WRONLY

Open for write only

O_RDWR

Open for both read and write

O_CREAT

Create file if it does not exist

O_TRUNC

Truncate (empty) an existing file

O_APPEND

Append data to the end of the file

O_EXCL

Fail if file already exists (used with O_CREAT)



read()

	Syntax: read(int fd, void *buf, size_t count);

	Example: read(fd, buffer, 100)

	#include <stdio.h>

#include <unistd.h>

int main()

{

    char buffer[100];

    int n;

    printf("Enter some text: ");

    n = read(0, buffer, sizeof(buffer) - 1);

    buffer[n] = '\0';   // Null-terminate the string

    printf("You entered: %s", buffer);

    return 0;

}

	

write()

	Syntax: write(int fd, const void *buf, size_t count);

	Example: write(fd, message, 11);

	#include <unistd.h>

int main()

{

    write(1, "Hello World\n", 12);

    return 0;

}