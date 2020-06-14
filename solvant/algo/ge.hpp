#pragma once
#include "core/matrix.hpp"
#include "core/vector.hpp"

#include <memory>

namespace solvant {

template <typename T, size_t N>
matrix<T, N, N> identity() {
    matrix<T, N, N> I;
    for (std::size_t i = 0; i < N; ++i) {
        I[i][i] = 1.0;
    }
    return I;
}

template <typename T, std::size_t N>
void pivot(solvant::matrix<T, N, N>& U, solvant::matrix<T, N, N>& P,
           const std::size_t& k) {
    std::size_t i = 0;
    T max = 0;
    for (std::size_t l = k; l < N; l++) {
        if (U(l, k) > max) {
            i = l;
            max = U(l, k);
        }
    }
    U.interchange_rows(i, k);
    P.interchange_rows(i, k);
}

template <typename T, std::size_t N>
void ge(const solvant::vector<T, N>& rhs, const solvant::matrix<T, N, N>& m,
        solvant::vector<T, N>& x) {
    auto U = m;
    auto L = identity<T, N>();
    auto P = identity<T, N>();
    for (std::size_t k = 0; k < N - 1; k++) {
        if (U(k, k) == 0) pivot(U, P, k);
        for (std::size_t j = k + 1; j < N; j++) {
            L(j, k) = U(j, k) / U(k, k);
            for (std::size_t s = k; s < N; s++) {
                U(j, s) = U(j, s) - L(j, k) * U(k, s);
            }
        }
    }

    auto bb = P * rhs;
    vector<T, N> y;

    // Call forward substitution (returns vector) to solve "Ly=bb"
    forward_substitute(bb, L, y);
    // Call backward substitution Ux = y
    backward_substitute(y, U, x);
}

template <typename T, std::size_t N>
void forward_substitute(const vector<T, N>& bb, const matrix<T, N, N>& L,
                        vector<T, N>& y) {
    y[0] = bb[0] / L(0, 0);
    for (std::size_t j = 1; j < N; j++) {
        T SUM = 0;
        for (std::size_t k = 0; k < j; k++) {
            SUM += y[k] * L(j, k);
        }
        y[j] = (bb[j] - SUM) / L(j, j);
    }
}

template <typename T, std::size_t N>
void backward_substitute(const vector<T, N>& y, const matrix<T, N, N>& U,
                         vector<T, N>& x) {
    x[N - 1] = y[N - 1] / U(N - 1, N - 1);
    // int -> size_t
    for (int j = N - 1; j > -1; j--) {
        T SUM = 0;
        for (std::size_t k = j + 1; k < N; k++) {
            SUM += x[k] * U(j, k);
        }
        x[j] = (y[j] - SUM) / U(j, j);
    }
}

}  // namespace solvant
