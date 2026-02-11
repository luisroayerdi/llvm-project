add_mlir_library(MLIRHello
  ../HelloDialect.cpp
  ../HelloPasses.cpp

  LINK_LIBS PUBLIC
  MLIRIR
  MLIRFuncDialect
  MLIRPass
  MLIRTransforms
)

target_include_directories(MLIRHello PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/..
)

