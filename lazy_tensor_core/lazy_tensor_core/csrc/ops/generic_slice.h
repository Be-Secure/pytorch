#pragma once

#include "lazy_tensor_core/csrc/ts_backend/TsNode.h"

namespace torch_lazy_tensors {
namespace ir {
namespace ops {

class GenericSlice : public TsNode {
 public:
  GenericSlice(const torch::lazy::Value& input,
               c10::ArrayRef<int64_t> base_indices,
               c10::ArrayRef<int64_t> sizes);

  NodePtr Clone(OpList operands) const override;

  std::string ToString() const override;

  const std::vector<int64_t>& base_indices() const { return base_indices_; }

  const std::vector<int64_t>& sizes() const { return sizes_; }

 private:
  std::vector<int64_t> base_indices_;
  std::vector<int64_t> sizes_;
};

}  // namespace ops
}  // namespace ir
}  // namespace torch_lazy_tensors
