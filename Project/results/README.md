# `results/` — Experimental Evidence

Store **measured project output** here.

## Suggested layout

```text
results/
├── logs/            # Allocation and monitor logs
├── benchmarks/      # Raw benchmark measurements
└── visualizations/  # Generated charts/figures
```

Every experiment should identify its workload, environment, allocator policy, sampling interval and commit SHA. Never fabricate measurements.

Keep large or reproducible generated artifacts out of the source tree. If an artifact is derived from a script, document the command that generated it.