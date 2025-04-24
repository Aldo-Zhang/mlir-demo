#ifndef DEMO_DIALECT_H
#define DEMO_DIALECT_H

#include <mlir/IR/BuiltinOps.h>
#include <mlir/IR/Dialect.h>
#include <mlir/Interfaces/FunctionInterfaces.h>
#include <mlir/Interfaces/InferTypeOpInterface.h>

#include "Demo/DemoDialect.h.inc"

#define GET_OP_CLASSES

// No need to set up a DemoOps.h
#include "Demo/DemoOps.h.inc"

#endif // DEMO_DIALECT_H 