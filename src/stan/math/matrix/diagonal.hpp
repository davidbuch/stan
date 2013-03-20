#ifndef __STAN__MATH__MATRIX__DIAGONAL_HPP__
#define __STAN__MATH__MATRIX__DIAGONAL_HPP__

#include <stan/math/matrix.hpp>

namespace stan {
  namespace math {

    /**
     * Return a column vector of the diagonal elements of the
     * specified matrix.  The matrix is not required to be square.
     * @param m Specified matrix.  
     * @return Diagonal of the matrix.
     */
    template <typename T>
    inline
    Eigen::Matrix<T,Eigen::Dynamic,1>
    diagonal(const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>& m) {
      return m.diagonal();
    }

  }
}
#endif
