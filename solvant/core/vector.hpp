#pragma once

#include <array>
#include <cmath>
#include <iostream>
#include <numeric>
#include <type_traits>
#include <utility>

namespace solvant {
/**
 * vector class
 */
template <typename T, std::size_t N>
class vector {
private:
    // Initialises all elements to zero
    std::array<T, N> m_data = {};

public:
    constexpr vector() : m_data({}){};

    //! vector a = {1,2,3,...}
    template <
        typename... Ts,
        typename std::enable_if<std::conjunction<std::is_same<T, Ts>...>::value,
                                int>::type = 0>
    constexpr vector(Ts&&... elements) noexcept {
        static_assert(sizeof...(Ts) == N);
        m_data = std::array<T, N>{std::forward<Ts>(elements)...};
    }

    ~vector(){};

    std::size_t size() const { return N; }

    //! obtain raw row data
    T operator[](const std::size_t n) const { return m_data[n]; }
    T& operator[](const std::size_t n) { return m_data[n]; }

    T operator*(const vector& v) {
        return std::inner_product(m_data.begin(), m_data.end(),
                                  v.m_data.begin(), 0);
    }

    bool operator==(const vector<T, N>& v) const { return m_data == v.m_data; }
};

template <typename T, std::size_t N>
inline void print(const vector<T, N>& a) {
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << '\n';
}

template <typename T>
inline void cross3(const vector<T, 3>& a, const vector<T, 3>& b,
                   vector<T, 3>& c) {
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[2] * b[0];
}

}  // namespace solvant

