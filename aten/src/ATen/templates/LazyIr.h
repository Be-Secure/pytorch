#pragma once

// This file contains autogenerated LazyTensor IR nodes
${lazy_ir_sysinc}

${lazy_ir_inc}

${external_backend_headers}

namespace torch_lazy_tensors {
namespace ir {

static lazy_tensors::Shape convertShape(
    const std::vector<at::ScalarType>& dtypes,
    const std::vector<std::vector<int64_t>>& shapes) {
  CHECK_EQ(dtypes.size(), shapes.size());
  if (dtypes.size() == 1) {
    return lazy_tensors::Shape(dtypes[0], shapes[0]);
  }

  std::vector<lazy_tensors::Shape> shape;
  for (int i = 0; i < dtypes.size(); i++) {
    shape.emplace_back(dtypes[i], shapes[i]);
  }

  // Since we are going to remove lazy_tensors::Shape very soon, this
  // copy-by-value is not worth fixing.
  return lazy_tensors::Shape(shape);
}

namespace ops {

// kNullValue is used to contribute a static hash value any time
// a node has an Optional<Value> input that is nullopt.  It is important
// to differentiate between HASH(nullopt, something) and HASH(something, nullopt),
// and using kNullValue in the hash function in the order of arguments
// serves this purpose.
static const torch::lazy::Value kNullValue = torch::lazy::Value();

${ir_declarations}

} // namespace ops
} // namespace ir
} // namespace torch_lazy_tensors
