# Kid Icarus: Uprising

[![ByteMatch progress](https://bytematch.dev/oz8yslnv53/uprising.svg)](https://bytematch.dev/oz8yslnv53/uprising)

Public research archive for the Japanese Rev 1 release of *Kid Icarus: Uprising* on Nintendo 3DS. It publishes reverse-engineering metadata, historical reconstruction examples, and an objdiff-compatible progress report.
***This repository*** is not an active matching decompilation or a buildable game project.

## Scope and status

`src/`, `include/` and any other commit data are a frozen proof of concept from approximately two months before this archive was published. They document how the matching work was *initially* approached and validate the source links recorded in the catalog; they are not maintained, expanded, or presented as current reconstruction work.

***Public updates are limited to the inventories, research information, and objdiff/ByteMatch reporting support.*** In particular, do not treat a source file's presence as a promise of a reproducible build or a current match.

## Contents

- `data/functions.tsv` — JP Rev 1 function inventory: address, name, size,
  optional archived source path, and recorded match score.
- `data/data.tsv` — defined-data inventory: address, size, type, and label.
- `src/`, `include/` — frozen historical reconstruction snapshot.
- `scripts/generate_decomp_report.py` — creates the objdiff-compatible report
  used by ByteMatch.

The function inventory currently contains 24,890 functions. The data
inventory contains 164,072 uniquely measured objects totalling 925,843 bytes.
Function and data labels are analysis metadata, not redistributions of the
original executable.

## Progress report

The report is generated from a private repository.

## Credits

The project organization, inventory conventions, and parts of the historical
workflow were informed by the [Zelda: Twilight Princess decompilation
project](https://github.com/zeldaret/tp).

Decision to go public was taken from [Monster Hunter 4: Ultimate Decomp Repository](https://github.com/mhvuze/mh4u-decomp).
