#ifndef STAN_LANG_AST_NODE_CHOLESKY_FACTOR_BLOCK_VAR_DECL_DEF_HPP
#define STAN_LANG_AST_NODE_CHOLESKY_FACTOR_BLOCK_VAR_DECL_DEF_HPP

#include <stan/lang/ast.hpp>
#include <string>

namespace stan {
  namespace lang {

    cholesky_factor_block_var_decl::cholesky_factor_block_var_decl() { }


    cholesky_factor_block_var_decl::cholesky_factor_block_var_decl(
                                    const std::string& name,
                                    const expression& M,
                                    const expression& N)
      : var_decl(name, bare_expr_type(matrix_type())),
        type_(cholesky_factor_block_type(M, N)) { }

    cholesky_factor_block_var_decl::cholesky_factor_block_var_decl(
                                    const std::string& name,
                                    const expression& M,
                                    const expression& N,
                                    const expression& def)
      : var_decl(name, bare_expr_type(matrix_type()), def),
        type_(cholesky_factor_block_type(M, N)) { }
  }
}
#endif