# Requirements Specification

## Functional Requirements

| ID | Requirement | Priority |
|---|---|---|
| FR-01 | Allocate memory through a custom `malloc`-like interface. | Must |
| FR-02 | Release allocated memory through a custom `free`-like interface. | Must |
| FR-03 | Provide zero-initialized allocation through `calloc` semantics. | Must |
| FR-04 | Resize allocations through `realloc` semantics while preserving data as required. | Must |
| FR-05 | Acquire process memory using `sbrk()` and/or `mmap()` according to allocation policy. | Must |
| FR-06 | Maintain block metadata and a free list. | Must |
| FR-07 | Support first-fit and/or best-fit block selection. | Should |
| FR-08 | Split oversized free blocks where safe. | Should |
| FR-09 | Coalesce adjacent free blocks. | Should |
| FR-10 | Record allocation and deallocation events with operation, size, address and timestamp. | Must |
| FR-11 | Monitor `/proc/[pid]/status` and `/proc/[pid]/maps`. | Must |
| FR-12 | Read system memory information from `/proc/meminfo`. | Should |
| FR-13 | Capture resource information using `getrusage()`. | Must |
| FR-14 | Perform periodic monitoring samples. | Must |
| FR-15 | Export measurements for analysis and visualization. | Must |
| FR-16 | Provide thread-safe allocator operations using POSIX synchronization where enabled. | Should |

## Non-Functional Requirements
- Correctness: invalid internal states must be detected during development.
- Portability: target Linux/Ubuntu with documented compiler assumptions.
- Observability: allocation and monitoring behavior must be inspectable through logs.
- Reproducibility: tests and commands must be documented.
- Maintainability: allocator metadata and invariants must be documented.
- Safety: no secrets or confidential data may enter version control.

## Constraints
The implementation is an academic systems-programming project. `sbrk()` is treated as an educational low-level mechanism; the implementation must document platform limitations rather than claim production suitability.