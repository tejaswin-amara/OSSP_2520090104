# Project Phase Plan

| Phase | Deliverable | Evidence | Status |
|---|---|---|---|
| Phase 1 | Problem definition, requirements and architecture | Charter, SRS, architecture | Completed/documented |
| Phase 2 | Allocator core | Source, unit tests, allocator logs | In progress |
| Phase 3 | Monitoring module | Monitor source, sample logs | In progress |
| Phase 4 | Integration and concurrency | Integration tests, stress tests | Pending |
| Phase 5 | Validation and benchmarking | Valgrind/ASan/strace evidence, benchmarks | Pending |
| Phase 6 | Final documentation and report | Final report, results, demo evidence | Pending |

## Git Tag Policy

Each completed phase deliverable should be tagged, for example:

```text
review-1
review-2
final
```

Tags must correspond to genuine completed milestones. Do not create retrospective or misleading contribution history.

## Weekly Contribution Policy

During active development, the team records at least one meaningful commit per week. Each member commits their own work using their own GitHub account so contribution history remains verifiable.

## Suggested Milestones

- `review-1`: requirements + architecture + initial allocator
- `review-2`: monitoring + integrated implementation + test suite
- `final`: validated implementation + results + final report + demo evidence