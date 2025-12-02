Build helper notes

This folder contains helper notes and a simple CMake file to help build any native helper binaries or to verify LibTorch detection. The recommended approach is to integrate LibTorch into the Unreal build via AI.Build.cs.

If you want to build a standalone trainer binary (optional), update the CMakeLists.txt LIBTORCH_ROOT variable to point to the downloaded LibTorch and run:
  mkdir build && cd build
  cmake .. -DCMAKE_PREFIX_PATH=/path/to/libtorch
  cmake --build . --config Release
