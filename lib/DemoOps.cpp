#include "../include/DemoOps.h"
#include "../include/DemoDialect.h"

#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/Builders.h"

namespace demo {
    #define GET_OP_CLASSES
    #include "../build/include/DemoOps.cpp.inc"
} // namespace demo