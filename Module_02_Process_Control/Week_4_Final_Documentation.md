# OSSP — Week 4 Final Documentation

**Student:** Tejaswin Amara  
**Repository:** `tejaswin-amara/OSSP_2520090104`  
**Module:** Operating Systems and System Software Programming (OSSP)  

---

# Task 1 — Create Main Loop, Display Prompt, Read User Input, Handle Exit Conditions, Design Control Flow Diagram, Test Interactive Loop

## Objective

Create an interactive shell loop that repeatedly:

1. Displays a shell prompt.
2. Reads a command from the user.
3. Handles end-of-file / input termination.
4. Removes the trailing newline.
5. Ignores empty commands.
6. Recognizes the `exit` command.
7. Tokenizes the command and prepares an argument array.
8. Creates a child process using `fork()`.
9. Executes the command in the child using `execvp()`.
10. Makes the parent wait for the child using `waitpid()`.
11. Displays the child PID and command completion message.
12. Repeats until an exit condition occurs.

## Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        // Display prompt
        printf("myShell> ");
        fflush(stdout);

        // Read input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nExiting shell...\n");
            break;
        }

        strip_newline(input);

        // Check empty command
        if (strlen(input) == 0) {
            continue;
        }

        // Exit built-in command
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Tokenization and argument parsing
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

        // Create child process
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }
        else if (pid == 0) {
            // Child Process
            if (execvp(args[0], args) < 0) {
                perror("Command execution failed");
            }
            exit(1);
        }
        else {
            // Parent Process
            int status;
            waitpid(pid, &status, 0);
            printf("Child PID: %d\n", pid);
            printf("Command execution completed.\n");
        }
    }

    return 0;
}
```

## Compilation and Execution

```bash
mkdir simple_shell
cd simple_shell
nano myshell.c
gcc -o myshell myshell.c
./myshell
```

## Test 1 — `echo`

```text
myShell> echo Hello
Hello
Child PID: 1964
Command execution completed.
```

## Test 2 — `ls -l`

```text
myShell> ls -l
total 24
-rwxr-xr-x 1 speed speed 16600 Aug 11 06:51 myshell
-rw-r--r-- 1 speed speed  2012 Aug 11 06:51 myshell.c
Child PID: 1967
Command execution completed.
```

The exact PID can change each time the program is executed because it is assigned by the operating system.

## Test 3 — Empty Command

```text
myShell>
myShell>
```

An empty command is ignored and the prompt is displayed again.

## Test 4 — Exit

```text
myShell> exit
```

The shell terminates when the built-in `exit` command is entered.

## Test 5 — EOF

If input reaches EOF, the shell displays:

```text
Exiting shell...
```

and terminates.

---

## Control Flow Diagram

```mermaid
flowchart TD
    A([Start]) --> B[Initialize input and argument arrays]
    B --> C[Display myShell prompt]
    C --> D[Read user input]
    D --> E{EOF / input failure?}
    E -- Yes --> F[Display Exiting shell]
    F --> Z([End])
    E -- No --> G[Remove trailing newline]
    G --> H{Input empty?}
    H -- Yes --> C
    H -- No --> I{Input is exit?}
    I -- Yes --> Z
    I -- No --> J[Tokenize command]
    J --> K[Create NULL-terminated argument array]
    K --> L{fork()}
    L -- Failure --> M[Display fork error]
    M --> Z
    L -- Child --> N[execvp(command, args)]
    N --> O{Execution successful?}
    O -- No --> P[Display execution error]
    P --> Q[Child exits]
    O -- Yes --> R[Command runs]
    R --> Q
    L -- Parent --> S[waitpid(child)]
    S --> T[Display child PID]
    T --> U[Display command execution completed]
    U --> C
```

## Screenshot Evidence

**Screenshot 1 — Source code**  
Keep the provided screenshot showing the `myshell.c` implementation in the terminal editor.

> Insert/keep screenshot here: `screenshot-01-myshell-code.png`

**Screenshot 2 — Compilation and execution**  
Keep the provided terminal screenshot showing:

- `mkdir simple_shell`
- `cd simple_shell`
- `nano myshell.c`
- `gcc -o myshell myshell.c`
- `./myshell`
- `echo Hello`
- `ls -l`
- Child PID output
- Command execution completed message

> Insert/keep screenshot here: `screenshot-02-myshell-output.png`

## Result

The interactive shell loop was successfully implemented and tested. The program accepts commands, handles exit conditions, tokenizes input, creates a child process, executes commands using `execvp()`, waits for completion using `waitpid()`, and returns to the prompt for the next command.

---

# Task 2 — Copy File1.txt to File2.txt Using System Calls

## Objective

Using the following system calls, copy the content from `File1.txt` to `File2.txt`:

1. `open()`
2. `read()`
3. `write()`
4. `close()`

The program must perform the file operation using system calls rather than high-level C file functions such as `fopen()`, `fread()`, `fwrite()`, and `fclose()`.

---

## 1. `open()` System Call

### Syntax

```c
open("filename.txt", modes, permissions);
```

### Example

```c
open("First_Prgm.txt", O_CREAT | O_WRONLY, 0644);
```

### Table 1 — Modes of `open()` System Call

| Flag | Purpose |
|---|---|
| `O_RDONLY` | Open for read only |
| `O_WRONLY` | Open for write only |
| `O_RDWR` | Open for both read and write |
| `O_CREAT` | Create file if it does not exist |
| `O_TRUNC` | Truncate (empty) an existing file |
| `O_APPEND` | Append data to the end of the file |
| `O_EXCL` | Fail if file already exists (used with `O_CREAT`) |

For this task, `File1.txt` is opened using `O_RDONLY`, while `File2.txt` is opened using `O_WRONLY | O_CREAT | O_TRUNC`.

The permission value `0644` gives the owner read/write permission and gives group and others read permission when a new file is created.

---

## 2. `read()` System Call

### Syntax

```c
read(int fd, void *buf, size_t count);
```

### Example

```c
read(fd, buffer, 100);
```

### Given Example

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
    char buffer[100];
    int n;

    printf("Enter some text: ");
    n = read(0, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("You entered: %s", buffer);

    return 0;
}
```

In the file-copy program, `read()` obtains a block of bytes from the source file into a buffer. The returned number of bytes determines how many bytes must be written to the destination file.

---

## 3. `write()` System Call

### Syntax

```c
write(int fd, const void *buf, size_t count);
```

### Example

```c
write(fd, message, 11);
```

### Given Example

```c
#include <unistd.h>

int main()
{
    write(1, "Hello World\n", 12);
    return 0;
}
```

In the file-copy program, `write()` writes the bytes read from `File1.txt` into `File2.txt`.

---

## 4. `close()` System Call

### Syntax

```c
close(fd);
```

`close()` releases the file descriptor after the file operation is complete.

Both the source and destination file descriptors must be closed before the program terminates.

---

# Complete File Copy Program

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd1, fd2;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // Open source file for reading
    fd1 = open("File1.txt", O_RDONLY);
    if (fd1 < 0)
    {
        perror("Error opening File1.txt");
        return 1;
    }

    // Open/create destination file for writing
    fd2 = open("File2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 < 0)
    {
        perror("Error opening File2.txt");
        close(fd1);
        return 1;
    }

    // Read from File1 and write to File2
    while ((bytesRead = read(fd1, buffer, BUFFER_SIZE)) > 0)
    {
        ssize_t totalWritten = 0;

        while (totalWritten < bytesRead)
        {
            ssize_t bytesWritten = write(
                fd2,
                buffer + totalWritten,
                bytesRead - totalWritten
            );

            if (bytesWritten < 0)
            {
                perror("Error writing to File2.txt");
                close(fd1);
                close(fd2);
                return 1;
            }

            totalWritten += bytesWritten;
        }
    }

    if (bytesRead < 0)
    {
        perror("Error reading File1.txt");
    }

    // Close both files
    close(fd1);
    close(fd2);

    if (bytesRead < 0)
        return 1;

    printf("File copied successfully from File1.txt to File2.txt.\n");
    return 0;
}
```

---

# How to Run Task 2

## Step 1 — Create the files

```bash
mkdir file_copy
cd file_copy
nano File1.txt
```

Enter sample content such as:

```text
This is File1.txt.
This content will be copied using Linux system calls.
Operating System System Calls practical.
```

Save the file.

## Step 2 — Create the C program

```bash
nano filecopy.c
```

Paste the complete program above and save it.

## Step 3 — Compile

```bash
gcc -o filecopy filecopy.c
```

## Step 4 — Execute

```bash
./filecopy
```

Expected output:

```text
File copied successfully from File1.txt to File2.txt.
```

## Step 5 — Verify the copied content

```bash
cat File1.txt
cat File2.txt
```

Both files should contain the same text.

You can also verify the contents using:

```bash
cmp File1.txt File2.txt
```

If there is no output from `cmp`, the files are identical.

---

# Task 2 System Call Flow

```mermaid
flowchart TD
    A([Start]) --> B[Open File1.txt with O_RDONLY]
    B --> C{Open successful?}
    C -- No --> D[Display error]
    D --> Z([End])
    C -- Yes --> E[Open/Create File2.txt with O_WRONLY | O_CREAT | O_TRUNC]
    E --> F{Open successful?}
    F -- No --> G[Display error]
    G --> H[Close File1]
    H --> Z
    F -- Yes --> I[Read bytes from File1 into buffer]
    I --> J{Bytes read > 0?}
    J -- Yes --> K[Write buffer to File2]
    K --> L{All bytes written?}
    L -- No --> K
    L -- Yes --> I
    J -- No --> M{Read error?}
    M -- Yes --> N[Display read error]
    N --> O[Close File1]
    M -- No --> O[Close File1]
    O --> P[Close File2]
    P --> Q[Display success message]
    Q --> Z([End])
```

---

# Task 2 Screenshot Evidence

**Screenshot 3 — File1.txt and source code**

> Keep the screenshot showing `File1.txt` content and/or `filecopy.c` in the terminal/editor.

**Screenshot 4 — Compilation and successful execution**

> Keep the terminal screenshot showing `gcc -o filecopy filecopy.c`, `./filecopy`, and the successful-copy message.

**Screenshot 5 — Verification**

> Keep the screenshot showing `cat File1.txt`, `cat File2.txt`, or `cmp File1.txt File2.txt` proving that the content was copied correctly.

---

# System Call Summary

| System Call | Role in this Task |
|---|---|
| `open()` | Opens `File1.txt` and creates/opens `File2.txt` |
| `read()` | Reads bytes from `File1.txt` into a buffer |
| `write()` | Writes the bytes from the buffer into `File2.txt` |
| `close()` | Closes both file descriptors after the operation |

---

# Final Test Checklist

## Task 1

- [ ] Shell source code screenshot kept.
- [ ] Program compiled successfully.
- [ ] `echo Hello` tested.
- [ ] `ls -l` tested.
- [ ] Empty input tested.
- [ ] `exit` tested.
- [ ] Child PID displayed.
- [ ] Command completion displayed.
- [ ] Control-flow diagram included.

## Task 2

- [ ] `File1.txt` created with sample content.
- [ ] `filecopy.c` created.
- [ ] Program compiled successfully.
- [ ] `open()` used for both files.
- [ ] `read()` used for source file.
- [ ] `write()` used for destination file.
- [ ] `close()` used for both files.
- [ ] `File2.txt` created/truncated correctly.
- [ ] Copied content verified.
- [ ] Screenshots kept as evidence.

---

# Conclusion

Task 1 demonstrates the control flow of a simple interactive shell: prompt display, input handling, exit conditions, tokenization, process creation, command execution, and parent-child synchronization.

Task 2 demonstrates low-level file copying using the Linux `open()`, `read()`, `write()`, and `close()` system calls. The source file is opened for reading, the destination is created or truncated for writing, data is transferred through a buffer, and both file descriptors are closed after the operation.

This document contains the complete written procedure, source code, commands, control-flow diagrams, expected outputs, verification steps, and screenshot placeholders. The screenshots can therefore be kept only as execution evidence.
