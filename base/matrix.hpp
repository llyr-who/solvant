#ifndef MATRIXDEF
#define MATRIXDEF
#include <cmath>
#include <iostream>
namespace solvant {
namespace base {
template <typename T, std::size_t R, std::size_t C>
class Matrix {
public:
    virtual void solve() = 0;
    void print() {
        for (std::size_t i = 0; i < R; i++) {
            std::cout << '\n';
            for (std::size_t j = 0; j < C; j++) {
                std::cout << this->at({i, j}) << " ";
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
    }

    std::array<std::size_t, 2> size() {
        return {R,C};
    }

    // safe-slow set/get
    virtual T at(std::array<std::size_t, 2> ij) = 0;
    virtual void set(std::array<std::size_t, 2> ij, const T val) = 0;

    // unsafe-fast sat/get
    virtual T fst_at(const std::size_t i, std::size_t j) = 0;
    virtual void fst_set(const std::size_t i, std::size_t j, const T val) = 0;
};
}  // namespace base
}  // namespace solvant
#endif
