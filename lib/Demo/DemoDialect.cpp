#include "Demo/DemoDialect.h"
#include "Demo/DemoDialect.cpp.inc"

using namespace mlir;
using namespace mlir::demo;

void DemoDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "Demo/DemoOps.cpp.inc"
    >();
}