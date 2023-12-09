#include "Plane.hpp"
#include <string>
#include <sstream>
// set plane to xz-plane.
Plane::Plane() : a {0, 0, 0} , n{0, 1, 0} {}
// set point and normal, then normalize.
Plane::Plane(const Point3D &pt, const Vector3D &_n) {
    a = pt;
    n = _n;
    n.normalize();
}
// Copy constructor
Plane::Plane(const Plane &object) {
    a = object.a;
    n = object.n;
}
// Assignment operator.
Plane& Plane::operator=(const Plane &rhs) {
    a = rhs.a;
    n = rhs.n;
    return (*this);
}
// String representation.
std::string Plane::to_string() const {
    std::stringstream ss;
    ss << "Point : " << a.to_string() << "Normal  : " << n.to_string();
    return ss.str();
}
// Ray intersection. Set t and sinfo as per intersection with this object.
bool Plane::hit(const Ray &ray, float &t, ShadeInfo &s) const {
    double temp = (a - ray.o) * n / (ray.d * n);
    if (temp > kEpsilon) {
        t = temp;
        s.hit = true;
        s.material_ptr = material_ptr;
        s.normal = n;
        s.ray = ray;
        s.hit_point = ray.o + ray.d * t;
        s.t = t;
        return true;
    }
    return false;
}
// Get bounding box.
BBox Plane::getBBox() const {
    return BBox();
}

bool Plane::shadow_hit(const Ray& ray, float& tmin) const {
    float t = (a  - ray.o)*n / (ray.d*n);
    if (t > kEpsilon) {
        tmin = t;
        return true;
    } else {
        return false;
    }
}

Point3D Plane::getCenter() const {
    return a;
}


