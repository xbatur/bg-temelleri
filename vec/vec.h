#ifndef VEC_H
#define VEC_H
#include <iostream>
template<typename T>
class Vec3
{
public:
    //Ctors
    Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
    Vec3(const T& xx) : x(xx), y(xx), z(xx) {}
    Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
    //Operator overloading
    Vec3<T> operator + (const Vec3<T>& v) const
    {
        return Vec3<T>(x + v.x, y + v.y, z + v.z);
    }
    Vec3<T> operator - (const Vec3<T>& v) const
    {
        return Vec3<T>(x - v.x, y - v.y, z - v.z);
    }
    Vec3<T> operator * (const T& r) const
    {
        return Vec3<T>(x * r, y * r, z * r);
    }
    //Functions
    T length();
    Vec3<T>& normalize();
    T dot(const Vec3<T>& a, const Vec3<T>& b);
    T angle(const Vec3<T>& a, const Vec3<T>& b);
    Vec3<T> cross(const Vec3<T>& v);
    //Variables
    T x, y, z;
};

typedef Vec3<float> Vec3f;

//Functions

//Get vector length.
template<typename T>
T Vec3<T>::length() {
    return sqrt(x * x + y * y + z * z);
}

//For non class object caller.
template<typename T>
T vecLength(const Vec3<T>& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
//End vector length.

//Vector normalization, get unit vector.
template<typename T>
Vec3<T>& Vec3<T>::normalize() {
    T len = length();
    if (len > 0) {
        T invertLen = 1 / len;
        x *= invertLen, y *= invertLen, z *= invertLen;
    }
    return *this;
}
//For non class object caller.
template<typename T>
Vec3<T>& vecNormalize(Vec3<T> &v) {
    T len = v.x * v.x + v.y * v.y + v.z * v.z;
    if (len > 0) {
        T invertLen = 1 / sqrt(len);
        x *= invertLen, y *= invertLen, z *= invertLen;
    }
    return *this;
}
// End vector normalization

//Dot Product
template <typename T>
T Vec3<T>::dot(const Vec3<T>& a, const Vec3<T>& b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

//For non class object caller.
template <typename T>
T vecDot(const Vec3<T>& a, const Vec3<T>& b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

//Get cosine angle between them
template <typename T>
T Vec3<T>::angle(const Vec3<T>& a, const Vec3<T>& b) {
    vecDot(&a, &b) / a.length() * b.length();
}

//For non class object caller.
template <typename T>
T vecAngle(const Vec3<T>& a, const Vec3<T>& b) {
    vecDot(&a, &b) / a.length() * b.length();
}

//End Dot Product

//Cross Product.
template <typename T>
Vec3<T> Vec3<T>::cross(const Vec3<T>& v) {
    return Vec3<T>(
        y * v.z - z * v.y,
        z * v.x - x * v.z,
        x * v.y - y * v.x
        );
}

//For non class object caller.
template <typename T>
Vec3<T> vecCross(const Vec3<T>& a, const Vec3<T>& b) {
    return Vec3<T>(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
        );
}
//End Cross Product
#endif
