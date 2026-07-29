## Build / compile

This is a standard UE5 C++ project — there is no separate package manager, linter, or test runner script. Compiling is done through Unreal's toolchain, not a CLI build command you'd normally invoke directly:

- Open `AIPrototype.sln` (or `AIPrototype.slnx`) in Visual Studio and build the `AIPrototypeEditor` target (Development Editor config) to get an editor you can run, or the `AIPrototype` target for a game-only build.
- Alternatively regenerate project files and build via UnrealBuildTool if the engine is installed locally, e.g.:
  `<EngineDir>\Build\BatchFiles\Build.bat AIPrototypeEditor Win64 Development -project="<repo>\AIPrototype.uproject"`
- There are two `.Target.cs` files in `Source/`: `AIPrototype.Target.cs` (Game) and `AIPrototypeEditor.Target.cs` (Editor). Module dependencies live in `Source/AIPrototype/AIPrototype.Build.cs`.
- `Automation_AIPrototype.sln` is not a project test suite — it's a solution referencing the engine's own `UnrealBuildTool`/`AutomationTool` C# projects (paths point at `../UnrealEngine/Engine/...`, a sibling engine checkout). Don't look here for project-specific tests.
- There are no automated tests, lint configs, or CI workflows in this repo (`.github/workflows` is empty).

After changing any `.h`/`.cpp` under `Source/`, the project must be rebuilt through Visual Studio/UBT for changes to take effect in the editor — hot reload from the running editor is unreliable for structural changes (new UCLASS/UPROPERTY, new files).

## Engine/tooling integration

- `.mcp.json` configures an `unreal-mcp` MCP server (`http://127.0.0.1:8000/mcp`) — this is the Unreal Engine MCP plugin, which lets Claude Code query/drive a **running Unreal Editor instance** directly (e.g. inspecting actors, calling editor tools). It requires the editor to be open with the MCP plugin's local server running; if it's not connected, tool calls will fail rather than falling back silently.
- The `.uproject` enables the `ModelContextProtocol`, `MCPClientToolset`, `Terminal`, and `AllToolsets` plugins specifically to support this Claude Code / Unreal MCP integration, alongside gameplay plugins (`GameplayAbilities`, `StateTree`, `GameplayStateTree`, `ModelingToolsEditorMode`).
