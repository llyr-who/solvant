#ifndef MATRIXDEF
#define MATRIXDEF
#include <cmath>
#include <iostream>
#include <memory>
namespace solvant {
namespace base {
template <typename T, std::size_t R, std::size_t C>
class matrix {
private:
	std::array<T, R*C> m_data;
public:
	matrix() {};
	virtual ~matrix() {};
    
    std::size_t rows() const { return R;}
    std::size_t cols() const { return C; }

    void print() {
        for (std::size_t i = 0; i < R; i++) {
            std::cout << '\n';
            for (std::size_t j = 0; j < C; j++) {
                std::cout << (*this)(i,j) << " ";
            }
            std::cout << '\n';
        }
        std::cout << std::endl;
    }

    // safety - when implementing, check bounds
    //virtual T at(const std::size_t i, const std::size_t j) = 0;
    //virtual void set(const std::size_t i, const std::size_t j, const T val) = 0;
    
    // no safety
    virtual T operator()(const std::size_t i, const std::size_t j) const {
    	return m_data[i*C + j];
    }
    virtual T& operator()(const std::size_t i, const std::size_t j) {
    	return m_data[i*C + j];
    }

    template<size_t K>
    matrix<T,R, K> operator*(const matrix<T, C, K>& rhs) const {
    	matrix<T,R,K> result;
    	for(int i = 0; i < R; i++) {
    		for(int j = 0; j < K;j++){
    			for(int k = 0; k < C; k++) {
    				result(i,j) += (*this)(i,k) * rhs(k,j);
    			}
    		}
    	}
    	return result;
    }

};
}  // namespace base
}  // namespace solvant
#endif
