# mlir-demo

This project is intend to 
# MLIR Demo

This project is intended to demonstrate the core concepts of building and running custom MLIR (Multi-Level Intermediate Representation) dialects and passes. Through this demo, you will learn how to create a simple MLIR dialect, implement a transformation pass, and integrate with the MLIR toolchain.

## Overview

`mlir-demo` provides:
- A minimal custom dialect (`DemoDialect`) with a sample operation (`demo.add`).
- A transformation pass that optimizes `demo.add` operations.
- CMake-based build scripts to compile and run the demo.
- GitHub Actions workflow for automatic build and test.

## Features

1. **Custom Dialect**: Defines a new MLIR dialect with custom operations.
2. **Transformation Pass**: Implements a pass that transforms or optimizes dialect operations.
3. **Example Frontend**: Includes a small driver to parse and execute MLIR files.
4. **CI Integration**: Continuous integration using GitHub Actions to ensure reproducibility.

## Prerequisites

- **LLVM/MLIR** (version 15.0 or higher)
- **CMake** (version 3.13 or higher)
- **Ninja** (optional, recommended)
- A C++17-compatible compiler (e.g., GCC 9+, Clang 10+)

## Installation

1. **Clone the repository**

   ```bash
   git clone https://github.com/aldozhang/mlir-demo.git
   cd mlir-demo
   ```

2. **Create a build directory and generate**

   ```bash
   mkdir build && cd build
   cmake -G Ninja -DMLIR_DIR=/path/to/mlir/lib/cmake/mlir ..
   ```

3. **Build the project**

   ```bash
   ninja
   ```

## Usage

- **Run the sample dialect example**

  ```bash
  cd build
  ./demo-opt ../examples/demo_add.mlir
  ```

- **Apply the custom pass**

  ```bash
  ./demo-opt -demo-opt ../examples/demo_add.mlir -o optimized_add.mlir
  ```

- **View help**

  ```bash
  ./demo-opt --help
  ```

## Project Structure

```
mlir-demo/
├── CMakeLists.txt        # Build configuration
├── examples/             # Sample MLIR files
│   └── demo_add.mlir
├── include/              # C++ header files for the dialect and pass
├── lib/                  # Implementation of dialect and pass
└── tools/                # Demo driver executable
```

## Roadmap

- Add support for additional sample operations (e.g., `demo.mul`, `demo.div`)
- Implement more advanced optimization passes
- Integrate with Python bindings
- Extend CI to deploy documentation on GitHub Pages

## License

This project is licensed under the MIT License.
