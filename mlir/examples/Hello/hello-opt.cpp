#include "HelloDialect.h"
#include "HelloPasses.h"

#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"
#include "mlir/InitAllPasses.h"
#include "mlir/InitAllDialects.h"

using namespace mlir;

int main(int argc, char **argv) {
  DialectRegistry registry;

  // Register core dialects (so module/func/etc parse).
  registerAllDialects(registry);
  registry.insert<hello::HelloDialect>();

  // Register passes (for -hello-lower-to-func).
  PassRegistration<hello::createLowerHelloToFuncPass>();

  return failed(MlirOptMain(argc, argv, "hello-opt\n", registry));
}
