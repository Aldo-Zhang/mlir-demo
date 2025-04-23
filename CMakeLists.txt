cmake_minimum_required(VERSION 3.13.4)
project(mlir-demo LANGUAGES CXX C)

# 查找 LLVM 和 MLIR
find_package(LLVM REQUIRED CONFIG)
find_package(MLIR REQUIRED CONFIG)

message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using MLIRConfig.cmake in: ${MLIR_DIR}")

set(LLVM_RUNTIME_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/bin)
set(LLVM_LIBRARY_OUTPUT_INTDIR ${CMAKE_BINARY_DIR}/lib)
set(MLIR_BINARY_DIR ${CMAKE_BINARY_DIR})

list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(TableGen)
include(AddLLVM)
include(AddMLIR)

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${MLIR_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR})

add_definitions(${LLVM_DEFINITIONS})
add_definitions(${MLIR_DEFINITIONS})

# 设置 TableGen 生成文件
set(LLVM_TARGET_DEFINITIONS include/DemoDialect.td)
mlir_tablegen(DemoDialect.h.inc -gen-dialect-decls)
mlir_tablegen(DemoDialect.cpp.inc -gen-dialect-defs)
add_public_tablegen_target(DemoDialectIncGen)

set(LLVM_TARGET_DEFINITIONS include/DemoOps.td)
mlir_tablegen(DemoOps.h.inc -gen-op-decls)
mlir_tablegen(DemoOps.cpp.inc -gen-op-defs)
add_public_tablegen_target(DemoOpsIncGen)

# 构建 Demo 方言库
add_mlir_dialect_library(MLIRDemo
  lib/DemoDialect.cpp
  lib/DemoOps.cpp

  DEPENDS
  DemoDialectIncGen
  DemoOpsIncGen

  LINK_LIBS PUBLIC
  MLIRIR
  MLIRInferTypeOpInterface
)

# 构建 demo-opt 工具
add_llvm_executable(demo-opt
  tools/demo-opt.cpp
)

target_link_libraries(demo-opt
  PRIVATE
  MLIRDemo
  MLIROptLib
)