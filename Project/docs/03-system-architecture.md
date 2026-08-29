# System Architecture

## High-Level Design

```text
                 +---------------------------+
                 |       Test Programs       |
                 +-------------+-------------+
                               |
                               v
                 +---------------------------+
                 |     Custom Allocator       |
                 | malloc/calloc/realloc/free |
                 +-------------+-------------+
                               |
              +----------------+----------------+
              |                                 |
              v                                 v
      +---------------+                 +---------------+
      | Free-list /   |                 | Memory Source |
      | metadata      |                 | sbrk / mmap   |
      +---------------+                 +---------------+
              |
              v
      +---------------+
      | Event Logger   |
      +-------+-------+
              |
              v
      +---------------+       +----------------------+
      | results/logs  |<------| Memory Monitor       |
      +---------------+       | /proc + getrusage    |
                              +----------------------+
``` 

## Allocator Layer

The allocator maintains metadata for each managed block. A typical block records its size, free/allocated state and linkage to other blocks. Allocation searches the free list according to the selected policy. An adequately large block may be split; release marks a block free and coalesces compatible neighboring blocks.

## Memory Acquisition

Small/general heap allocations may be obtained by extending the process heap with `sbrk()`. Large or separately managed regions may use `mmap()`. The implementation must keep ownership and release rules explicit because heap memory and mapped regions have different lifecycles.

## Monitoring Layer

The monitor identifies a target process and periodically reads `/proc/<pid>/status`, `/proc/<pid>/maps`, and optionally `/proc/meminfo`. `getrusage()` provides process resource statistics. Samples are normalized into a stable log/report format.

## Logging Schema

Recommended fields:

```text
timestamp, pid, thread_id, operation, requested_size, address, source, policy
```

## Important Invariants

- Block metadata must remain within valid managed regions.
- A block must not simultaneously appear as allocated and free.
- A released block must not be returned twice without a new allocation.
- Coalescing must update neighboring links consistently.
- `realloc()` must preserve the required prefix of existing data.
- Monitor output must distinguish unavailable metrics from zero values.

## Concurrency

Allocator shared state is protected with a POSIX mutex when multithreaded operation is enabled. Lock scope should cover metadata mutation, not unrelated slow I/O. Logging should avoid recursively invoking the allocator.

## Failure Handling

Allocation failure returns the documented failure value. System-call failures preserve `errno` where appropriate and are logged. Signal handling must use async-signal-safe operations; a `SIGSEGV` handler must not attempt unsafe heap operations.