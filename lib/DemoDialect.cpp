#include "../include/DemoDialect.h"

using namespace mlir;
using namespace demo;

void DemoDialect::initialize() {
  // 注册通过 TableGen 定义的所有 Ops
  addOperations<
#define GET_OP_LIST
#include "../build/include/DemoOps.cpp.inc"
  >();

  // （可选）注册 Types、Attributes ……  
}