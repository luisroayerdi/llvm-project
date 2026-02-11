include "mlir/IR/OpBase.td"
include "Hello.td"

def Hello_PrintOp : Op<Hello_Dialect, "print", [HasParent<"FuncOp">]> {
  let summary = "Hello-world print operation";
  let description = [{
    A minimal hello op with no operands/results.
    We'll lower it into a func.call to @hello_print.
  }];

  let arguments = (ins);
  let results = (outs);

  let assemblyFormat = "attr-dict";
}
