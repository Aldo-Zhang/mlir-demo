#ifndef DEMO_OPS_H
#define DEMO_OPS_H

#include "/Users/aldo/mlir-demo/llvm-project/mlir/include/mlir/IR/BuiltinTypes.h"
#include "/Users/aldo/mlir-demo/llvm-project/mlir/include/mlir/IR/Dialect.h"
#include "/Users/aldo/mlir-demo/llvm-project/mlir/include/mlir/IR/OpDefinition.h"
#include "/Users/aldo/mlir-demo/llvm-project/mlir/include/mlir/Interfaces/SideEffectInterfaces.h"

#include "include/DemoDialect.h"

namespace demo {

// 在这里声明各种操作

// 包含从 TableGen 生成的类声明
#define GET_OP_CLASSES
#include "build/include/DemoOps.h.inc"

} // namespace demo

#endif // DEMO_OPS_H