# Unreal Engine 5.7.4 Global Development Rules

## 1. Build System & Tooling
- **The Build System:** Always use `UnrealBuildTool.exe` via the terminal. Avoid manual modifications to generated files.
- **Command Consistency:** Use the `Build.bat` script in the project root for consistency.
- **Iteration (Live Coding):** Use **Live Coding (Ctrl + Alt + F11)** for logic changes inside .cpp files. 
- **The Header (.h) Rule:** When making changes to .h files (macros, new variables, new functions), you MUST shut down the Editor and perform a full Clean and Build to ensure the Unreal Header Tool (UHT) stays in sync. **Hot Reload is deprecated and prohibited**.
- **Modules:** Properly define module dependencies in .Build.cs. Only include necessary modules to keep compile times low.

## 2. Naming Conventions & Directory Structure
- **Filenames:** MUST use PascalCase for all .h and .cpp files (e.g., SpaceShip.cpp).
- **Class Prefixes:** Use 'A' for Actors, 'U' for Components/Objects, 'F' for Structs, and 'I' for Interfaces.
- **Layout:** Always use a Public/Private split.
    - `Source/[Module]/Public/` -> All .h files.
    - `Source/[Module]/Private/` -> All .cpp files.
- **Organization:** Mirror sub-folders in both Public and Private directories.

## 3. Architecture & Blueprint Synergy
- **Hybrid Workflow:** Use C++ for core logic and performance; use Blueprints for visual tweaking and rapid iteration.
- **Communication:**
    - **One-to-Many:** Use `DECLARE_DYNAMIC_MULTICAST_DELEGATE` (Event Dispatchers).
    - **Cross-System:** Use Unreal Interfaces (UInterface) to define contracts (e.g., IDamageable).
- **Data-Driven:** NEVER hardcode gameplay values. Use `UDataAsset` or `UDataTable`.
- **Editor Exposure:** Use `UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpaceSim")` for variables that require tuning in the Inspector.
- **Forward Declarations:** Use `class UComponent;` in headers instead of `#include` where possible to minimize dependency webs.

## 4. Memory, Safety & Performance
- **Smart Pointers (Members):** Use `TObjectPtr<T>` for all persistent UObject member fields in headers.
- **Raw Pointers (Local):** Use raw pointers (`T*`) for local function variables, parameters, and return types where GC tracking is not required for scope.
- **Weak References:** Use `TWeakObjectPtr<T>` for references that shouldn't prevent an object from being destroyed.
- **Validation:** Always wrap pointer calls in `if (IsValid(PointerName))`.
- **Garbage Collection:** Ensure all UObject pointers in headers are marked with the `UPROPERTY()` macro to prevent premature deletion.
- **Tick Optimization:** Set `bCanEverTick = false` in constructors by default. Use Timers or Event-Driven logic instead of Tick() whenever possible.
- **Object Pooling:** Use for frequently spawned actors (projectiles/enemies) to avoid SpawnActor/DestroyActor overhead.

## 5. Rendering, Physics & LWC
- **Substrate Materials:** All materials must adhere to Substrate's slab-based logic; avoid legacy "Standard" material shading pathways.
- **Nanite Foliage:** Use Nanite Skeletal Assemblies for vegetation to utilize 5.7+ dynamic wind and voxel-based shadow caching.
- **Spatial Precision (LWC):** Use `FVector` (64-bit double precision) for all location and orbital math to prevent jitter at vast distances.
- **Frame-Rate Independence:** All movement math must be multiplied by `DeltaTime`.
- **Math Library:** Favor `FMath` functions (e.g., VInterpTo) over standard C++ math for engine compatibility.

## 6. Debugging & Logging
- **The Standard:** Use `UE_LOG` with a custom project category (e.g., LogSpaceSurvivor). 
- **Prohibited:** Do not use `GEngine->AddOnScreenDebugMessage` in permanent code.
- **Profiling:** Use Unreal Insights to identify bottlenecks before attempting optimization.