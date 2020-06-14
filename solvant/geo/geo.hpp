#pragma once

#include "core/matrix.hpp"
#include "core/vector.hpp"

namespace solvant {
namespace geo {

matrix<float, 4, 4> view_model_matrix(const vector<float, 3>& pos,
                                  const vector<float, 3>& target,
                                  const vector<float, 3>& up) {
    // this vector points into the screen
    auto mz = pos - target;
    mz.normalize();

    // x axis is going to be perpendicular to both
    // the axis looking into the screen (mz) and up
    vector<float, 3> mx;
    solvant::cross_product3(up, mz, mx);
    mx.normalize();

    // at the moment mz,mx and up are not orthogonal.
    // floatherefore we just take the cross product
    // of mx and mz to get my!
    vector<float, 3> my;
    solvant::cross_product3(mz, mx, my);

    // we want the position in the new coordinate system.
    // and we need to "kick" back, so we can see the object
    vector<float, 3> t;
    t[0] = mx[0] * pos[0] + mx[1] * pos[1] + mx[2] * pos[2];
    t[1] = my[0] * pos[0] + my[1] * pos[1] + my[2] * pos[2];
    t[2] = -(mz[0] * pos[0] + mz[1] * pos[1] + mz[2] * pos[2]);

    // clang-format off
    matrix<float, 4, 4> m = {mx[0], my[0], mz[0], t[0], 
                             mx[1], my[1], mz[1], t[1],
                             mx[2], my[2], mz[2], t[2],
                              0.0f,  0.0f,  0.0f, 1.0f};
    // clang-format on
    return m;
}

matrix<float, 4, 4> proj_matrix(float FOVangle, float aspect, float nearz, float farz) {
    matrix<float, 4, 4> A;
    // plenty of explainations online.
    A(0, 0) = 1 / (aspect * tanf(FOVangle / 2));
    A(1, 1) = 1 / tanf(FOVangle / 2);
    A(2, 2) = (nearz + farz) / (farz - nearz);
    A(2, 3) = -2.0 * nearz * farz / (farz - nearz);
    A(3, 2) = -1.0;

    return A;
}

}  // namespace geo
}  // namespace solvant
