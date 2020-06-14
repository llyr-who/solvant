#pragma once
#include "core/matrix.hpp"
#include "core/vector.hpp"

namespace solvant {
namespace geo {

using T = float;

matrix<T, 4, 4> formViewModelMatrix(const vector<T, 4>& pos,
                                    const vector<T, 4>& target,
                                    const vector<T, 4>& up) {
    vector<T, 4> mz;
    mz[0] = pos[0] - target[0];
    mz[1] = pos[1] - target[1];
    mz[2] = pos[2] - target[2];
    mz[3] = 0.0f;
    mz.normalize();

    vector<T, 4> my;
    my[0] = up[0];
    my[1] = up[1];
    my[2] = up[2];
    my[3] = 0.0f;

    vector<T, 4> mx;
    mx[0] = my[1] * mz[2] - my[2] * mz[1];
    mx[1] = my[2] * mz[0] - my[0] * mz[2];
    mx[2] = my[0] * mz[1] - my[1] * mz[0];
    mx[3] = 0.0f;
    mx.normalize();

    my[0] = mz[1] * mx[2] - mz[2] * mx[1];
    my[1] = mz[2] * mx[0] - mz[0] * mx[2];
    my[2] = mz[0] * mx[1] - mz[1] * mx[0];
    my[3] = 0.0f;

    vector<T, 4> t;
    t[0] = mx[0] * pos[0] + mx[1] * pos[1] + mx[2] * pos[2];
    t[1] = my[0] * pos[0] + my[1] * pos[1] + my[2] * pos[2];
    t[2] = -(mz[0] * pos[0] + mz[1] * pos[1] + mz[2] * pos[2]);

    AV4X4FLOAT m;
    m[0] = mx[0];
    m[1] = my[0];
    m[2] = mz[0];
    m[3] = 0.0f;
    m[4] = mx[1];
    m[5] = my[1];
    m[6] = mz[1];
    m[7] = 0.0f;
    m[8] = mx[2];
    m[9] = my[2];
    m[10] = mz[2];
    m[11] = 0.0f;
    m[12] = t[0];
    m[13] = t[1];
    m[14] = t[2];
    m[15] = 1.0f;

    return m;
}

AV4X4FLOAT formProjMatrix(float FOVangle, float aspect, float nearz,
                          float farz) {
    AV4X4FLOAT A;

    A[0] = 1 / (aspect * tanf(FOVangle / 2));
    A[5] = 1 / tanf(FOVangle / 2);
    A[10] = (nearz + farz) / (farz - nearz);
    A[11] = -2.0 * nearz * farz / (farz - nearz);
    A[14] = -1.0;

    return A;
}
}  // namespace geo
}  // namespace solvant
