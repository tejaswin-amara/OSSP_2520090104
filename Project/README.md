# Linux Dynamic Memory Allocation and Memory Monitoring System

> **Operating Systems and Systems Programming (25CS2104E)** · PBL · Section 10 · **Team 12**

**Institution:** Koneru Lakshmaiah Education Foundation (Deemed to be University)  
**Faculty / Supervisor:** Manthena Raghupathi  
**Academic Year:** 2026–27 · Term-I  

---

## 📌 Project Overview

The **Linux Dynamic Memory Allocation and Memory Monitoring System** is a systems-programming project developed in C/C++ for Linux/Ubuntu. It combines a custom dynamic memory allocator with a real-time monitoring utility to make memory allocation, deallocation, heap growth, memory consumption, and fragmentation more transparent.

The project explores how user-space memory management interacts with Linux memory primitives such as `brk()`, `sbrk()`, `mmap()`, the `/proc` filesystem, POSIX threads, mutexes, and signal handling.

## 👥 Team 12

| Roll Number | Student | Responsibility |
|---:|---|---|
| **2520030456** | **T. Arun** | Core memory allocator using `malloc()`/`free()` and `brk()`/`sbrk()`; allocation/deallocation event logging with size, address, and timestamp. |
| **2520090104** | **Tejaswin Amara** | Memory monitoring using `/proc/[pid]/status`, `/proc/[pid]/maps`, and `getrusage()`; periodic sampling and reporting. |
| **2520090140** | **U. Vinay Sampath** | Integration and testing; Valgrind-based leak validation; test cases, documentation, and project report. |

> Each member must make genuine commits from their own GitHub account so individual contribution remains verifiable.

---

## 🎯 Abstract

Dynamic memory management directly affects application performance, reliability, and system stability. Standard allocators generally hide allocation behavior, making fragmentation, memory growth, and leaks difficult to inspect.

This project develops a Linux-based **custom dynamic memory allocation and memory monitoring system**. The allocator provides `malloc`, `calloc`, `realloc`, and `free` functionality using low-level mechanisms including `sbrk()` and `mmap()`. A linked-list free-list manages reusable blocks using allocation strategies such as first-fit and best-fit, with block coalescing to reduce fragmentation.

A companion monitoring utility periodically reads `/proc/[pid]/status` and `/proc/[pid]/maps` and uses `getrusage()` to observe process memory behavior, including `VmSize`, `VmRSS`, and heap-growth information. Allocation events are logged for later analysis and visualization.

The implementation also considers multi-threaded safety using POSIX mutexes and uses signal handling to report abnormal memory-access events such as `SIGSEGV`.

## ❗ Problem Statement

Modern applications frequently depend on default memory allocators without direct visibility into allocation patterns, fragmentation, reclamation, or memory growth. This makes memory leaks and inefficient allocation strategies difficult to understand and diagnose.

The project addresses this problem by providing a transparent custom allocation mechanism and a real-time monitoring utility for Linux C/C++ applications.

## 🎯 Objectives

1. Implement custom `malloc()`, `calloc()`, `realloc()`, and `free()` functionality in C.
2. Use Linux `brk()`/`sbrk()` and `mmap()` mechanisms for memory acquisition.
3. Maintain a free list with first-fit/best-fit allocation and block coalescing.
4. Monitor process memory through `/proc/[pid]/status` and `/proc/[pid]/maps`.
5. Use `getrusage()` for process resource and memory measurements.
6. Record allocation/deallocation events with timestamps, addresses, and sizes.
7. Provide thread-safe allocator operations using POSIX mutexes.
8. Detect and report abnormal memory-access conditions using signal handling.
9. Validate behavior with controlled test programs, GDB, and Valgrind.
10. Produce reproducible logs, measurements, visualizations, and reports.

---

## 🏗️ System Architecture

```text
                    ┌──────────────────────────┐
                    │      Test Application    │
                    │       C / C++ Program     │
                    └────────────┬─────────────┘
                                 │
                    malloc/calloc/realloc/free
                                 │
                                 ▼
             ┌────────────────────────────────────┐
             │       Custom Memory Allocator      │
             │                                    │
             │  • Block metadata                  │
             │  • Free list                       │
             │  • First-fit / Best-fit             │
             │  • Block splitting / coalescing    │
             │  • Thread synchronization           │
             └──────────────┬─────────────────────┘
                            │
                 ┌──────────┴──────────┐
                 ▼                     ▼
             brk/sbrk()             mmap()
                 │                     │
                 └──────────┬──────────┘
                            ▼
                     Linux Process Memory

                            ▲
                            │
                ┌───────────┴────────────┐
                │    Memory Monitor      │
                │                        │
                │ /proc/<pid>/status     │
                │ /proc/<pid>/maps       │
                │ getrusage()            │
                │ periodic sampling      │
                └───────────┬────────────┘
                            │
                            ▼
                  Logs / Results / Reports
```

## 🔧 Core Linux Concepts and APIs

| API / Concept | Role |
|---|---|
| `malloc()` | Dynamic allocation interface implemented by the project |
| `calloc()` | Zero-initialized dynamic allocation |
| `realloc()` | Resizing an allocated block |
| `free()` | Returning an allocated block to the allocator |
| `brk()` / `sbrk()` | Process heap expansion/reduction mechanism |
| `mmap()` / `munmap()` | Memory-mapped allocation and release |
| `/proc/[pid]/status` | Process memory statistics such as `VmSize` and `VmRSS` |
| `/proc/[pid]/maps` | Process virtual-memory region layout |
| `/proc/meminfo` | System-wide memory statistics |
| `getrusage()` | Process resource and memory-usage information |
| `pthread_mutex_t` | Synchronization of allocator operations |
| `SIGSEGV` | Abnormal/invalid memory-access signal |

---

## 📂 Project Structure

```text
Project/
├── src/
│   ├── allocator/       # Custom allocation implementation
│   ├── monitor/         # /proc and getrusage monitoring
│   ├── tests/           # Functional and stress tests
│   └── common/          # Shared headers/utilities
├── docs/
│   ├── architecture/   # System architecture and design
│   ├── experiments/    # Experiment methodology
│   └── api/             # Linux API notes
├── data/
│   └── README.md        # Data provenance / permitted datasets
├── results/
│   ├── logs/            # Allocation and monitoring logs
│   ├── benchmarks/     # Performance measurements
│   └── visualizations/ # Generated plots
└── reports/
    ├── reviews/         # Phase/review deliverables
    └── final/           # Final report
```

---

## 💻 Development Environment

### Recommended platform

- Ubuntu 24.04 LTS or compatible Linux distribution
- GCC 13+
- GNU Make
- GDB
- Valgrind
- Git
- Bash
- Python 3 + `matplotlib` for visualization

### Clone

```bash
git clone https://github.com/tejaswin-amara/OSSP_2520090104.git
cd OSSP_2520090104/Project
```

### Build

Once the implementation is present, the project should provide a reproducible Make-based build:

```bash
make
```

### Run tests

```bash
make test
```

### Debug with GDB

```bash
gdb ./build/<program>
```

### Check memory behavior with Valgrind

```bash
valgrind --leak-check=full --show-leak-kinds=all ./build/<program>
```

### Trace Linux system calls

```bash
strace -f ./build/<program>
```

> Exact executable names and targets should be documented in this file when the implementation is finalized.

---

## 📊 Monitoring and Reporting

The monitoring subsystem is intended to periodically capture:

- `VmSize`
- `VmRSS`
- Heap-region information from `/proc/[pid]/maps`
- Observed heap growth
- Allocation count
- Deallocation count
- Allocated bytes
- Freed bytes
- Active allocation count
- Fragmentation indicators
- Allocation/deallocation timestamps

Raw observations should be stored under `results/` and visualized using Python/Matplotlib or gnuplot.

---

## 🧪 Testing Strategy

Testing will cover:

1. Basic allocation and deallocation.
2. Zero-initialized allocation using `calloc()`.
3. Block resizing with `realloc()`.
4. Reuse of freed blocks.
5. Free-list splitting and coalescing.
6. First-fit versus best-fit behavior.
7. Large allocations through `mmap()`.
8. Repeated allocation/deallocation stress tests.
9. Multi-threaded allocation safety.
10. Memory-leak detection with Valgrind.
11. Invalid-memory-access handling.
12. Monitoring accuracy against `/proc` and `getrusage()`.

---

## 📈 Expected Results

The completed system should demonstrate:

- Correct dynamic allocation and deallocation.
- Reduced unnecessary fragmentation through free-list management.
- Correct block reuse and coalescing.
- Observable heap growth and process memory behavior.
- Reliable allocation/deallocation logging.
- Thread-safe allocator behavior.
- Reproducible memory-monitoring measurements.
- Evidence of memory leaks and their remediation.
- Benchmark comparisons between allocation strategies where applicable.

---

## 🗓️ Development Phases

| Phase | Deliverable | Status |
|---|---|---|
| Phase 1 | Problem statement, scope, architecture | 🟢 Baseline completed |
| Phase 2 | Allocator foundation and metadata | 🟡 In development |
| Phase 3 | Allocation strategies and memory acquisition | ⏳ Pending |
| Phase 4 | Monitoring and logging subsystem | ⏳ Pending |
| Phase 5 | Integration, concurrency and safety | ⏳ Pending |
| Phase 6 | Testing, benchmarking and visualization | ⏳ Pending |
| Phase 7 | Documentation, final report and demonstration | ⏳ Pending |

---

## 👨‍🏫 Course Alignment

The project primarily demonstrates **CO4 — Analyze** through Linux virtual memory, process address spaces, `malloc/free`, `brk/sbrk`, `mmap`, page-level memory behavior, and `/proc` inspection.

It also supports **CO6 — Apply** through POSIX threads and mutex-based synchronization, while the logging and Linux systems-programming workflow reinforces the broader course outcomes.

### Relevant modules

- **M1 — The OS as a Service Layer:** system calls and Linux user/kernel interaction.
- **M4 — Memory Management:** virtual memory, heap, `malloc/free`, `brk/sbrk`, `mmap`, `/proc`, memory bugs.
- **M6 — Concurrency Primitives:** threads, mutexes, races and synchronization.

---

## 🔐 Security and Data Policy

Do **not** commit:

- Passwords or credentials
- API keys or authentication tokens
- Private keys or certificates
- `.env` files containing secrets
- Confidential institutional data
- Restricted or licensed datasets without redistribution permission
- Local machine dumps or unnecessary generated files

External data sources must be documented in `data/README.md` with source, license, version/date, and reproduction instructions.

---

## 🌿 Git & Contribution Policy

This is an academic team repository. Contribution evidence must remain authentic.

- Every team member commits using their own GitHub account.
- Contributions are made progressively throughout the project.
- At least one meaningful team commit should be made per active project week.
- Each phase deliverable should receive an appropriate Git tag such as `review-1`, `review-2`, or `final`.
- Avoid bulk uploading the entire project from one account.
- Do not rewrite history to conceal contribution authorship.

The repository should remain accessible to the faculty/supervisor and Course Coordinator until final evaluation is complete.

---

## 📚 References

- Abraham Silberschatz, Peter B. Galvin & Greg Gagne — *Operating System Concepts*.
- Remzi H. Arpaci-Dusseau & Andrea C. Arpaci-Dusseau — *Operating Systems: Three Easy Pieces*.
- W. Richard Stevens & Stephen A. Rago — *Advanced Programming in the UNIX Environment*.
- Michael Kerrisk — *The Linux Programming Interface*.
- Linux manual pages: `man 2 brk`, `man 2 mmap`, `man 2 getrusage`, `man 5 proc`, `man 7 pthreads`.

---

## 📜 Academic Information

**Institution:** Koneru Lakshmaiah Education Foundation (Deemed to be University)  
**Course:** Operating Systems and Systems Programming (25CS2104E)  
**Section:** 10  
**Team:** 12  
**Faculty:** Manthena Raghupathi  
**Academic Year:** 2026–27  
**Project:** Linux Dynamic Memory Allocation and Memory Monitoring System

---

> **Status:** Project repository baseline established. Implementation, experiments, results, and final evaluation deliverables will be added progressively.
