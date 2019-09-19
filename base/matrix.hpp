#ifndef MATRIXDEF
#define MATRIXDEF
#include <cmath>
#include <iostream>
namespace solvant {
namespace base {
template <typename T, std::size_t R, std::size_t C>
class Matrix {
public:
    
    std::size_t rows() const { return R;}
    std::size_t cols() const { return C; }

    void print() {
        for (std::size_t i = 0; i < R; i++) {
            std::cout << '\n';
            for (std::size_t j = 0; j < C; j++) {
                std::cout << this->at(i,j) << " ";
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
    }

    // safety
    virtual T at(const std::size_t i, const std::size_t j) = 0;
    virtual void set(const std::size_t i, const std::size_t j, const T val) = 0;
    
    // no safety
    virtual T operator()(const std::size_t i, const std::size_t j) const = 0;
    virtual T& operator()(const std::size_t i, const std::size_t j) = 0;

};
}  // namespace base
}  // namespace solvant
#endif
