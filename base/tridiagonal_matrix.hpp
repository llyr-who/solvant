#include "banded_matrix.hpp"

namespace solvant {
namespace base {
template<typename T, size_t sz>
using tridiagonal_matrix = banded_matrix<T, sz,3>;
}
}




