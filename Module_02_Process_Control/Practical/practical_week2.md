Task 1: Develop a C program that demonstrates how a Linux operating system executes a command entered by a user that 1. Accept a Linux command as input. 2. Create a child process using fork(). 3. Execute the command in the child process using an appropriate exec() system call. 4. Allow the parent process to wait for the child using wait (). 5. Display the Process ID (PID) of both parent and child processes.

Write a C code to create a process using fork() system call.

Read the user input as shell command.

Use a system call exec() to execute the shell command.

Use a wait() system call for waiting a parent process.

Display the PIDs of parent and child processes.







Example Output:

Enter a Linux command: ls

Parent Process

Child Process

Parent PID : 67

Child PID  : 68

Child PID  : 68

Parent PID : 67



Executing command: ls

CE1    FIRST.c    File2.c        Proces_States.c   command_executor    filecopy.c                                                                                            hello.c   process_example        session_4_a    session_4_b.c

CE1.c  File1.c    First.c        Process_States.c  command_executor.c  fork_example.c.save  my_shell  process_example.c     session_4_a.c

FIRST  File1.txt  Proces_States  R1                filecopy            hello                                                                                                 os-lab    process_example.cyes  session_4_b



Child process completed.



Task-2: Using Linux terminal commands (uname, lscpu, ps, top), investigate the relationship between hardware resources and operating system services. Prepare a report explaining how the OS abstracts CPU, memory, storage, and I/O devices.