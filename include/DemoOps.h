#ifndef DEMO_OPS_H
#define DEMO_OPS_H

#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

#include "include/DemoDialect.h"

namespace demo {

// 在这里声明各种操作

// 包含从 TableGen 生成的类声明
#define GET_OP_CLASSES
#include "build/include/DemoOps.h.inc"

} // namespace demo

#endif // DEMO_OPS_H