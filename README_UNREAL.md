Unreal C++ RL Scaffold

This branch (feature/cpp-3d-rl) contains a source-only scaffold for an Unreal Engine 5 C++ project that integrates an in-C++ reinforcement learning trainer using LibTorch. This is a minimal starting point; it does not include binary assets or a full Unreal project.

Prerequisites
- Unreal Engine 5.3+ installed.
- Visual Studio 2026 with C++ toolset installed.
- LibTorch prebuilt binaries matching your compiler/OS (download from https://pytorch.org).

Quick start
1) Clone the repo and checkout the branch:
   git clone https://github.com/adampr0gram/AI.git
   cd AI
   git checkout feature/cpp-3d-rl

2) Copy this Source/ folder into a minimal Unreal project or create a new UE C++ project and replace its Source/ module with the Source/AI module present here.

3) Configure LibTorch:
- Download the correct LibTorch for your platform and Visual Studio toolchain.
- Update Build/LibTorchPath.txt with the absolute path to the LibTorch root (or set Libtorch environment variables).
- The AI.Build.cs contains placeholders for including LibTorch; adjust if necessary.

4) Open the Unreal project (.uproject) in the Editor and build the project in Visual Studio 2026.

Notes
- The RLTrainer is a minimal stub that uses LibTorch. Training/inference code is provided as illustrative examples and will require tuning and further integration.
- The Agent is a physics-enabled cube actor that receives actions (forces) and reports simple observations (position/velocity).
- The NarratorCamera is a free-fly pawn (WASD + mouse) that you can possess to move around the scene while training or running the agent.

See README_UNREAL.md and Build/README.md for more detailed setup instructions.
