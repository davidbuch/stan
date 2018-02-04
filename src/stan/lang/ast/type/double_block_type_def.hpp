#ifndef STAN_LANG_AST_DOUBLE_BLOCK_TYPE_DEF_HPP
#define STAN_LANG_AST_DOUBLE_BLOCK_TYPE_DEF_HPP

#include <stan/lang/ast.hpp>

namespace stan {
  namespace lang {
    double_block_type::double_block_type()
      : bounds_(nil(), nil()) { }

    double_block_type::double_block_type(const range& bounds)
      : bounds_(bounds) { }

    range double_block_type::bounds() const { return bounds_; }
  }
}
#endif
