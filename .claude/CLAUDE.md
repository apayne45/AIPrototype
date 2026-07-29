# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project overview

An Unreal Engine 5.8 C++ project, originally generated from Epic's "Third Person Game Template" (see `Config/DefaultGame.ini` `ProjectName`). It is a prototyping playground for AI/gameplay experiments — the project name `AIPrototype` refers to gameplay AI (StateTree/behavior systems), not to Claude tooling.

There is no README in this repo.

## Guidance files

@build.md
@architecture.md
@branches.md
@guidance.md

`build.md` and `architecture.md` cover the shared template/codebase and change rarely. 
`guidance.md` provides rules in how to design and plan changes, while keeping language clear and concise
`branches.md` are the split point for feature-branch-specific work — when adding a new one (e.g. `mass.md` for `dev-austin-MASS`), see @branches.md for the pattern to follow so each branch's docs can evolve independently with fewer merge conflicts.
