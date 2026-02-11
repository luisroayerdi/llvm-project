include "mlir/IR/BuiltinDialect.td"

def Hello_Dialect : Dialect {
  let name = "hello";
  let cppNamespace = "hello";
}

