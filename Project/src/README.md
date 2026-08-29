# `src/` — Implementation

This directory contains the actual project implementation and automated tests.

## Recommended layout

```text
src/
├── allocator/     # Allocation engine and block metadata
├── monitor/       # /proc and getrusage monitoring
├── common/        # Shared types, utilities and logging interfaces
└── tests/         # Unit, integration and stress tests
```

Keep implementation code separate from generated binaries and logs. Build output belongs in an ignored `build/` directory; experimental output belongs in `../results/`.