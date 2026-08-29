# Testing and Validation Plan

## Test Categories

### Allocation Correctness
- Allocate small, medium and large blocks.
- Verify returned pointers are suitably aligned.
- Write/read within requested bounds.
- Verify `calloc` memory is zero-initialized.
- Verify `realloc` preserves existing data.
- Verify `free` makes eligible blocks reusable.

### Free-list Behavior
- Reuse an exact-size free block.
- Exercise first-fit selection.
- Exercise best-fit selection.
- Create adjacent free blocks and verify coalescing.
- Exercise fragmentation-heavy workloads.

### Failure Cases
- Zero-size allocation behavior is documented and tested.
- Integer overflow in `calloc` size calculation is rejected.
- Allocation failure is handled without corrupting allocator state.
- Invalid internal metadata is detected during debug/testing builds.

### Monitoring
- Confirm `/proc/<pid>/status` metrics are parsed correctly.
- Confirm `/proc/<pid>/maps` reflects heap and mapped regions.
- Confirm `getrusage()` values are collected.
- Confirm periodic samples have monotonic timestamps.
- Confirm target-process termination is handled cleanly.

### Concurrency
- Run multiple allocation/free workers concurrently.
- Use ThreadSanitizer where compatible with the implementation.
- Verify no metadata races or deadlocks.

## Tool-Assisted Validation

```bash
make clean && make
make test
valgrind --leak-check=full --track-origins=yes ./build/test_allocator
strace -f -e trace=brk,mmap,munmap ./build/test_allocator
``` 

If a command or binary differs from the final implementation, update this document rather than leaving stale commands.

## Acceptance Criteria

| Area | Pass condition |
|---|---|
| Build | No compiler errors; required warnings addressed |
| Allocation | All supported allocation tests pass |
| Reallocation | Data preservation and failure behavior pass |
| Free list | Reuse, splitting and coalescing tests pass where implemented |
| Monitoring | Required metrics are collected and validated |
| Concurrency | Stress tests complete without known races/deadlocks |
| Memory analysis | Findings from Valgrind/ASan are documented |
| Reproducibility | A clean Linux environment can follow the README and reproduce results |

## Test Evidence

Store test logs and summarized measurements in `Project/results/`. Store formal test reports in `Project/reports/`.