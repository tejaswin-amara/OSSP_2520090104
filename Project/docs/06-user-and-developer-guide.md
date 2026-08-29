# User and Developer Guide

## Intended User
The project is an educational Linux systems-programming demonstrator for studying allocation behavior and process memory.

## Typical Workflow

1. Build the project on Linux/Ubuntu.
2. Run allocator unit/integration tests.
3. Start a monitored test process.
4. Run representative allocation workloads.
5. Collect allocator events and process-memory samples.
6. Analyze reuse, heap growth, fragmentation and leak behavior.
7. Store reproducible evidence under `results/` and summarize findings under `reports/`.

## Developer Rules

- Keep allocator metadata definitions centralized.
- Separate allocation policy from platform memory acquisition.
- Keep logging independent from allocation internals where possible.
- Check all system-call and allocation return values.
- Document ownership for every allocated resource.
- Add a regression test for every discovered allocator bug.
- Avoid undefined behavior in diagnostics.

## Debugging

Recommended tools:

```bash
gdb ./build/test_allocator
valgrind --leak-check=full ./build/test_allocator
strace -f -e trace=brk,mmap,munmap ./build/test_allocator
```

For compiler-assisted checking, use AddressSanitizer where the allocator design and build configuration permit it.

## Reproducibility

Record Linux distribution/version, compiler version, build flags, allocator policy, workload parameters and monitor sampling interval in each benchmark/report. Do not rely on undocumented machine-specific observations.