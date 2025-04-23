include "DemoDialect.td"
include "/Users/aldo/mlir-demo/llvm-project/mlir/include/mlir/IR/OpBase.td"
include "/Users/aldo/mlir-demo/llvm-project/mlir/include/mlir/Interfaces/SideEffectInterfaceBase.td"

def AddOp : Op<Demo_Dialect, "add", []> {
  let summary = "元素级加法操作";
  let description = [{
    将两个张量按元素相加。
    
    示例:
    ```mlir
    %2 = demo.add %0, %1 : tensor<2x2xf32>
    ```
  }];
  
  let arguments = (ins AnyTensor:$lhs, AnyTensor:$rhs);
  let results = (outs AnyTensor:$result);
}