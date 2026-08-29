# Project Charter

## Project
**Linux Dynamic Memory Allocation and Memory Monitoring System**

## Academic Context
- Course: Operating Systems and Systems Programming (25CS2104E)
- Academic Year: 2026–27, Term-I
- Section: 10
- Team: 12
- Faculty / Supervisor: Manthena Raghupathi

## Team
| Roll Number | Student | Responsibility |
|---|---|---|
| 2520030456 | T. Arun | Core allocator and allocation/deallocation event logging |
| 2520090104 | Tejaswin Amara | `/proc` and `getrusage()` monitoring, sampling and reporting |
| 2520090140 | U. Vinay Sampath | Integration, testing, Valgrind validation, documentation and report |

## Purpose
Provide a transparent experimental memory-management system for Linux that demonstrates dynamic allocation, heap growth, fragmentation, monitoring and memory-leak analysis.

## Scope
The project covers a custom allocator implementing `malloc`, `calloc`, `realloc` and `free` semantics; free-list management; first-fit/best-fit allocation; block splitting and coalescing; `sbrk`/`mmap` based acquisition; allocation logging; and a companion monitor using `/proc/[pid]/status`, `/proc/[pid]/maps`, `/proc/meminfo` and `getrusage()`.

## Out of Scope
Replacing the system allocator globally, kernel-level allocator development, production-grade security guarantees, arbitrary hardware portability, and redistribution of restricted datasets.

## Success Criteria
1. Allocator builds cleanly with warnings enabled.
2. Allocation primitives pass functional tests.
3. Freed blocks can be reused and adjacent free blocks can be coalesced.
4. Large allocations can use `mmap()` where designed.
5. Monitor reports repeatable process-memory metrics.
6. Allocation events are timestamped and attributable to an operation.
7. Integration tests and Valgrind/ASan checks are documented.
8. Results are reproducible from repository instructions.

## Risks
Incorrect pointer arithmetic, metadata corruption, double-free, use-after-free, allocator recursion, thread races, signal-handler safety issues, platform-specific `sbrk()` behavior, and misleading memory measurements.

## Governance
All members contribute through their own GitHub accounts. Meaningful work is committed progressively; phase deliverables are tagged. No credentials, API keys, confidential institutional data or unauthorized licensed datasets are committed.