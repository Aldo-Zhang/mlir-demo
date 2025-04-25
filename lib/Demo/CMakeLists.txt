add_mlir_dialect_library(MLIRDemo
  DemoDialect.cpp
  DemoOps.cpp

  DEPENDS
  DemoOpsIncGen
  DemoDialectIncGen

  LINK_COMPONENTS
  Core

  LINK_LIBS PUBLIC
  MLIRIR
)