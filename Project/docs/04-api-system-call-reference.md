# Linux API and System Call Reference

| API | Role | Key consideration |
|---|---|---|
| `sbrk()` / `brk()` | Process heap boundary | Global program-break interaction; document limitations. |
| `mmap()` | Map memory regions | Check flags/protection and page alignment requirements. |
| `munmap()` | Release mapped regions | Release exactly the mapped region. |
| `malloc()` | Standard allocation reference | Useful for behavioral comparison; custom implementation must avoid accidental recursion. |
| `calloc()` | Zero-initialized allocation reference | Check multiplication overflow before `nmemb * size`. |
| `realloc()` | Resize allocation | Preserve old data on successful resize; define failure behavior. |
| `free()` | Release allocation | Detect allocator metadata misuse during testing. |
| `pthread_mutex_lock()` | Protect allocator state | Always pair lock/unlock on every path. |
| `pthread_create()` / `pthread_join()` | Concurrency testing | Verify all worker threads complete. |
| `getrusage()` | Process resource statistics | Interpret returned fields according to platform semantics. |
| `/proc/<pid>/status` | Process memory summary | Parse labels and units explicitly. |
| `/proc/<pid>/maps` | Virtual-memory mappings | Useful for observing heap/mmap/stack regions. |
| `/proc/meminfo` | System-wide memory statistics | Values are commonly expressed in kB. |
| `clock_gettime()` | Timestamp events | Prefer a monotonic clock for elapsed-time measurements. |
| `sigaction()` | Signal handling | Use async-signal-safe handler behavior. |
| `write()` | Low-level logging | Useful when allocator logging must avoid stdio/allocator recursion. |

## Error Handling

Check every system-call return value. On failure, capture relevant `errno` immediately when applicable. Never treat an unavailable `/proc` metric as a valid zero.

## References

Use Linux manual pages during implementation:
- `man 2 mmap`
- `man 2 munmap`
- `man 2 sbrk`
- `man 2 getrusage`
- `man 2 sigaction`
- `man 2 write`
- `man 3 malloc`
- `man 3 calloc`
- `man 3 realloc`
- `man 3 free`
- `man 7 proc`