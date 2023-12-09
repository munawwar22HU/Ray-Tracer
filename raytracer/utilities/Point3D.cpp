#include <cmath>
#include <sstream>
#include "Point3D.hpp"

// set point to (0, 0, 0).
Point3D::Point3D() : x(0) , y(0) , z(0) {}
// set point to (c, c, c).
Point3D::Point3D(float c) : x(c) , y(c) , z(c) {}
// set point to (x,y,z).
Point3D::Point3D(float x, float y, float z) : x(x) , y(y) , z(z) {}

// https://stackoverflow.com/questions/53211020/making-my-own-tostring-method-on-c-struct/53211127
// String representation.
std::string Point3D::to_string() const {
    std::stringstream ss;
    ss << "(" << x << "," << y << "," << z << ")";
    return ss.str();
}

// unary minus.
Point3D Point3D::operator-() const {
    return Point3D(-x, -y, -z);
}
// vector joining two points
Vector3D Point3D::operator-(const Point3D &p) const {
    return Vector3D(x - p.x, y - p.y, z - p.z);
}
// addition of a vector
Point3D Point3D::operator+(const Vector3D &v) const {
    return Point3D(x+v.x, y+v.y, z+v.z);
}

// subtraction of a vector
Point3D Point3D::operator-(const Vector3D&v) const {
    return Point3D(x - v.x, y - v.y, z - v.z);
}

Point3D Point3D::operator*(const float s) const {
    return Point3D(x*s, y*s, z*s);
}

// https://www.w3schools.com/cpp/cpp_math.asp
float Point3D::d_squared(const Point3D &p) const {
    return (pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
}

float Point3D::distance(const Point3D&p) const {
    return sqrt(this->d_squared(p));
}

Point3D operator*(const float a , const Point3D &pt) {
    return pt*a;
}

Point3D min(const Point3D& a,  const Point3D &b) {
    return Point3D (std::min(a.x, b.x),std::min(a.y, b.y), std::min(a.z, b.z)) ;
}

Point3D max(const Point3D& a,  const Point3D &b) {
    return Point3D (std::max(a.x, b.x),std::max(a.y, b.y), std::max(a.z, b.z)) ;
}

float Point3D::operator[](int idx) const
{
    switch (idx) {
      case 0:
        return x;
      case 1:
        return y;
    }
    return z;
}

Point3D Point3D::interpolate(const Point3D& a, const Point3D& b,
const Point3D& c, const Point3D& x, const Point3D& y) {
  return Point3D(x.x + (c.x - a.x) / (b.x - a.x) * (y.x - x.x),
                 x.y + (c.y - a.y) / (b.y - a.y) * (y.y - x.y),
                 x.z + (c.z - a.z) / (b.z - a.z) * (y.z - x.z));
}
