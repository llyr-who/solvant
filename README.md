# solvant [![Codacy Badge](https://api.codacy.com/project/badge/Grade/d33593faf7ee4367a5fc0909531dfb31)](https://app.codacy.com/manual/llyr-who/solvant?utm_source=github.com&utm_medium=referral&utm_content=llyr-who/solvant&utm_campaign=Badge_Grade_Dashboard)

To build

`cmake -H. -Bbuild && make -C build`

To test

`cd build && make test`

To generate documentation, make sure doxygen is installed. More specifically the packages, `doxygen`, `doxygen-gui` and
`graph-viz`.

Once these packages are installed you can run

`cd build && make docs && google-chrome docs/html/index.html`


Basic usage would be as follows

```cpp
// After importing using cmake (fetch_content etc)
#include "solvant/core/matrix.hpp"

int main() {
    using matrix3x3 = solvant::matrix<float, 2, 2>;
    
    matrix3x3 A = {1,2,3,4};
    matrix3x3 B = ...;
    matrix3x3 C; // answer;
    
    solvant::matrix_prod(A, B, C);
}

```

For a full list of features see the docs.
