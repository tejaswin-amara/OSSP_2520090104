# Task 2 – Copy File1.txt to File2.txt Using System Calls

**Repository:** `tejaswin-amara/OSSP_2520090104`  
**Module:** Module 02 – Process Control / File-system system-call practice  
**Language:** C  
**Platform:** Linux / Ubuntu / WSL

---

## Aim

To copy the content from `File1.txt` to `File2.txt` using the following UNIX/Linux system calls:

1. `open()`
2. `read()`
3. `write()`
4. `close()`

The actual copying operation uses system calls rather than high-level file functions such as `fopen()`, `fread()`, `fwrite()`, and `fclose()`.

## 1. `open()`

### Syntax

```c
open("filename.txt", modes, permissions);
```

### Example

```c
open("First_Prgm.txt", O_CREAT | O_WRONLY, 0644);
```

### Table 1: Modes of `open()` System Call

| Flag | Purpose |
|---|---|
| `O_RDONLY` | Open for read only. |
| `O_WRONLY` | Open for write only. |
| `O_RDWR` | Open for both read and write. |
| `O_CREAT` | Create file if it does not exist. |
| `O_TRUNC` | Truncate (empty) an existing file. |
| `O_APPEND` | Append data to the end of the file. |
| `O_EXCL` | Fail if file already exists (used with `O_CREAT`). |

## 2. `read()`

### Syntax

```c
read(int fd, void *buf, size_t count);
```

### Example

```c
read(fd, buffer, 100);
```

### Supplied Example

```c
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
```

`read()` returns the number of bytes actually read. The returned value should be checked before using the data.

## 3. `write()`

### Syntax

```c
write(int fd, const void *buf, size_t count);
```

### Example

```c
write(fd, message, 11);
```

### Supplied Example

```c
#include <unistd.h>

int main()
{
    write(1, "Hello World\n", 12);
    return 0;
}
```

`write()` sends bytes to the file descriptor. The number of bytes written should be checked so that partial writes can be handled correctly.

## 4. `close()`

### Syntax

```c
close(fd);
```

`close()` closes an open file descriptor. Both the source and destination descriptors should be closed after the copy is complete.

---

# Complete Program

The source code is kept separately in [`file_copy.c`](./file_copy.c).

```c
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
```

## How the Program Works

1. `open("File1.txt", O_RDONLY)` opens the source file for reading.
2. `open("File2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644)` opens or creates the destination file for writing and clears an old copy first.
3. `read()` reads a block of bytes from the source into `buffer`.
4. `write()` writes the bytes to the destination.
5. The loop continues until `read()` returns `0`, meaning end-of-file.
6. `close()` closes both file descriptors.
7. A success message is displayed.

## File Descriptor Flow

```text
File1.txt
   |
   | open(O_RDONLY)
   v
 Source FD
   |
   | read()
   v
 buffer[4096]
   |
   | write()
   v
 Destination FD
   |
   | open(O_WRONLY | O_CREAT | O_TRUNC)
   v
File2.txt

Finally:
Source FD ------> close()
Destination FD -> close()
```

## Control Flow

```text
START
  |
  v
Open File1.txt for reading
  |
  +---- Error ---> Display error ---> END
  |
  v
Open/Create File2.txt for writing
  |
  +---- Error ---> Close source ---> Display error ---> END
  |
  v
Read block from File1.txt
  |
  v
Any bytes read?
 /           \
No            Yes
 |              |
 v              v
END OF FILE   Write block to File2.txt
 |              |
 v              v
Close files   More data?
 |              |
 v              +---- Yes ---> Read next block
Success         |
                No
                 |
                 v
              Close files
                 |
                 v
              Success
                 |
                 v
                END
```

## Compilation

```bash
gcc -o file_copy file_copy.c
```

## Prepare the Source File

Create `File1.txt` with some test content, for example:

```bash
echo "This is the content of File1.txt." > File1.txt
```

Or create/edit it with:

```bash
nano File1.txt
```

## Run the Program

```bash
./file_copy
```

Expected output:

```text
File copied successfully from File1.txt to File2.txt.
```

## Verify the Copy

Display both files:

```bash
cat File1.txt
cat File2.txt
```

A direct comparison can also be made with:

```bash
cmp File1.txt File2.txt
```

If `cmp` produces no output, the files are identical.

## Error Cases to Test

### Missing source file

If `File1.txt` does not exist, the program should display an error from `open()`.

### Existing destination file

`O_TRUNC` clears the old `File2.txt` contents before the new copy is written.

### Empty source file

An empty `File1.txt` should produce an empty `File2.txt` and still complete successfully.

## Screenshot Evidence

Keep Task 2 screenshots in the [`screenshots`](./screenshots/) folder, not in this document folder's root.

Recommended evidence:

1. `01_file1_and_source.png` – `File1.txt` and the source program.
2. `02_file_copy_execution.png` – compilation and successful execution.
3. `03_file2_verification.png` – `cat`/`cmp` verification showing the copied content.
