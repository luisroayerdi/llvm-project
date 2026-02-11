#include "HelloDialect.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/DialectImplementation.h"

#include "HelloOps.h.inc"

using namespace mlir;

namespace hello {
void HelloDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "HelloOps.cpp.inc"
      >();
}
} // namespace hello

#include "Hello.cpp.inc"
