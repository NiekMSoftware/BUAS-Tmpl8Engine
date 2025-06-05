//
// Created by niek on 05/06/2025.
//

#ifndef VEC3_H
#define VEC3_H

#include <math.h>

namespace niekm::tmpl8::math {

    struct Vector3 {
        float x, y, z;

        Vector3() = default;
        Vector3(float nx, float ny, float nz);

        // operators
        float& operator[](int i);
        const float& operator[](int i) const;

        Vector3& operator*=(float s);
        Vector3& operator/=(float s);

        Vector3& operator+=(const Vector3& v);
        Vector3& operator-=(const Vector3& v);
    };

    inline Vector3 operator*(const Vector3& v, const float s) {
        return { Vector3(v.x * s, v.y * s, v.z * s) };
    }

    inline Vector3 operator/(const Vector3& v, float s) {
        s = 1.0f / s;
        return { Vector3(v.x / s, v.y / s, v.z / s) };
    }

    inline Vector3 operator-(const Vector3& v) {
        return { Vector3(-v.x, -v.y, -v.z) };
    }

    inline Vector3 operator-(const Vector3& a, const Vector3& b) {
        return { Vector3(a.x - b.x, a.y - b.y, a.z - b.z) };
    }

    inline Vector3 operator+(const Vector3& a, const Vector3& b) {
        return { Vector3(a.x + b.x, a.y + b.y, a.z + b.z) };
    }

    inline float magnitude(const Vector3& v) {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    inline Vector3 normalize(const Vector3& v) {
        return v / magnitude(v);
    }

}

#endif //VEC3_H
