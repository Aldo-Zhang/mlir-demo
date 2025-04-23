#include "../include/DemoOps.h"
#include "../include/DemoDialect.h"

#include "/Users/aldo/mlir-demo/llvm-project/mlir/include/mlir/IR/OpImplementation.h"
#include "/Users/aldo/mlir-demo/llvm-project/mlir/include/mlir/IR/Builders.h"

namespace demo {
    #define GET_OP_CLASSES
    #include "../build/include/DemoOps.cpp.inc"
} // namespace demo