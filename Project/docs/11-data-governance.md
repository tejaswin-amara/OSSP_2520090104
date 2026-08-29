# Data Governance and Security

## Repository Policy

The repository must not contain passwords, API keys, access tokens, private keys, `.env` files, confidential institutional information, personally sensitive records, or datasets whose license does not permit repository distribution.

## Data Directory

`Project/data/` is reserved for small, permitted project inputs and documentation of external sources. If a dataset is externally hosted or restricted, store a source reference and acquisition instructions instead of copying the restricted data.

## Required Dataset Metadata

For every external data source document:

- Source/owner
- URL or official identifier
- Dataset/version
- Retrieval date
- License/terms
- Intended use
- Expected schema
- Reproduction/acquisition procedure

## Generated Data

Raw allocator logs, monitor samples and benchmark outputs should be stored under `Project/results/` when appropriate. Avoid committing unnecessarily large files or sensitive machine-specific information.

## Secrets

Use local environment variables or a secret-management mechanism for credentials. Verify `.gitignore` before committing.

## Incident Procedure

If a secret or restricted data is accidentally committed: stop sharing it, revoke/rotate the exposed credential, remove the sensitive content from the repository history as appropriate, notify the responsible course/project authority, and document the corrective action.