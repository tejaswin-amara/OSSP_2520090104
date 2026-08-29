# Results and Benchmarking Template

Use this template for every controlled experiment. Replace placeholders with measured values; do not invent results.

## Environment

| Parameter | Value |
|---|---|
| OS | `<distribution/version>` |
| Kernel | `<uname -r>` |
| CPU | `<model>` |
| RAM | `<capacity>` |
| Compiler | `<gcc --version>` |
| Build flags | `<flags>` |
| Allocator policy | `<first-fit/best-fit>` |
| Sampling interval | `<ms/s>` |

## Workload

- Number of allocations: `<N>`
- Size distribution: `<description>`
- Free pattern: `<description>`
- Reallocation count: `<N>`
- Threads: `<N>`
- Duration: `<duration>`

## Metrics

| Metric | Baseline | Custom allocator | Notes |
|---|---:|---:|---|
| Allocation success rate | TBD | TBD | |
| Mean allocation latency | TBD | TBD | |
| Peak heap growth | TBD | TBD | |
| Peak VmRSS | TBD | TBD | |
| Peak VmSize | TBD | TBD | |
| Reused blocks | TBD | TBD | |
| Free blocks | TBD | TBD | |
| Fragmentation indicator | TBD | TBD | Define formula |
| Reported leaks | TBD | TBD | |

## Interpretation

Explain observed differences, workload sensitivity, allocator policy effects, and measurement limitations. Distinguish measured facts from hypotheses.

## Reproduction

Record the exact command, input parameters, commit SHA and environment used for each benchmark.