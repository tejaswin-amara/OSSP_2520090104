# Troubleshooting Guide

## Build Errors

- Confirm GCC and required POSIX development tools are installed.
- Run `make clean` before rebuilding after structural changes.
- Treat warnings as defects when the project build uses `-Werror`.

## Allocation Crashes

Check pointer arithmetic, block-size calculations, metadata boundaries, alignment and free-list links. Reproduce with the smallest failing workload under GDB.

## Valgrind Reports

Classify findings into definitely lost, indirectly lost, invalid read/write, use-after-free, double-free and uninitialized-value errors. Fix allocator defects before interpreting application-level leaks.

## Monitor Shows Zero/Unavailable Values

Check that the target PID is alive, `/proc/<pid>/status` is readable, labels are parsed exactly, units are handled correctly, and `getrusage()` is queried for the intended process/thread scope.

## `sbrk()` Problems

`sbrk()` interacts with the process program break and can conflict with other heap managers. Keep the academic allocator isolated from unrelated allocation activity and document the Linux/glibc assumptions of the test environment.

## Threading Problems

Check every shared metadata access for synchronization. Never hold allocator locks while performing slow or potentially reentrant logging. Use race-detection tooling where compatible.