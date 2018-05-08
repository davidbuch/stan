#ifndef STAN_LANG_AST_BLOCK_ARRAY_TYPE_DEF_HPP
#define STAN_LANG_AST_BLOCK_ARRAY_TYPE_DEF_HPP

#include <stan/lang/ast.hpp>
#include <vector>

namespace stan {
namespace lang {

block_array_type::block_array_type()
    : element_type_(ill_formed_type()), array_len_(nil()) {}

block_array_type::block_array_type(const block_var_type& el_type,
                                   const expression& len)
    : element_type_(el_type), array_len_(len) {}

block_array_type::block_array_type(const block_var_type& el_type,
                                   const std::vector<expression>& lens) {
  if (lens.size() == 1) {
    element_type_ = el_type;
    array_len_ = lens[0];
  } else {
    block_array_type tmp(el_type, lens[lens.size() - 1]);
    for (size_t i = lens.size() - 2; i > 0; --i) {
      tmp = block_array_type(tmp, lens[i]);
    }
    element_type_ = tmp;
    array_len_ = lens[0];
  }
}

int block_array_type::dims() const {
  int total = 1;
  block_var_type cur_type(element_type_);
  while (cur_type.is_array_type()) {
    total += 1;
    cur_type = cur_type.array_element_type();
  }
  return total;
}

block_var_type block_array_type::contains() const {
  block_var_type cur_type(element_type_);
  while (cur_type.is_array_type()) {
    cur_type = cur_type.array_element_type();
  }
  return cur_type;
}

block_var_type block_array_type::element_type() const { return element_type_; }

expression block_array_type::array_len() const { return array_len_; }

std::vector<expression> block_array_type::array_lens() const {
  std::vector<expression> result;
  result.push_back(array_len_);
  block_var_type cur_type(element_type_);
  while (cur_type.is_array_type()) {
    result.push_back(cur_type.array_len());
    cur_type = cur_type.array_element_type();
  }
  return result;
}
}  // namespace lang
}  // namespace stan
#endif