cmake_minimum_required(VERSION 3.13.4)
project(mlir-demo LANGUAGES CXX C)
message(STATUS "PROJECT_NAME: " ${PROJECT_NAME})

# 设置 C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set install path
set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}")

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
include_directories(${PROJECT_SOURCE_DIR}/include) # include .td files and .h files
include_directories(${PROJECT_BINARY_DIR}/include) # include .inc files

add_definitions(${LLVM_DEFINITIONS})
add_definitions(${MLIR_DEFINITIONS})

# Add all targets depends on all-targets
add_custom_target(all-targets ALL)
add_custom_command(
    TARGET all-targets
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} --install .
    COMMENT "Install project ...")

# Add subdirectories for the trace of the target
add_subdirectory(include/Demo)
add_subdirectory(lib)

# # 设置 TableGen 生成文件
# set(LLVM_TARGET_DEFINITIONS include/DemoDialect.td)
# mlir_tablegen(DemoDialect.h.inc -gen-dialect-decls)
# mlir_tablegen(DemoDialect.cpp.inc -gen-dialect-defs)
# add_public_tablegen_target(DemoDialectIncGen)

# set(LLVM_TARGET_DEFINITIONS include/DemoOps.td)
# mlir_tablegen(DemoOps.h.inc -gen-op-decls)
# mlir_tablegen(DemoOps.cpp.inc -gen-op-defs)
# add_public_tablegen_target(DemoOpsIncGen)

# 构建 Demo 方言库
# add_mlir_dialect_library(MLIRDemo
#   lib/Demo/DemoDialect.cpp
#   lib/Demo/DemoOps.cpp

#   DEPENDS
#   DemoOpsIncGen

#   LINK_LIBS PUBLIC
#   MLIRIR
#   MLIRInferTypeOpInterface
# )

# 构建 demo-opt 工具
add_llvm_executable(demo-opt
  tools/demo-opt.cpp
)

target_link_libraries(demo-opt
  PRIVATE
  MLIRDemo
  MLIROptLib
)