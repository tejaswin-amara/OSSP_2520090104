# Module 02 – Process Control: Task 1 and Task 2

This file is the combined entry point for the two practical tasks. The implementation, detailed documentation, and screenshot evidence are intentionally kept in their respective task folders rather than being mixed together.

## Task 1 – Interactive Shell

- [Complete Task 1 Documentation](./Task_01_Interactive_Shell/README.md)
- [Source Code – `myshell.c`](./Task_01_Interactive_Shell/myshell.c)
- [Screenshot Evidence Folder](./Task_01_Interactive_Shell/screenshots/README.md)

Task 1 covers:

1. Main loop
2. Prompt display
3. Reading user input
4. Exit conditions
5. Empty-command handling
6. Tokenization and argument parsing
7. `fork()`
8. `execvp()`
9. `waitpid()`
10. Control-flow diagram
11. Compilation and execution
12. Interactive testing

## Task 2 – Copy File1.txt to File2.txt Using System Calls

- [Complete Task 2 Documentation](./Task_02_File_Copy_System_Calls/README.md)
- [Source Code – `file_copy.c`](./Task_02_File_Copy_System_Calls/file_copy.c)
- [Screenshot Evidence Folder](./Task_02_File_Copy_System_Calls/screenshots/README.md)

Task 2 covers:

1. `open()`
2. `read()`
3. `write()`
4. `close()`
5. `open()` mode flags
6. Complete file-copy program
7. Error handling
8. File descriptor flow
9. Control-flow diagram
10. Compilation and execution
11. File-content verification

## Evidence Organization

Screenshots belong inside the `screenshots` folder of the task they demonstrate. Source code stays beside the task documentation, and supporting reports remain directly under `Module_02_Process_Control`.

### Task 1 screenshots

- `Task_01_Interactive_Shell/screenshots/01_myshell_source.png` – GNU nano source-code evidence.
- `Task_01_Interactive_Shell/screenshots/02_myshell_execution.png` – terminal execution evidence.

### Task 2 screenshots

- `Task_02_File_Copy_System_Calls/screenshots/01_file1_and_source.png` – source file and source program.
- `Task_02_File_Copy_System_Calls/screenshots/02_file_copy_execution.png` – compilation and successful execution.
- `Task_02_File_Copy_System_Calls/screenshots/03_file2_verification.png` – copied-file verification.

This combined file exists to prevent broken links while preserving the task-by-task repository structure.
