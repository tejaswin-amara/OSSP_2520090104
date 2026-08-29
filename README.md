# Linux Dynamic Memory Allocation and Memory Monitoring System

> **Koneru Lakshmaiah Education Foundation (Deemed to be University estd. u/s. 3 of the UGC Act, 1956)**  
> Bachupally-Gandimaisamma Road, Bowrampet, Hyderabad, Telangana - 500 043  
> Phone: 7815926816 · [www.klh.edu.in](https://www.klh.edu.in/)

## Course & Project Information

| Field | Details |
|---|---|
| Course | **OPERATING SYSTEMS AND SYSTEMS PROGRAMMING (25CS2104E)** |
| Course Format | **PBL25CS2104E · PCC · CAPS** |
| Credits | **4** |
| Contact Hours | **8/week** |
| Academic Term | **2026–27, Term-I** |
| Trimester | **T04** |
| Document | Project Problem Statement Submission Form |
| Section No. | **10** |
| Team No. | **12** |
| Project Title | **Linux Dynamic Memory Allocation and Memory Monitoring System** |
| Supervisor / Faculty | To be recorded |

## Team Members

| Roll Number | Student Name | GitHub Account |
|---:|---|---|
| 2520030456 | T. Arun | To be recorded |
| 2520090104 | Tejaswin Amara | [@tejaswin-amara](https://github.com/tejaswin-amara) |
| 2520090140 | U. Vinay Sampath | To be recorded |

> Every team member must commit using their own GitHub account. Individual contribution is verified through Git history.

## Individual Contribution

| Roll Number | Student Name | Individual Responsibility |
|---:|---|---|
| 2520030456 | T. Arun | Designed and implemented the core memory allocation module using `malloc()`/`free()` and `brk()`/`sbrk()`; built the logging mechanism that records the size, address, and timestamp of every allocation/deallocation event. |
| 2520090104 | Tejaswin Amara | Developed the memory monitoring component that reads `/proc/[pid]/status` and `/proc/[pid]/maps` and uses `getrusage()` to capture `VmSize`, `VmRSS`, and heap growth; implemented periodic sampling and reporting logic. |
| 2520090140 | U. Vinay Sampath | Handled integration and testing of the allocator and monitoring modules, cross-validated memory leak detection using Valgrind, and prepared the test cases, documentation, and project report. |

---

# Official Course Detail

## Course Objective & Rationale

Operating Systems and Systems Programming teaches what happens between a program and the hardware. The PBL track follows an **outside-in, project-driven** approach: students begin with a working Unix-style shell and progressively understand the system calls and kernel mechanisms behind process creation, execution, pipes, waiting, signals, memory, files, and concurrency.

The standard Unix/Linux toolchain is **gcc, make, gdb, valgrind, and strace**. The course builds upon **DDCA** (CPU and memory model), **DSA-1** (linked lists, queues, and hash tables), and **PSPJ**. It enables **ESDT — Embedded Software Development**, **CDIS — Cloud Infrastructure**, **SDSR — System Design for Scalability**, and **CICD**.

**Self-Learning Material:** [25CS2104E SLM](https://y25btech.klef.in/slm/25CS2104E.html)

## Course Outcomes

| CO | BTL | Course Outcome |
|---|---|---|
| **CO1** | BTL4 — Analyze | Analyze the OS as a layered service abstraction, including kernel/user mode, syscall interface, shell behavior, and command execution. |
| **CO2** | BTL3 — Apply | Apply `fork`, `exec`, `wait`, and `exit` to create, control, and correctly reap child processes. |
| **CO3** | BTL3 — Apply | Apply pipes, FIFOs, Unix domain sockets, signals, shared memory, and semaphores for IPC. |
| **CO4** | BTL4 — Analyze | Analyze virtual memory, paging, address translation, TLBs, page faults, demand paging, and copy-on-write. |
| **CO5** | BTL4 — Analyze | Analyze file-system abstractions, VFS, inodes, directory entries, file descriptors, and file-I/O syscalls. |
| **CO6** | BTL3 — Apply | Apply POSIX threads, mutexes, condition variables, and semaphores while reasoning about races, deadlocks, and starvation. |

## Module-Wise Syllabus

### M1 — The OS as a Service Layer

**Maps to CO1.** Working Unix shell; kernel/user-space split; privileged and unprivileged execution; syscalls; `strace`; Linux kernel architecture; glibc wrappers; `man 2`/`man 3`; `errno`; return-value checking; C systems programming.

### M2 — Processes and Process Control

**Maps to CO2.** Process abstraction and PCB; lifecycle; `fork()`; `exec()`; `wait()`/`waitpid()`; `SIGCHLD`; `exit()`/`_exit()`; conceptual Linux scheduling; zombies; fork bombs; inherited file descriptors.

### M3 — Inter-Process Communication

**Maps to CO3.** Anonymous pipes; `pipe()`; `dup2()`; FIFOs via `mkfifo()`; signals; `sigaction()`; process groups and sessions; Unix domain sockets; shared memory; POSIX/System V semaphores; choosing IPC mechanisms by problem profile.

### M4 — Memory Management

**Maps to CO4.** Virtual-memory illusion; page tables; virtual-to-physical translation; TLB; minor/major page faults; demand paging; Linux process address space; `malloc()`/`free()`; `brk()`/`sbrk()`/`mmap()`; segmentation faults; stack overflow; double-free; use-after-free; copy-on-write; Valgrind; AddressSanitizer; `/proc/<pid>/maps`.

### M5 — File Systems

**Maps to CO5.** Unix “everything is a file”; regular files, directories, devices, sockets and FIFOs; inodes; directory entries; hard links; symbolic links; VFS; file descriptors; `open()`; `read()`; `write()`; `lseek()`; `close()`; buffered/unbuffered I/O; `mmap()`; ext4 and journaling concepts.

### M6 — Concurrency Primitives

**Maps to CO6.** Threads vs processes; POSIX threads; `pthread_create()`/`pthread_join()`/`pthread_exit()`; race conditions; mutexes; condition variables; counting semaphores; producer-consumer patterns; deadlock's four conditions; lock ordering; starvation; read-write locks and atomics.

---

# Anchor Project — Shellforge

The official PBL course outline identifies **Shellforge — A Unix-Style Shell from Scratch in C** as the twelve-week anchor project.

### Functional Features

- Interactive prompt and command history.
- Quoting and escaping.
- Environment-variable expansion and command substitution.
- Arbitrary-length pipelines.
- Input/output/error redirection.
- Background jobs and job control (`jobs`, `fg`, `bg`).
- `Ctrl-C` and `Ctrl-Z` signal handling.
- Built-ins: `cd`, `pwd`, `exit`, `jobs`, `fg`, `bg`, `history`, `export`.

### Core System Calls

`fork()`, `exec()`, `pipe()`, `dup2()`, `waitpid()`, `kill()`, and `sigaction()`.

### Minimal Tool Stack

- GCC 13+ with `-Wall -Wextra -Werror`
- GNU Make
- GDB
- Valgrind
- strace
- Git + GitHub
- Linux laptop/VM; Ubuntu 24.04 LTS recommended

### Twelve-Week Build Flow

| Stage | Focus |
|---|---|
| Weeks 1–2 | Shell fundamentals, OS/service-layer concepts, environment setup |
| Week 3 | Command parsing, quoting, escaping |
| Weeks 4–5 | `fork()`/`exec()` and simple commands |
| Weeks 6–7 | Pipes and multi-process pipelines |
| Weeks 8–9 | I/O redirection |
| Weeks 10–11 | Signals and job control |
| Week 12 | Integration, testing, debugging, documentation, polish |

> **Project-specific note:** Shellforge is the official course-level PBL anchor project. The team's submitted project for this repository remains **Linux Dynamic Memory Allocation and Memory Monitoring System**.

---

# Submitted Project

## Abstract

Dynamic memory management directly affects application performance, reliability, and system stability. This project proposes a **Linux Dynamic Memory Allocation and Memory Monitoring System** consisting of a custom heap allocator and a real-time memory monitoring utility.

The allocator implements `malloc`, `calloc`, `realloc`, and `free` from scratch using low-level Linux mechanisms such as `sbrk()` and `mmap()`. The monitoring component reads process and system-wide memory statistics from `/proc/[pid]/status` and `/proc/meminfo` to display live memory consumption, fragmentation levels, and allocation patterns.

The system addresses memory leaks, fragmentation, and inefficient allocation through free-list management and first-fit/best-fit policies. POSIX mutex locks provide multi-threaded safety, while signal handling such as `SIGSEGV` supports abnormal memory-access detection.

## Problem Statement

Modern applications often rely on default memory allocators without sufficient visibility into allocation, fragmentation, or reclamation. This makes leaks and inefficient allocation strategies difficult to diagnose.

This project develops a transparent custom allocation mechanism combined with a real-time monitoring system exposing allocation, deallocation, memory-consumption, and fragmentation statistics for C/C++ applications on Linux.

## Objectives

1. Implement a custom C dynamic memory allocator using `sbrk()` and `mmap()` with `malloc`, `calloc`, `realloc`, and `free` behavior.
2. Develop a real-time memory-monitoring module using `/proc` statistics.
3. Implement free-list management and first-fit/best-fit strategies with fragmentation reduction.
4. Log and visualize allocation trends and detect memory leaks.

## Proposed Methodology

The project consists of two integrated components on Linux/Ubuntu using C/C++.

### Memory Allocator

The allocator manages process memory through `sbrk()` and `mmap()`, maintains linked-list metadata for a free list, supports first-fit and best-fit strategies, and coalesces free blocks.

### Memory Monitoring

A companion utility periodically reads `/proc/[pid]/status` and `/proc/[pid]/maps`, and uses `getrusage()` to collect process memory metrics such as `VmSize`, `VmRSS`, and heap-growth observations for logging and reporting.

### Safety & Concurrency

POSIX threads and mutex locks provide thread-safe allocator operations. Signal handling, including `SIGSEGV`, supports abnormal memory-access detection and reporting.

## OS Concepts / Linux APIs

| Concept / API | Purpose |
|---|---|
| `malloc`, `calloc`, `realloc`, `free` | Custom dynamic allocation primitives |
| `brk`, `sbrk` | Process heap management |
| `mmap`, `munmap` | Memory-mapped allocation/release |
| `/proc/[pid]/status`, `/proc/[pid]/maps`, `/proc/meminfo` | Process/system memory statistics and address-space inspection |
| `getrusage()` | Process resource and memory-usage measurements |
| POSIX `pthread` + mutexes | Thread-safe allocation |
| `SIGSEGV` / signal handling | Abnormal memory-access detection |

## Tools / Platforms

| Tool | Purpose |
|---|---|
| Linux / Ubuntu | Development and testing |
| C / C++ | System-level implementation |
| Valgrind / GDB | Debugging and memory analysis |
| gnuplot / Python (`matplotlib`) | Visualization |
| Bash | Build/test/monitoring automation |

## Expected Outcome

- Functional custom dynamic memory allocator.
- Real-time `/proc`-based monitoring utility.
- Sample test programs.
- Allocation/deallocation logs.
- Memory-usage and allocation visualizations.
- Memory-leak and fragmentation analysis.
- Thread-safe allocator operations.

---

# Repository Structure

```text
OSSP_2520090104/
├── Project/
│   ├── src/
│   ├── docs/
│   ├── data/
│   ├── results/
│   └── reports/
├── .gitignore
└── README.md
```

| Directory | Purpose |
|---|---|
| `Project/src/` | Allocator, monitor, tests, and supporting source code |
| `Project/docs/` | Architecture, methodology, API notes, experiments, documentation |
| `Project/data/` | Permitted data or documented external data sources |
| `Project/results/` | Logs, measurements, benchmarks, observations, visualizations |
| `Project/reports/` | Review submissions and final academic reports |

# Setup & Execution

## Prerequisites

- Linux/Ubuntu.
- GCC/G++ with POSIX thread support.
- Git.
- Optional: Valgrind, GDB, Python/matplotlib, gnuplot.

## Clone

```bash
git clone https://github.com/tejaswin-amara/OSSP_2520090104.git
cd OSSP_2520090104
```

Build and execution instructions for each implementation should be maintained in `Project/docs/` and alongside the relevant source. Generated outputs belong in `Project/results/`.

# GitHub & Project Governance

- Repository created: **YES**
- Every team member commits under their own GitHub account.
- Contributions must be progressive through each project phase.
- Minimum one meaningful team commit per week during active project work.
- Each completed phase deliverable must be tagged, e.g. `review-1`, `review-2`, `final`.
- Supervisor and Course Coordinator must be granted repository access.
- Repository remains accessible until final project evaluation.
- Never commit credentials, API keys, private keys, licensed/restricted datasets without permission, or confidential institutional data.
- The repository URL recorded in Section D must not be renamed or transferred without written consent from the Course Coordinator.

# Phase Status

**Current Phase: Project Problem Statement / Course Alignment Baseline**

| Deliverable | Status |
|---|---|
| Official course information | ✅ Documented |
| CO1–CO6 | ✅ Documented |
| M1–M6 syllabus | ✅ Documented |
| Shellforge anchor-project reference | ✅ Documented |
| Submitted project title/scope | ✅ Documented |
| Abstract/problem statement/objectives | ✅ Documented |
| Methodology and OS APIs | ✅ Documented |
| Team No. | ✅ Team 12 |
| Individual responsibilities | ✅ Assigned |
| Required project folders | ✅ Established under `Project/` |
| Supervisor/faculty | ⏳ Not provided in source document |
| Supervisor/Course Coordinator access | ⏳ Administrative action required |
| Weekly contributions | ⏳ Ongoing |
| Review tags | ⏳ Create when deliverables are actually complete |
| Final evaluation | ⏳ Pending |

# Faculty & Approval

| Field | Status |
|---|---|
| Faculty Name | To be recorded |
| Faculty Signature | To be obtained |
| Remarks | To be recorded |
| Project Approved | To be recorded |
| Approval Date | To be recorded |

# Data & Security Policy

Never commit passwords, authentication tokens, API keys, private keys, `.env` files, restricted/licensed datasets without redistribution permission, confidential institutional information, local IDE configuration, build caches, or unnecessary generated files.

For external or restricted datasets, document the authoritative source, license/usage terms, version/retrieval date, schema, and reproduction/access procedure in `Project/data/README.md`.

# Academic Integrity

Git history forms part of the project's contribution evidence. Team members must make genuine, meaningful contributions from their own GitHub accounts. Do not manufacture commits, rewrite history to conceal authorship, or use a single account for bulk uploads.

# Reference Books

1. **Operating System Concepts** — Abraham Silberschatz, Peter Baer Galvin & Greg Gagne, Wiley, 2018, 10th Ed.
2. **Operating Systems: Three Easy Pieces** — Remzi H. Arpaci-Dusseau & Andrea C. Arpaci-Dusseau, 2023.
3. **Modern Operating Systems** — Andrew S. Tanenbaum & Herbert Bos, Pearson, 2022, 5th Ed.
4. **Advanced Programming in the UNIX Environment** — W. Richard Stevens & Stephen A. Rago, Addison-Wesley, 2013, 3rd Ed.
5. **The Linux Programming Interface** — Michael Kerrisk, No Starch Press, 2010.
6. **Computer Systems: A Programmer's Perspective** — Randal E. Bryant & David R. O'Hallaron, Pearson, 2015, 3rd Ed.

# Recommended Online Resources

1. [NPTEL — Introduction to Operating Systems](https://nptel.ac.in/courses/106106144)
2. [NPTEL — Operating System Fundamentals](https://nptel.ac.in/courses/106105214)
3. [Coursera — Nand to Tetris Part II](https://www.coursera.org/learn/nand2tetris2)
4. [MIT 6.S081 — Operating System Engineering](https://pdos.csail.mit.edu/6.S081/)
5. [OSTEP — Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/)

---

**Course:** Operating Systems and Systems Programming (25CS2104E)  
**Term:** 2026–27, Term-I  
**Section:** 10  
**Project:** Linux Dynamic Memory Allocation and Memory Monitoring System  
**Team:** 12
