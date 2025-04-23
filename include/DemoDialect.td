#ifndef DEMO_DIALECT
#define DEMO_DIALECT

include "/Users/aldo/mlir-demo/llvm-project/mlir/include/mlir/IR/DialectBase.td"

def Demo_Dialect : Dialect {
    let name = "demo";
    let summary = " A minimal dialect for demo ops";
    let description = [{
        This dialect provides a demo.add operation for illustration.
    }];
    let cppNamespace = "demo";
}

#endif // DEMO_DIALECT