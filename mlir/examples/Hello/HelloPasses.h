#pragma once
#include "mlir/Pass/Pass.h"

namespace hello {
std::unique_ptr<mlir::Pass> createLowerHelloToFuncPass();
} // namespace hello

