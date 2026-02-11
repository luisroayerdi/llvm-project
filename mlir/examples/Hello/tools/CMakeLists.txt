add_mlir_tool(hello-opt
  ../hello-opt.cpp
)

# Add include dir for TableGen-generated headers (Hello.h.inc, HelloOps.h.inc, etc.)
target_include_directories(hello-opt PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/..
)

target_link_libraries(hello-opt
  PRIVATE
  MLIRHello
  MLIROptLib
)

