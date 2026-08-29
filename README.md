# Linux Dynamic Memory Allocation and Memory Monitoring System

> **Koneru Lakshmaiah Education Foundation (Deemed to be University estd. u/s. 3 of the UGC Act, 1956)**  
> Bachupally-Gandimaisamma Road, Bowrampet, Hyderabad, Telangana - 500 043  
> Phone: 7815926816 · [www.klh.edu.in](https://www.klh.edu.in/)

## Course & Project Information

| Field | Details |
|---|---|
| Course | **OPERATING SYSTEMS AND SYSTEMS PROGRAMMING (25CS2104E)** |
| Academic Term | **2026–27, Term-I** |
| Document | Project Problem Statement Submission Form |
| Section No. | 10 |
| Team No. | To be recorded |
| Project Title | **Linux Dynamic Memory Allocation and Memory Monitoring System** |
| Supervisor / Faculty | To be recorded |
| Repository | `OSSP_2520090104` |

## Team Members

| Roll Number | Student Name | GitHub Account |
|---:|---|---|
| 2520030456 | T. Arun | To be recorded |
| 2520090104 | Tejaswin Amara | [@tejaswin-amara](https://github.com/tejaswin-amara) |
| 2520090140 | U. Vinay Sampath | To be recorded |

> Each team member must contribute from their own GitHub account. Individual contribution is verified through the repository's commit history.

## Abstract

Dynamic memory management directly affects application performance, reliability, and system stability. This project proposes a **Linux Dynamic Memory Allocation and Memory Monitoring System** consisting of a custom heap allocator and a real-time memory monitoring utility.

The allocator implements the core allocation primitives `malloc`, `calloc`, `realloc`, and `free` from scratch using low-level Linux system calls such as `sbrk()` and `mmap()`. The monitoring component reads process and system-wide memory statistics from the `/proc` filesystem, particularly `/proc/[pid]/status` and `/proc/meminfo`, to report live memory consumption, fragmentation levels, and allocation patterns.

The system addresses memory leaks, fragmentation, and inefficient allocation strategies through free-list management and first-fit/best-fit allocation policies. Multi-threaded safety is provided using POSIX mutex locks, while signal handling such as `SIGSEGV` is used to detect abnormal memory-access conditions.

## Problem Statement

Modern applications typically rely on default memory allocators without providing sufficient visibility into allocation, fragmentation, or memory reclamation. This makes memory leaks, inefficient allocation strategies, and fragmentation difficult to diagnose.

The project addresses this problem by developing a transparent custom memory allocation mechanism together with a real-time monitoring system that exposes allocation, deallocation, memory consumption, and fragmentation statistics for C/C++ applications running on Linux.

## Objectives

1. Design and implement a custom dynamic memory allocator in C using Linux system calls such as `sbrk()` and `mmap()`, replicating `malloc`, `calloc`, `realloc`, and `free`.
2. Develop a memory monitoring module that reads real-time statistics from the `/proc` filesystem.
3. Implement fragmentation-reduction strategies including free-list management and first-fit/best-fit allocation policies.
4. Visualize memory allocation trends and detect memory leaks through logging and a reporting dashboard.

## Proposed Methodology

The project is developed as two integrated modules on a Linux/Ubuntu platform using C/C++.

### 1. Memory Allocator Module

The allocator manages process memory directly through `sbrk()` and `mmap()`. It maintains an internal free list using linked-list metadata and supports first-fit and best-fit allocation strategies. Free blocks are coalesced where possible to reduce fragmentation.

Core operations:

- `malloc()` — allocate a block of dynamic memory.
- `calloc()` — allocate and zero-initialize memory.
- `realloc()` — resize an existing allocation.
- `free()` — release allocated memory back to the allocator.
- `sbrk()` / `brk()` — manage the process heap.
- `mmap()` / `munmap()` — handle memory-mapped allocations, particularly larger blocks.

### 2. Memory Monitoring Module

A companion monitoring utility periodically reads:

- `/proc/[pid]/status` for process-level memory statistics.
- `/proc/meminfo` for system-wide memory statistics.

Collected information is logged for analysis and visualization, including memory consumption, fragmentation indicators, and allocation/deallocation patterns.

### 3. Safety and Concurrency

The system uses POSIX threads and mutex locks to provide thread-safe allocator operations. Signal handling, including `SIGSEGV`, is incorporated for abnormal memory-access detection and reporting.

## Operating Systems Concepts / Linux APIs Used

| OS Concept / Linux API / System Call | Purpose |
|---|---|
| Dynamic Memory Allocation (`malloc`, `calloc`, `realloc`, `free`) | Custom implementation of standard heap allocation functions |
| `sbrk()` / `brk()` | Extend or shrink the process heap segment directly |
| `mmap()` / `munmap()` | Allocate and release memory-mapped regions, especially for large blocks |
| `/proc` filesystem (`/proc/[pid]/status`, `/proc/meminfo`) | Retrieve real-time process and system memory statistics |
| POSIX Threads (`pthread`) and mutex locks | Ensure thread-safe allocation in multi-threaded programs |
| Signal handling (`SIGSEGV`) | Detect and report abnormal/invalid memory access conditions |

## Tools / Platforms / Software Used

| Tool / Platform / Software | Purpose |
|---|---|
| Linux / Ubuntu | Development and testing environment |
| C / C++ | Core implementation languages for system-level programming |
| Valgrind / GDB | Debugging memory leaks and analyzing runtime behavior |
| gnuplot / Python (`matplotlib`) | Visualizing memory-usage trends collected by the monitor |
| Bash scripting | Automating build, testing, and monitoring workflows |

## Expected Outcome

The completed system is expected to provide:

- A functional custom dynamic memory allocator that replicates the major standard C allocation operations.
- A real-time memory monitoring utility based on the Linux `/proc` filesystem.
- Sample test programs for allocator and monitoring validation.
- Logging of allocation, deallocation, and memory statistics.
- Visualization of memory usage and allocation trends.
- Mechanisms for identifying memory leaks and fragmentation.
- Thread-safe allocation using POSIX synchronization primitives.

## Repository Structure

```text
OSSP_2520090104/
├── Project/
│   ├── src/          # Source code and implementations
│   ├── docs/         # Technical and project documentation
│   ├── data/         # Permitted data or documented external data sources
│   ├── results/      # Experimental outputs, logs and observations
│   └── reports/      # Phase and final academic reports
├── .gitignore
└── README.md
```

### Directory Responsibilities

- **`Project/src/`** — allocator, monitoring utility, tests, and supporting source code.
- **`Project/docs/`** — architecture, methodology, API notes, setup, experiments, and project documentation.
- **`Project/data/`** — permitted datasets or references to external data sources. Restricted/licensed data must not be committed.
- **`Project/results/`** — generated logs, measurements, benchmarks, observations, and visualizations.
- **`Project/reports/`** — review submissions and final report materials.

## Setup

### Prerequisites

- Linux/Ubuntu environment.
- GCC/G++ or an equivalent C/C++ compiler.
- POSIX threads support.
- Git.
- Optional: Valgrind, GDB, Python with `matplotlib`, and gnuplot for testing and visualization.

### Clone

```bash
git clone https://github.com/tejaswin-amara/OSSP_2520090104.git
cd OSSP_2520090104
```

### Build & Run

Implementation-specific build and execution commands are maintained in `Project/docs/` and alongside the relevant source components. Generated logs and experiment outputs should be placed in `Project/results/`.

## Individual Contribution

| Roll Number | Student Name | Individual Responsibility |
|---:|---|---|
| 2520030456 | T. Arun | To be recorded |
| 2520090104 | Tejaswin Amara | To be recorded |
| 2520090140 | U. Vinay Sampath | To be recorded |

This table should be updated as responsibilities are formally assigned and completed. Contributions must remain attributable to the corresponding GitHub account.

## GitHub & Project Governance

- Repository URL: `https://github.com/tejaswin-amara/OSSP_2520090104`
- Repository created: **YES**
- Every team member must commit using their own GitHub account.
- Contributions must be progressive through the project phases.
- Maintain at least one meaningful team commit per week during active project work.
- Tag completed phase deliverables, for example `review-1`, `review-2`, and `final`.
- Grant repository access to the supervisor and Course Coordinator.
- Keep the repository accessible until final project evaluation is completed.
- Do not commit passwords, credentials, API keys, private keys, licensed datasets without redistribution permission, or confidential institutional data.
- The repository URL recorded in Section D must not be renamed or transferred without written consent from the Course Coordinator.

## Phase Status

**Current Phase: Project Problem Statement / Repository Baseline**

| Deliverable | Status |
|---|---|
| Project title and scope | ✅ Defined |
| Team member details | ✅ Recorded from submission document |
| Abstract | ✅ Documented |
| Problem statement | ✅ Documented |
| Objectives | ✅ Documented |
| Proposed methodology | ✅ Documented |
| OS concepts and Linux APIs | ✅ Documented |
| Tools and platforms | ✅ Documented |
| Expected outcomes | ✅ Documented |
| Required project folders | ✅ Established under `Project/` |
| Individual responsibilities | ⏳ To be recorded |
| Supervisor/faculty details | ⏳ To be recorded |
| Supervisor/Course Coordinator access | ⏳ To be granted |
| Weekly contribution history | ⏳ Ongoing |
| Review tags | ⏳ To be created for completed reviews |
| Final evaluation | ⏳ Pending |

## Faculty & Approval

| Field | Status |
|---|---|
| Faculty Name | To be recorded |
| Faculty Signature | To be obtained |
| Remarks | To be recorded |
| Project Approved | To be recorded |
| Approval Date | To be recorded |
| Faculty Signature | To be obtained |

## Data & Security Policy

Never commit:

- Passwords, authentication tokens, API keys, private keys, or `.env` files.
- Licensed/restricted datasets without explicit redistribution permission.
- Confidential institutional, student, staff, or assessment information.
- Local IDE configuration, build caches, or unnecessary generated files.

For externally hosted or restricted datasets, document the authoritative source, license/usage terms, version or retrieval date, schema, and reproduction/access procedure in `Project/data/README.md`.

## Academic Integrity

Git history forms part of the project's contribution evidence. Team members must make genuine, meaningful contributions from their own GitHub accounts. Do not manufacture commits, rewrite history to conceal authorship, or use a single account for bulk uploads.

---

**Project:** Linux Dynamic Memory Allocation and Memory Monitoring System  
**Course:** Operating Systems and Systems Programming (25CS2104E)  
**Term:** 2026–27, Term-I  
**Section:** 10  
**Team:** To be recorded
