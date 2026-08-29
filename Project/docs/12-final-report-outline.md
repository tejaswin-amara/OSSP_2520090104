# Final Project Report Outline

## 1. Title Page
- Institution
- Course and code
- Project title
- Team 12
- Team members and roll numbers
- Faculty: Manthena Raghupathi
- Academic year/term

## 2. Abstract
Summarize the problem, approach, implementation and measured outcome.

## 3. Introduction
Explain dynamic memory management and the motivation for transparent monitoring.

## 4. Problem Statement
State the engineering problem and its Linux context.

## 5. Objectives and Scope
List objectives, scope and limitations.

## 6. OS Concepts
Discuss process address spaces, heap management, virtual memory, system calls, `/proc`, synchronization and memory errors.

## 7. System Design
Include architecture, allocator metadata, free-list policy, memory acquisition and monitoring flow diagrams.

## 8. Implementation
Explain `malloc`, `calloc`, `realloc`, `free`, `sbrk`/`mmap`, logging, monitoring and concurrency mechanisms.

## 9. Testing
Describe unit, integration, stress and failure-case tests.

## 10. Experimental Results
Present measured allocation behavior, heap growth, VmRSS/VmSize, fragmentation indicators, reuse and leak-analysis results. Do not fabricate measurements.

## 11. Tool-Assisted Analysis
Discuss Valgrind, GDB, strace and AddressSanitizer results where used.

## 12. Team Contributions
Map each contribution to the Git history and deliverables.

## 13. Limitations
Discuss platform assumptions, `sbrk()` limitations, measurement limitations and non-production status.

## 14. Future Work
Potential improvements include more allocation policies, richer metrics, improved visualization, portability and stronger automated testing.

## 15. Conclusion
Summarize what was implemented and demonstrated.

## 16. References
List books, Linux manual pages, course resources and other authoritative sources used.