# Final Demonstration Script

## Objective
Demonstrate the allocator, monitoring utility, logging, diagnostics and documented evidence in a reproducible Linux environment.

## Demonstration Sequence

1. Show repository structure and project documentation.
2. Show the build command and a clean successful build.
3. Run basic allocation tests.
4. Demonstrate `calloc` zero initialization.
5. Demonstrate `realloc` data preservation.
6. Demonstrate free-list reuse and coalescing where implemented.
7. Start the monitoring utility against a test process.
8. Execute an allocation workload and show periodic `/proc` and `getrusage()` measurements.
9. Show timestamped allocation/deallocation events.
10. Run Valgrind and explain the final findings.
11. Use `strace` to show relevant `brk`/`mmap`/`munmap` activity.
12. Show results and benchmark evidence.
13. Explain limitations and future work.

## Evidence Checklist

- [ ] Clean build
- [ ] Functional tests
- [ ] Monitoring output
- [ ] Allocation log
- [ ] Valgrind output
- [ ] strace output
- [ ] Benchmark results
- [ ] Final report

## Demo Safety

Do not deliberately trigger a real invalid memory access on an uncontrolled process. If demonstrating signal/error handling, use an isolated test program designed for that purpose and clearly label it as a controlled test.