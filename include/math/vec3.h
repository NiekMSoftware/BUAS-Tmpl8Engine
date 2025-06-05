//
// Created by niek on 05/06/2025.
//

#ifndef VEC3_H
#define VEC3_H

namespace niekm::tmpl8::math {

    struct Vector3 {
        float x, y, z;

        Vector3() = default;
        Vector3(float nx, float ny, float nz);

        // operators
        float& operator[](int i);
        const float& operator[](int i) const;

        Vector3& operator *= (float s);
        Vector3& operator /= (float s);

        // methods
        float magnitude() const;
    };

    inline Vector3 operator *(const Vector3& v, const float s) {
        return { Vector3(v.x * s, v.y * s, v.z * s) };
    }

}

#endif //VEC3_H
