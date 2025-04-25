#ifndef DEMO_OPS_TD
#define DEMO_OPS_TD

include "mlir/IR/OpBase.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "mlir/Interfaces/SideEffectInterfaceBase.td"
include "mlir/Interfaces/FunctionInterfaces.td"
include "mlir/Interfaces/InferTypeOpInterface.td"

include "Demo/DemoDialect.td"

// A base class for defining ops more elegantly
class Demo_Op<string mnemonic, list<Trait> traits = []> :
    Op<Demo_Dialect, mnemonic, traits>;


//
// AddOp
//

def AddOp : Demo_Op<"add", [
  Pure
]> {
  let summary = "add";

  let description = [{
    Demo Add Operation.
  }];
  
  let arguments = (ins AnyTypeOf<[AnyMemRef, AnyTensor]>:$lhs, AnyTypeOf<[AnyMemRef, AnyTensor]>:$rhs);
  let results = (outs AnyTypeOf<[AnyMemRef, AnyTensor]>:$output);

  // assemblyFormat
  // hasFolder
  // Verifier
}

#endif // DEMO_OPS_TD
