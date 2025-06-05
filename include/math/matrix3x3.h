//
// Created by niek on 05/06/2025.
//

#ifndef MATRIX3X3_H
#define MATRIX3X3_H

#include "math/vec3.h"

namespace niekm::tmpl8::math {

    struct Matrix3x3 {
    private:
        float n[3][3];

    public:
        Matrix3x3() = default;

        Matrix3x3(float n00, float n01, float n02,
                float n10, float n11, float n12,
                float n20, float n21, float n22);

        Matrix3x3(const Vector3& a, const Vector3& b, const Vector3& c);

        float& operator()(int i, int j);

        Vector3& operator[](int j);
        const Vector3& operator[](int j) const;
    };

}

#endif //MATRIX3X3_H
