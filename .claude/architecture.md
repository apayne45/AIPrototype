### Content organization notes

- `Content/Developers/<username>/` and `Content/Dev/<username>/` are personal sandbox areas (mirrors the git branch-per-developer pattern) — don't assume assets here are wired into any shipping level.
- `.uasset`/`.umap` and raw media (`.fbx`, `.png`, `.wav`, etc.) are tracked via Git LFS (see `.gitattributes`); expect binary diffs to be unreadable and avoid trying to inspect asset internals as text.
- `Content/__ExternalActors__/` and `Content/__ExternalObjects__/` are UE5's One File Per Actor (OFPA) data for levels — treat as generated/managed by the editor, not hand-edited.

### Feature branch work

Active feature work (GAS, Mass, Mover, etc.) lives under `Source/AIPrototype/Dev_<username>/` and `Content/Dev/<username>/`, kept separate from the shared variant code/content above. See @.claude/branches.md for which topic file documents which in-progress feature.
