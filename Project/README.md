# 🧠 Linux Dynamic Memory Allocation & Memory Monitoring System

**A Linux systems-programming project for transparent memory allocation, heap behavior, and process-memory monitoring.**

> **Operating Systems and Systems Programming · 25CS2104E · Section 10 · Team 12**

| | |
|---|---|
| 🏫 Institution | Koneru Lakshmaiah Education Foundation (Deemed to be University) |
| 👨‍🏫 Faculty | **Manthena Raghupathi** |
| 📅 Academic Year | **2026–27 · Term-I** |
| 👥 Team | **12** |
| 🐧 Platform | Linux / Ubuntu |
| 💻 Language | C / C++ |

---

## ✨ What This Project Does

This project builds an **educational custom memory-management and monitoring stack for Linux**. It combines a custom allocator, low-level memory acquisition, allocation logging, and process-memory observation.

### Core capabilities

- Custom `malloc`, `calloc`, `realloc`, and `free` behavior
- `sbrk()` / `brk()` and `mmap()` based memory acquisition
- Free-list management with first-fit/best-fit policies
- Block splitting and coalescing
- Timestamped allocation/deallocation logging
- `/proc/<pid>/status` and `/proc/<pid>/maps` monitoring
- `getrusage()` measurements
- POSIX mutex-based synchronization
- Validation with GDB, Valgrind, AddressSanitizer and strace where compatible

> **Academic scope:** this is an educational allocator and observability project, not a replacement for the production Linux/glibc allocator.

---

## 👥 Team 12

| Roll No. | Member | Primary Contribution |
|---|---|---|
| **2520030456** | **T. Arun** | Core allocator using `malloc()`/`free()` and `brk()`/`sbrk()`; allocation/deallocation event logging. |
| **2520090104** | **Tejaswin Amara** | `/proc/[pid]/status`, `/proc/[pid]/maps`, `getrusage()`, periodic sampling and reporting. |
| **2520090140** | **U. Vinay Sampath** | Integration, testing, Valgrind validation, test cases, documentation and final report. |

**Supervisor:** Manthena Raghupathi

> Contribution evidence is maintained through authentic GitHub history. Each member must commit their own work from their own account.

---

## 🧩 Architecture

```text
                         ┌───────────────────────┐
                         │  Test / Demo Program  │
                         └───────────┬───────────┘
                                     │
                       malloc / calloc / realloc / free
                                     │
                                     ▼
                 ┌─────────────────────────────────────┐
                 │         CUSTOM ALLOCATOR            │
                 │                                     │
                 │ Metadata · Free List · Fit Policy   │
                 │ Split · Coalesce · Synchronization  │
                 └──────────────┬──────────┬───────────┘
                                │          │
                           sbrk/brk      mmap/munmap
                                │          │
                                └────┬─────┘
                                     ▼
                            Linux Process Memory
                                     ▲
                                     │
                 ┌───────────────────┴──────────────────┐
                 │            MEMORY MONITOR            │
                 │ /proc/<pid>/status · /proc/<pid>/maps│
                 │ /proc/meminfo · getrusage()          │
                 │ Periodic sampling · reporting        │
                 └───────────────────┬──────────────────┘
                                     │
                                     ▼
                         ┌────────────────────────┐
                         │ Logs · Results · Charts│
                         └────────────────────────┘
```

---

## 🎯 Objectives

1. Implement custom `malloc()`, `calloc()`, `realloc()` and `free()` behavior in C.
2. Demonstrate Linux memory acquisition with `brk()`/`sbrk()` and `mmap()`.
3. Maintain reusable blocks through free-list metadata.
4. Support or compare first-fit and best-fit allocation policies.
5. Reduce fragmentation through safe splitting and coalescing.
6. Monitor process memory through `/proc` and `getrusage()`.
7. Produce structured allocation/deallocation logs.
8. Exercise thread-safe allocator state with POSIX mutexes.
9. Validate behavior with automated tests and diagnostic tooling.
10. Produce reproducible academic evidence, benchmarks and reports.

---

## 🧠 OS Concepts Demonstrated

| Concept | Demonstrated Through |
|---|---|
| Virtual memory | Process address space and `/proc/<pid>/maps` |
| Dynamic allocation | Custom allocation primitives |
| Heap management | `brk()` / `sbrk()` |
| Memory mapping | `mmap()` / `munmap()` |
| Process monitoring | `/proc/<pid>/status` |
| Resource accounting | `getrusage()` |
| Fragmentation | Free-list, splitting and coalescing |
| Concurrency | POSIX threads and mutexes |
| Fault analysis | GDB, Valgrind, ASan and controlled signal handling |
| System-call tracing | `strace` |

---

## 📁 Repository Map

```text
OSSP_2520090104/
├── README.md                         # Course-level overview
├── Practical/                        # Practical course material
├── Skills/                           # Skills/course material
│
└── Project/
    ├── README.md                     # Project guide
    ├── src/                          # Implementation and tests
    ├── docs/                         # Design and project documentation
    ├── data/                         # Permitted inputs / source references
    ├── results/                      # Logs, measurements and visualizations
    └── reports/                      # Review and final academic reports
```

### Documentation index

| Document | Purpose |
|---|---|
| [Project Charter](docs/01-project-charter.md) | Scope, goals, risks and success criteria |
| [Requirements](docs/02-requirements-specification.md) | Functional and non-functional requirements |
| [Architecture](docs/03-system-architecture.md) | Components, interfaces and invariants |
| [Linux API Reference](docs/04-api-system-call-reference.md) | System calls and APIs used |
| [Testing Plan](docs/05-testing-validation-plan.md) | Test strategy and acceptance criteria |
| [Developer Guide](docs/06-user-and-developer-guide.md) | Build/debug/development workflow |
| [Phase Plan](docs/07-phase-plan.md) | Milestones and review tags |
| [Benchmark Template](docs/08-results-and-benchmarking-template.md) | Reproducible experiment format |
| [Demo Script](docs/09-demo-script.md) | Final demonstration flow |
| [Troubleshooting](docs/10-troubleshooting.md) | Common development problems |
| [Data Governance](docs/11-data-governance.md) | Data and security policy |
| [Final Report Outline](docs/12-final-report-outline.md) | Report structure |

---

## 🛠️ Development Environment

**Recommended:** Ubuntu 24.04 LTS or compatible Linux distribution, GCC 13+, GNU Make, GDB, Valgrind, Git and Bash. Python 3 + Matplotlib may be used for visualization.

```bash
cd Project
make
make test
```

### Debugging

```bash
gdb ./build/<program>
valgrind --leak-check=full --show-leak-kinds=all ./build/<program>
strace -f -e trace=brk,mmap,munmap ./build/<program>
```

> Executable names and Make targets must match the actual implementation. Do not leave unverified commands in the documentation.

---

## 📊 Monitoring Model

The monitor is designed to capture:

- `VmSize`
- `VmRSS`
- heap mapping/address-range information
- observed heap growth
- allocation/deallocation counts
- active allocation count
- allocated/freed bytes
- fragmentation indicators
- timestamps and process identity

Measurements should be stored with environment and workload metadata so experiments remain reproducible.

---

## 🧪 Validation Strategy

### Functional

- Small, medium and large allocations
- `calloc()` zero initialization
- `realloc()` data preservation
- Free-block reuse
- Splitting and coalescing
- First-fit/best-fit behavior
- Large `mmap()` allocations

### Robustness

- Zero-size requests
- `calloc()` integer-overflow checks
- Allocation failure
- Controlled metadata-corruption tests
- Repeated allocation/free stress
- Multi-threaded workloads

### Tool-assisted

| Tool | Purpose |
|---|---|
| GDB | State and crash inspection |
| Valgrind | Leak and invalid-access analysis |
| AddressSanitizer | Compiler-assisted memory diagnostics where compatible |
| strace | Observation of memory-related system calls |

---

## 📈 Results Policy

**Results are measured, not invented.** Every benchmark should record the commit SHA, OS/kernel, compiler, build flags, allocator policy, workload, thread count, sampling interval, raw measurements and interpretation/limitations.

Use the [benchmarking template](docs/08-results-and-benchmarking-template.md) and store evidence in `results/`.

---

## 🗺️ Project Status

| Area | Status |
|---|---|
| Project definition | 🟢 Complete |
| Requirements | 🟢 Complete |
| Architecture | 🟢 Documented |
| Documentation framework | 🟢 Complete |
| Allocator implementation | 🟡 Development |
| Monitoring implementation | 🟡 Development |
| Integration | ⚪ Pending |
| Automated validation | ⚪ Pending |
| Benchmarking | ⚪ Pending |
| Final report | ⚪ Pending |
| Final demonstration | ⚪ Pending |

---

## 🎓 Course Alignment

The project strongly supports **CO4 — Analyze** through virtual memory, heap behavior, `brk()`/`sbrk()`, `mmap()`, `/proc` inspection and memory-error analysis.

It also supports **CO6 — Apply** through POSIX threads and mutex synchronization, while reinforcing systems-programming practices from the wider course.

---

## 🔐 Academic & Repository Governance

- Every team member contributes through their own GitHub account.
- Contributions are progressive; avoid single-member bulk uploads.
- Make at least one meaningful team commit per active project week.
- Tag completed phase deliverables, e.g. `review-1`, `review-2`, `final`.
- Grant repository access to the supervisor and Course Coordinator.
- Keep the repository accessible until final evaluation is complete.
- Never commit credentials, API keys, private keys, confidential institutional data or unauthorized licensed datasets.
- The recorded repository URL must not be renamed or transferred without written consent from the Course Coordinator.

---

## 📚 References

- Silberschatz, Galvin & Gagne — *Operating System Concepts*.
- Arpaci-Dusseau & Arpaci-Dusseau — *Operating Systems: Three Easy Pieces*.
- Stevens & Rago — *Advanced Programming in the UNIX Environment*.
- Kerrisk — *The Linux Programming Interface*.
- Linux manual pages for `brk`, `mmap`, `getrusage`, `proc`, `pthread`, `sigaction` and related APIs.

---

## 📌 Academic Record

**Institution:** Koneru Lakshmaiah Education Foundation  
**Course:** Operating Systems and Systems Programming (25CS2104E)  
**Section:** 10  
**Team:** 12  
**Faculty:** Manthena Raghupathi  
**Academic Year:** 2026–27 · Term-I  
**Project:** Linux Dynamic Memory Allocation and Memory Monitoring System

---

> **Built for learning how Linux memory really works — from allocation metadata to the process address space.**
