#include "Demo/DemoDialect.h"
#include "Demo/DemoOps.h"

#include "mlir/IR/Dialect.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Pass/PassManager.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"

int main(int argc, char **argv) {
  // mlir::registerAllPasses();
  
  // 注册我们的方言 - 修复注册代码
  mlir::DialectRegistry registry;

  mlir::MLIRContext context(registry);
  
  // StandardOpsDialect 在新版 MLIR 中已被弃用，使用其他核心方言
  registry.insert<mlir::demo::DemoDialect>();
  
  return mlir::asMainReturnCode(
    mlir::MlirOptMain(argc, argv, "Demo dialect MLIR optimizer driver\n", registry));
} 