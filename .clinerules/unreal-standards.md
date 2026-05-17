# UE5 Technical Artist Rules (SpaceSurvivorII)

## 1. Environment & Tools
- **MCP Server:** Always use `vibeue` for Unreal Engine-specific tasks.
- **Code Reading:** Use local `read_file` for `Source/` directory. Use `vibeue__read_logs` ONLY for `.log` files.
- **Python:** Prepend `import unreal` to all `execute_python_code` calls.

## 2. VibeUE Syntax (Strict)
- **Asset Search:** Use `vibeue__manage_asset` with `action: "search"` and `search_term`.
- **Asset Verification:** Use `action: "find"` ONLY if you have a full `/Game/` path.
- **Discovery:** Use `action: "list"` with `path` to browse directories.

## 3. Project Map (Direct Access)
Refer to these paths instead of searching to save tokens:
- **Headers:** `Source/SpaceSurvivorII/Public/`
- **Private Logic:** `Source/SpaceSurvivorII/Private/`
- **UI Widgets (C++):** `Source/SpaceSurvivorII/Public/UI/Widgets/`
- **UI Assets (Blueprints):** `/Game/UI/` (Use `vibeue__manage_asset`)
- **Core Systems:** `Source/SpaceSurvivorII/Public/Core/`

## 4. Operational Guardrails
- **Path Persistence:** Once a file path is confirmed, do not re-verify or "correct" it unless a 404 error occurs.
- **No Confirmation Loops:** If a tool call succeeds, proceed to analysis. Do not repeat calls to "confirm" results.
- **Stop on Error:** If a path error repeats twice, STOP and ask the user for the absolute path.

## 5. Asset Creation & Python
- **Creation Strategy:** To create a Blueprint or Widget, use `execute_python_code`.
- **Boilerplate:** Always start UE Python scripts with:
  ```python
  import unreal
  asset_tools = unreal.AssetToolsHelpers.get_asset_tools()
  ```

## 6. Strict Tool Policy
- **NO SHELL:** NEVER use `execute_command` to interact with Unreal Engine or VibeUE.
- **MCP ONLY:** All engine interactions MUST use tools prefixed with `vibeue__`.
- **PYTHON ONLY:** To create assets (Blueprints, Widgets, Actors), use `vibeue__execute_python_code`.

## 7. Rendering, Physics & LWC
- **Substrate Materials:** All materials must adhere to Substrate's slab-based logic; avoid legacy "Standard" material shading pathways.
- **Nanite Foliage:** Use Nanite Skeletal Assemblies for vegetation to utilize 5.7+ dynamic wind and voxel-based shadow caching.
- **Spatial Precision (LWC):** Use `FVector` (64-bit double precision) for all location and orbital math to prevent jitter at vast distances.
- **Frame-Rate Independence:** All movement math must be multiplied by `DeltaTime`.
- **Math Library:** Favor `FMath` functions (e.g., VInterpTo) over standard C++ math for engine compatibility.



