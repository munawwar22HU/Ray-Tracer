#include <cmath>
#include <sstream>
#include "Vector3D.hpp"

// set vector to (0, 0, 0).
Vector3D::Vector3D()  : x{0}, y{0}, z{0} {}
// set vector to (c, c, c).
Vector3D::Vector3D(double c) :  x{c}, y{c}, z{c} {}
// set vector to (_x, _y, _z)
Vector3D::Vector3D(double _x, double _y, double _z) :  x{_x}, y{_y}, z{_z} {}
// construct from a point.
Vector3D::Vector3D(const Point3D &p) :  x{p.x}, y{p.y}, z{p.z} {}
// Assigment Operator
Vector3D& Vector3D::operator=(const Point3D& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return (*this);
}
// String representation
std::string Vector3D::to_string() const {
    std::stringstream ss;
    ss << "<" << x << "," << y << "," << z << ">";
    return ss.str();
}
// unary minus
Vector3D Vector3D::operator-() const {
    return Vector3D(-x, -y, -z);
}
// addition
Vector3D Vector3D::operator+(const Vector3D &v) const {
    return Vector3D(x+v.x, y+v.y, z+v.z);
}
// subtraction
Vector3D Vector3D::operator-(const Vector3D &v) const {
    return Vector3D(x-v.x, y-v.y, z-v.z);
}
// compound addition
Vector3D& Vector3D::operator+=(const Vector3D &v) {
    x+=v.x;
    y+=v.y;
    z+=v.z;
    return (*this);
}
// compound subtraction
Vector3D& Vector3D::operator-=(const Vector3D &v) {
    x-= v.x;
    y-= v.y;
    z-= v.z;
    return (*this);
}
// Scaling
Vector3D Vector3D::operator*(const double a) const {
    return Vector3D(x*a, y*a, z*a);
}
Vector3D Vector3D::operator/(const double a) const {
    return this->operator*(1/a);
}
// Length
double Vector3D::len_squared() const {
    return pow(x, 2) + pow(y, 2) + pow(z, 2);
}
double Vector3D::length() const {
    return sqrt(this->len_squared());
}
void Vector3D::normalize()  {
    double l = this -> length();
    x /= l;
    y /= l;
    z /= l;
}
// Vector Products
double Vector3D::operator*(const Vector3D&b) const {
    return x*b.x + y*b.y + z*b.z;
}
// https://www.tutorialspoint.com/cplusplus-program-to-compute-cross-product-of-two-vectors
Vector3D Vector3D::operator^(const Vector3D&v) const {
    return Vector3D(y*v.z - z*v.y, - (x*v.z - z*v.x) , x*v.y - y*v.x);
}
// Scaling
Vector3D operator*(const double a, const Vector3D &v) {
    return v*a;
}

