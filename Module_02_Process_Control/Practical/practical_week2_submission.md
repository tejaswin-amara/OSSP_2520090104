OSSP WEEK 2 PRACTICAL REPORT

Name: Tejaswin Amara
Roll No: 2520090104
Department: CS&IT
Course: OSSP
Week: 2

Task 1: Process Creation using fork(), exec(), and wait()

Objective: Develop a C program that accepts a Linux command, creates a child process using fork(), executes the command using exec(), waits for the child process using wait(), and displays the Parent and Child Process IDs.

Figure 1: Writing the C program in Nano Editor



Figure 2: Compiling the program and executing the 'ls' command



Figure 3: Executing the 'pwd' command



Task 2: Hardware Resources and Operating System Services

The following Linux commands were executed to study operating system services and hardware abstraction:
• uname -a
• lscpu
• ps
• top

Figure 4: Output of lscpu, ps and top



Observation

CPU: The operating system schedules processor time among processes.
Memory: The OS allocates and manages memory for each process.
Storage: The OS manages files and directories through the file system.
I/O Devices: Device drivers allow applications to communicate with hardware.

Conclusion

The practical successfully demonstrated Linux process creation using fork(), command execution using exec(), synchronization using wait(), and the abstraction of hardware resources through operating system services.