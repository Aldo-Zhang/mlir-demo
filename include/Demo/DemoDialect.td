#ifndef DEMO_DIALECT_TD
#define DEMO_DIALECT_TD

include "mlir/IR/DialectBase.td"

def Demo_Dialect : Dialect {
    let name = "demo";
    let summary = " A minimal dialect for demo ops";
    let description = [{
        This dialect provides a demo.add operation for illustration.
    }];

    // Use the absolute namespace mlir::demo
    let cppNamespace = "::mlir::demo";
}

#endif // DEMO_DIALECT_TD