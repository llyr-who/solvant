#ifndef MATRIXDEF
#define MATRIXDEF
#include <cmath>
#include <iostream>
namespace solvant {
namespace base {
template <typename T, std::size_t R, std::size_t C>
class Matrix {
public:
    Matrix() {};
    virtual ~Matrix() {} ;
    virtual void solve() = 0;
    void print() {
        for(int i = 0; i < R; i++) {
            std::cout << '\n';
            for(int j = 0; j < C; j++) {
                std::cout << this->at({i,j}) << " ";
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
    }
    // safe-slow set/get
    virtual T at(std::array<int, 2> ij) = 0;
    virtual void set(std::array<int, 2> ij, const T val) = 0;
protected:
    // unsafe-fast sat/get
    virtual T at(const std::size_t i, std::size_t j) = 0;
    virtual void set(const std::size_t i, std::size_t j, const T val) = 0;
};
}  // namespace Base
}  // namespace SolvAnt
#endif
