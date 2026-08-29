# OSSP Practical — Week 2

## Task 1 — Process Creation using `fork()`, `exec()`, and `wait()`

Develop a C program that accepts a Linux command, creates a child process using `fork()`, executes the command using `exec()`, waits for the child using `wait()`, and displays the parent and child process IDs.

## Task 2 — Hardware Resources and Operating System Services

Linux commands used in the practical:

- `uname -a`
- `lscpu`
- `ps`
- `top`

### Observations

- CPU: the operating system schedules processor time among processes.
- Memory: the OS allocates and manages memory for each process.
- Storage: the OS manages files and directories through the file system.
- I/O devices: device drivers allow applications to communicate with hardware.

### Conclusion

The practical demonstrates Linux process creation using `fork()`, command execution using `exec()`, synchronization using `wait()`, and abstraction of hardware resources through operating-system services.

Source basis: uploaded `OSSP PRACTICAL Week 2.pdf`.
