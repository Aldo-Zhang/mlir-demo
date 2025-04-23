#include "../include/DemoDialect.h"
#include "../include/DemoOps.h"

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
  mlir::registerAllPasses();
  
  // 注册我们的方言
  mlir::DialectRegistry registry;
  registry.insert<mlir::StandardOpsDialect>();
  registry.insert<demo::DemoDialect>();
  
  // 其他需要的方言
  // registry.insert<mlir::arith::ArithDialect>();
  // registry.insert<mlir::func::FuncDialect>();
  
  return mlir::asMainReturnCode(
    mlir::MlirOptMain(argc, argv, "Demo dialect MLIR optimizer driver\n", registry));
} 