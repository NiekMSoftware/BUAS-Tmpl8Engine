//
// Created by niek on 05/06/2025.
//

#include "math/matrix3x3.h"

namespace niekm::tmpl8::math {
    Matrix3x3::Matrix3x3(
        const float n00, const float n01, const float n02,
        const float n10, const float n11, const float n12,
        const float n20, const float n21, const float n22) {
        n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
        n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
        n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
    }

    Matrix3x3::Matrix3x3(const Vector3 &a, const Vector3 &b, const Vector3 &c) {
        n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
        n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
        n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
    }

    float& Matrix3x3::operator()(const int i, const int j) {
        return n[j][i];
    }

    Vector3 & Matrix3x3::operator[](const int j) {
        return *reinterpret_cast<Vector3 *>(&n[j]);
    }

    const Vector3 & Matrix3x3::operator[](const int j) const {
        return *reinterpret_cast<const Vector3 *>(&n[j]);
    }
}
