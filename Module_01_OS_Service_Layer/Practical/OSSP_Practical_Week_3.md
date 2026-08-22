# OSSP Practical — Week 3

## Task 1 — Parent and Child Process Using `fork()`

Develop a C program using `fork()` that creates a parent and child process and displays the Process ID (PID), Parent Process ID (PPID), and process execution information.

## Task 2 — Process State Transition Experiment

Design an experiment to observe process state transitions using Linux monitoring tools such as `ps`, `top`, and `/proc`. The documented stages are:

1. RUNNING — the child is executing CPU instructions.
2. WAITING — the child sleeps for 15 seconds.
3. TERMINATING — the child exits.
4. CHILD TERMINATED — the parent detects child termination.

### Observation Table

| Stage | Expected/Observed State | Tool / Evidence | Observation |
|---|---|---|---|
| STATE 1 | RUNNING | `ps` / `top` | Child is executing CPU instructions. |
| STATE 2 | WAITING | `ps` / `/proc` | Child is sleeping for 15 seconds. |
| STATE 3 | TERMINATING | Program output | Child is exiting. |
| STATE 4 | TERMINATED | Parent output | Parent detects child termination. |

### Conclusion

The experiment demonstrates creation of parent and child processes using `fork()` and records the child process at different execution stages.

Source basis: uploaded `OSSP Practical Week 3.pdf`.
