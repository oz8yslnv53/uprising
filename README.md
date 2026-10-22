# Kid Icarus: Uprising

[![ByteMatch progress](https://bytematch.dev/oz8yslnv53/uprising.svg)](https://bytematch.dev/oz8yslnv53/uprising)

Public research archive for the Japanese Rev 1 release of *Kid Icarus: Uprising* on Nintendo 3DS. It publishes reverse-engineering metadata, historical reconstruction examples, and an objdiff-compatible progress report.
***This repository*** is not an active matching decompilation or a buildable game project.

## Scope and status

`src/`, `include/` and any other committed data are a frozen proof of concept from approximately two months before this archive was published. They document how the matching work was *initially* approached and validate the source links recorded in the catalog; they are not maintained, expanded, or presented as current reconstruction work. A lot of it overuses casts, lacks proper data structures, uses direct offsets, and has other practices that do not make for final, correct work.

The repository deliberately contains no game executable, ROM, extracted assets, object files, SDK, or compiler. The sole exceptions are the Nintendo 3DS application icon and project banner in `assets/`, included only for the ByteMatch project page. Obtain any other game material lawfully and keep it outside this checkout.

***Public updates are limited to the inventories, research information, and objdiff/ByteMatch reporting support.*** In particular, do not treat a source file's presence as a promise of a reproducible build or a current match.

## Contents

- `data/functions.tsv` — JP Rev 1 function inventory: address, name, size,
  optional archived source path, and recorded match score.
- `data/data.tsv` — defined-data inventory: address, size, type, and label.
- `data/provenance.json` — committed private catalog revision and score profile
  used for the current public score export.
- `assets/icon.png` — 512px project icon extracted from the JP Rev 1 SMDH.
- `assets/banner.jpg` — 1600×800 project banner for ByteMatch.
- `src/`, `include/` — frozen historical reconstruction snapshot.
- `scripts/generate_decomp_report.py` — creates the objdiff-compatible report
  used by ByteMatch.

The function inventory currently contains 24,890 functions. The data
inventory contains 164,072 uniquely measured objects totalling 925,843 bytes.
Function and data labels are analysis metadata, not redistributions of the
original executable.

## Progress report

The report is generated from a private repository. Its scores are exported
from the latest committed private `score_armcc41_nintendo` ledger; the exact
source revision and profile are in `data/provenance.json`. They do not
establish that the frozen public sources can currently be built or byte-matched.

On every push, GitHub Actions generates the public report and uploads it as
`jp_rev1_report`. It groups functions by their current private-tree subsystem
metadata (for example `camera`, `render`, and `runtime`); functions with no
known subsystem remain in `unknown`. ByteMatch reads that artifact for the
public project page.

## Credits

The project organization, inventory conventions, and parts of the historical
workflow were informed by the [Zelda: Twilight Princess decompilation
project](https://github.com/zeldaret/tp).

Decision to go public was taken from [Monster Hunter 4: Ultimate Decomp Repository](https://github.com/mhvuze/mh4u-decomp).
