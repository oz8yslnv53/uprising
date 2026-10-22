# Kid Icarus: Uprising — research archive

[![ByteMatch progress](https://bytematch.dev/oz8yslnv53/uprising.svg)](https://bytematch.dev/oz8yslnv53/uprising)

Public research archive for the Japanese Rev 1 release of *Kid Icarus:
Uprising* on Nintendo 3DS. It publishes reverse-engineering metadata,
historical reconstruction examples, and an objdiff-compatible progress report.
It is not an active matching decompilation or a buildable game project.

## Scope and status

The repository deliberately contains no game executable, ROM, extracted
assets, object files, SDK, or compiler. Obtain any such material lawfully and
keep it outside this checkout.

`src/` and `include/` are a frozen proof of concept from approximately two
months before this archive was published. They document how the matching work
was approached and validate the source links recorded in the catalog; they are
not maintained, expanded, or presented as current reconstruction work.

Public updates are limited to the inventories, research information, and
objdiff/ByteMatch reporting support. In particular, do not treat a source
file's presence as a promise of a reproducible build or a current match.

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

Generate the report locally with Python 3.9 or newer:

```sh
python3 scripts/generate_decomp_report.py --output build/report.json
```

The report is derived only from the public TSV inventories. Its match scores
are historical records with their original compiler/target context; they do
not establish that the frozen sources can currently be built or byte-matched.

On every push, GitHub Actions generates this report and uploads it as
`jp_rev1_report`. ByteMatch reads that artifact for the public project page.
Register the GitHub repository with ByteMatch and install its GitHub App (or
wait for polling) to ingest the report.

## Historical validation context

The archived work targeted the Japanese Rev 1 build, using the 3DS CTR SDK
3.2.5.200 context and ARM Compiler 4.1 as a matching reference. Reproducing
or independently checking a historical score requires a lawful copy of the
appropriate target material and toolchain; neither is supplied here.

## Credits

The project organization, inventory conventions, and parts of the historical
workflow were informed by the [Zelda: Twilight Princess decompilation
project](https://github.com/zeldaret/tp).
