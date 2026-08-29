# Operating Systems & System Programming — Team Repository

> **KLH • CSIT • 2026–2027 • Team ID 2520090104**

## Project Information

| Field | Details |
|---|---|
| Project Title | Operating Systems & System Programming (OSSP) Coursework Project |
| Branch | CSIT |
| Academic Year | 2026–2027 |
| Team ID | 2520090104 |
| Repository | `KLH-CSIT-2026-2027-2520090104-OSSP` *(required naming target)* |
| Current Repository | `OSSP_2520090104` *(legacy name; rename requires repository-level GitHub action/Coordinator approval)* |
| Supervisor | **To be recorded before Section D submission** |
| Course | Operating Systems & System Programming |

## Team Members

| Name | University ID | GitHub Account |
|---|---:|---|
| Tejaswin Amara | 2520090104 | [@tejaswin-amara](https://github.com/tejaswin-amara) |
| Additional team member | To be recorded | To be recorded |

> Every actual team member must be listed with their university ID and must contribute from their own GitHub account. Do not use another member's account or a single-member bulk upload.

## Abstract

This repository provides the controlled academic workspace for the Operating Systems & System Programming project. It organizes practical implementations, skill activities, source code, supporting documentation, datasets or data-source references, generated results, and formal reports into a reproducible project structure. The repository is maintained progressively across project phases so that individual contributions, weekly development activity, and phase deliverables remain verifiable through Git history and tagged milestones.

## Repository Structure

```text
.
├── src/                         # Source code and implementations
├── docs/                        # Technical and project documentation
├── data/                        # Small permitted data or documented data sources
├── results/                     # Experimental outputs and observations
├── reports/                     # Phase/final reports and report assets
├── Module_01_OS_Service_Layer/  # Existing OSSP coursework
├── Module_02_Process_Control/
├── Module_03_IPC/
├── Module_04_Memory_Management/
├── Module_05_File_Systems/
├── Module_06_Concurrency/
├── .gitignore
└── README.md
```

The existing module structure is retained. Each module continues to use `Practical/` and `skills/` for coursework organization.

## Setup

1. Clone the repository.
2. Install the compiler/interpreter and tools required by the relevant module or project task.
3. Read the relevant documentation in `docs/` and the module README before execution.
4. Keep generated outputs under `results/` and formal deliverables under `reports/`.
5. Never commit credentials, API keys, licensed datasets, confidential institutional data, or local environment files.

Example:

```bash
git clone https://github.com/tejaswin-amara/OSSP_2520090104.git
cd OSSP_2520090104
```

## Execution

Execution instructions are maintained with each implementation. Start with the applicable module directory and follow its README. Source programs belong in `src/` or the appropriate module `Practical/` directory; reproducible outputs belong in `results/`.

## Contribution & Git History Policy

- Every team member commits using their own GitHub account.
- Contributions must be progressive; avoid bulk-uploading the complete project through one account.
- The team must maintain **at least one meaningful commit per week** during the active project phase.
- Use descriptive commit messages, for example:
  - `feat: implement process creation practical`
  - `docs: add IPC experiment documentation`
  - `test: validate concurrency implementation`
  - `report: submit phase review evidence`
- Each phase deliverable must be tagged in GitHub using the prescribed milestone names such as `review-1`, `review-2`, and `final`.

## Phase Status

**Current phase: Phase 1 — Repository Structure & Documentation Baseline**

| Deliverable | Status |
|---|---|
| Required top-level folders | In progress / baseline created |
| Project README | In progress — team/supervisor metadata requires completion |
| Source organization | Baseline established |
| Documentation organization | Baseline established |
| Data/data-source policy | Established |
| Results organization | Baseline established |
| Reports organization | Baseline established |
| Weekly contribution tracking | To continue progressively |
| Phase tags | To be created for each completed phase |
| Supervisor access | To be granted |
| Course Coordinator access | To be granted |

## Data & Security Policy

Do not commit:

- Passwords, tokens, API keys, private keys, or `.env` files.
- Licensed or restricted datasets unless redistribution is explicitly permitted.
- Confidential institutional, student, staff, or assessment data.
- Personal machine configuration, IDE state, build caches, or generated dependency folders.

If external data is required, document the authoritative source, access procedure, license/terms, and reproducibility notes in `data/README.md` instead of committing restricted data.

## Repository Governance

- The repository URL recorded for Section D must remain stable.
- Do not rename or transfer the repository after Section D recording without written consent from the Course Coordinator.
- Grant repository access to the supervisor and Course Coordinator.
- Keep the repository accessible until final project evaluation is completed.

## Phase Tagging Convention

Use annotated release tags for completed deliverables:

```text
review-1   → Phase/Review 1 deliverable
review-2   → Phase/Review 2 deliverable
final      → Final evaluated deliverable
```

Tags must point to the exact commit representing the submitted deliverable.

## Academic Integrity

All submitted work must represent the team's actual work and contributions. Git history is part of the contribution evidence. Do not rewrite history to conceal authorship or manufacture contribution activity.

---

**Repository status:** Structural compliance work is being completed. Team member, supervisor, access, weekly contribution, and release-tag actions must be completed through the appropriate GitHub accounts and course administration workflow.
