//
// Created by niek on 05/06/2025.
//

#include "math/vec3.h"

#include <math.h>

namespace niekm::tmpl8::math {

    Vector3::Vector3(const float nx, const float ny, const float nz) {
        x = nx;
        y = ny;
        z = nz;
    }

    float & Vector3::operator[](const int i) {
        return { (&x) [i] };
    }

    const float & Vector3::operator[](const int i) const {
        return { (&x) [i] };
    }

    Vector3 & Vector3::operator*=(const float s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vector3 & Vector3::operator/=(float s) {
        s = 1.f / s;
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vector3 & Vector3::operator+=(const Vector3 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3 & Vector3::operator-=(const Vector3 &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

}
