# Antigravity: AI-Driven UI Architecture Showcase

**Developer:** Christopher J. Jepson  
**Role Focus:** Technical Artist / DevSecOps Engineer  

## 🚀 Project Overview

This repository serves as a technical proof-of-concept demonstrating advanced **"Vibe Coding"** and automated pipeline integration within Unreal Engine 5. It showcases the ability to architect, develop, and deploy comprehensive gameplay features—specifically a hybrid C++/Blueprint User Interface—entirely through natural language prompting and automated agentic execution. 

The codebase and visual assets in this repository were generated without direct manual coding, requiring only architectural direction, rigorous code review, and unit testing to ensure AAA-standard compliance.

## 🛠️ Technology Stack & Pipeline

* **Game Engine:** Unreal Engine 5.7.4
* **AI Orchestration:** Google Antigravity IDE & Gemini Pro 3.0
* **Editor Integration:** VibeUE (Model Context Protocol Server)
* **Languages:** C++, Python (via VibeUE Automation), Blueprint Visual Scripting

## ⚙️ Key Technical Achievements

### 1. Zero-Touch Hybrid Architecture
Demonstrates a strict **Architecture of Authority** where C++ handles core performance and state logic, while Blueprints handle visual representation. The AI pipeline successfully generated the foundational C++ classes (e.g., `MainMenuWidget`) and automatically bound them to the visual UMG Blueprints using `UPROPERTY(meta = (BindWidget))` macros.

### 2. Programmatic Blueprint Assembly
Utilizing the VibeUE MCP bridge, the AI agent executed Python scripts directly within the Unreal Editor to:
* Instantiate UserWidget Blueprints.
* Construct UI hierarchies (Canvas Panels, Vertical Boxes, Buttons).
* Programmatically wire Event Graph logic (e.g., binding `OnClicked` events to native `QuitGame` and `LevelTravel` execution nodes).

### 3. Strict Standard Adherence
The generated code was forced to comply with a highly rigid `rules.md` framework, ensuring:
* **Memory Safety:** Implementation of `TObjectPtr<T>` and strict garbage collection validation.
* **Modern UE5 Standards:** Compatibility with Large World Coordinates (LWC) utilizing 64-bit precision (`FVector`) and Substrate material logic.
* **Naming Conventions:** Flawless execution of PascalCase file structuring and standard Unreal prefixes (`U`, `A`, `F`).

## 🔍 The Developer's Role: Architect & Reviewer

While the AI performed the manual keystrokes, the actual engineering required deep technical oversight. Drawing on a rigorous foundation in Information Technology and DevSecOps best practices, my role in this pipeline involved:

1.  **System Prompt Engineering:** Designing atomic, highly specific prompts that act as compiler instructions for the LLM.
2.  **Environment Configuration:** Establishing the local HTTP Streamable transport bridge between the Antigravity IDE and the Unreal Editor instance.
3.  **Code Review & Validation:** Auditing the generated C++ for memory leaks, pointer safety, and modularity before allowing Live Coding compilation.
4.  **Version Control Management:** Implementing highly optimized `.gitignore` configurations to prevent repository bloat from AI workspace files, `.rsp` temporary data, and heavy uncompiled UE5 assets.

## 📈 Implications for Technical Art & DevSecOps

This project proves that the barrier between technical logic and visual artistry is shrinking. By leveraging AI as a "mechanical engineer" for the Unreal Engine, a Technical Artist can drastically reduce iteration times on UI/UX, shader compilation, and boilerplate C++ generation. This workflow shifts the developer's focus from manual implementation to high-level architectural design, code security, and pipeline optimization.
