#include "HelloPasses.h"
#include "HelloDialect.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Pass/Pass.h"

using namespace mlir;

namespace {
struct LowerHelloToFuncPass
    : public PassWrapper<LowerHelloToFuncPass, OperationPass<ModuleOp>> {
  MLIR_DEFINE_EXPLICIT_INTERNAL_INLINE_TYPE_ID(LowerHelloToFuncPass)

  StringRef getArgument() const final { return "hello-lower-to-func"; }
  StringRef getDescription() const final {
    return "Lower hello.print into func.call @hello_print";
  }

  void runOnOperation() override {
    ModuleOp module = getOperation();
    MLIRContext *ctx = module.getContext();

    // Ensure we have: func.func @hello_print()
    auto helloPrintSym = module.lookupSymbol<func::FuncOp>("hello_print");
    if (!helloPrintSym) {
      OpBuilder b(module.getBodyRegion());
      auto funcTy = b.getFunctionType(/*inputs=*/{}, /*results=*/{});
      helloPrintSym = b.create<func::FuncOp>(module.getLoc(), "hello_print", funcTy);
      helloPrintSym.setPrivate(); // keep it local for demo
    }

    // Rewrite hello.print -> func.call @hello_print()
    module.walk([&](Operation *op) {
      if (op->getName().getStringRef() != "hello.print")
        return;

      OpBuilder b(op);
      b.create<func::CallOp>(op->getLoc(), helloPrintSym, ValueRange{});
      op->erase();
    });
  }
};
} // namespace

namespace hello {
std::unique_ptr<mlir::Pass> createLowerHelloToFuncPass() {
  return std::make_unique<LowerHelloToFuncPass>();
}
} // namespace hello
