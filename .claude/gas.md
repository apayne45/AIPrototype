## Gameplay Ability System (GAS) work-in-progress

Branch: `dev-austin-GAS`. `Source/AIPrototype/Dev_Austin/GAS/` is an in-progress, separate GAS integration, unrelated to the Combat variant's own hand-rolled damage system (see @.claude/architecture.md):

- `Actors/Characters/AbilitiesLabCharacter` — a character implementing `IAbilitySystemInterface`, owns a `ULabAbilitySystemComponent`.
- `Attributes/LabHealthAttributeSet` — `UAttributeSet` with `Health`/`MaxHealth`/`Damage`, replication via `OnRep_*`, and a `OnHealthChanged` BP-assignable delegate.
- `Components/LabAbilitySystemComponent` — currently an empty subclass of `UAbilitySystemComponent`, a placeholder for future customization.

Note this folder is **not** added to `PublicIncludePaths` in `AIPrototype.Build.cs` (unlike every `Variant_*` subfolder), so files here use full relative includes (`"Dev_Austin/GAS/..."`) rather than bare filenames — keep that convention when adding files under `Dev_Austin/`.

`Content/Dev/Austin/GAS/` is the matching Blueprint sandbox for this work. `Config/DefaultGame.ini` has `[/Script/GameplayAbilities.AbilitySystemGlobals]` configured for this system.
