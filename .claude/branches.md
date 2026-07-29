## Branches

Active development happens on personal branches per feature area, merging up through `development` into `main`:

- `dev-austin` — general dev-austin work
- `dev-austin-GAS` — Gameplay Ability System integration (no topic file yet - add '.claude/gas.md' and link it here when this branch has enough shape to document)
- `dev-austin-MASS` — Mass Entity/crowd work (no topic file yet — add `.claude/mass.md` and link it here when this branch has enough shape to document)
- `dev-austin-MOVER` — Mover component migration (no topic file yet — add `.claude/mover.md` and link it here when this branch has enough shape to document)
- `dev-ryan` — general dev-ryan work

When adding a new per-branch topic file, follow the pattern of specifying branch name, source/content folder locations, and any Build.cs/include-path quirks for the claude md file. Once completed, add an import for it in @.claude/CLAUDE.md, plus an entry in this list.
