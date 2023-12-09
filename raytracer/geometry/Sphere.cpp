#include "Sphere.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

// sphere at origin with radius 0.
Sphere::Sphere() : c{0, 0, 0} , r{0} {}
// set center and radius.
Sphere::Sphere(const Point3D &_c, float _r) : c{_c} , r{_r} {}
// Copy constructor
Sphere::Sphere(const Sphere &o) {
    c = o.c;
    r = o.r;
}
// Assignment operator.
Sphere& Sphere::operator=(const Sphere &rhs) {
    c = rhs.c;
    r = rhs.r;
    return (*this);
}
// String representation.
std::string Sphere::to_string() const {
    std::stringstream ss;
    ss << "Center : " << c.to_string() << " Raduis : " << r;
    return ss.str();
}
// Ray intersection. Set t and sinfo as per intersection with this object.
bool Sphere::hit(const Ray &ray, float &t, ShadeInfo &s)const {
    double discrim = sqrt((ray.d * (ray.o - c) * 2) * (ray.d * (ray.o - c) * 2)
    - 4 * (ray.d * ray.d) * ((ray.o - c) * (ray.o - c) - r * r));
    double t1 = (-(ray.d * (ray.o - c) * 2) - (discrim))
    / (2 * (ray.d * ray.d));
    double t2 = (-(ray.d * (ray.o - c) * 2) + (discrim))
    / (2 * (ray.d * ray.d));

    if (t1 < kEpsilon && t2 < kEpsilon) {
       return false;
    }
    if (t1 >= kEpsilon && t2 >= kEpsilon) {
        t = std::min(t1, t2);
    } else {
       t = std::max(t1, t2);
    }
    s.material_ptr = material_ptr;
    s.ray = ray;
    s.hit_point = ray.o + ray.d * t;
    s.normal = s.hit_point - c;
    s.normal.normalize();
    s.t = t;
    s.hit = true;
    return true;
}
//Get bounding box.
BBox Sphere::getBBox() const {
    Point3D min_t = c - Vector3D(r);
    Point3D max_t = c + Vector3D(r);
    return BBox(min_t, max_t);
}



bool Sphere::shadow_hit(const Ray& ray, float& tmin) const {
    double discrim = sqrt((ray.d * (ray.o - c) * 2) * (ray.d * (ray.o - c) * 2)
    - 4 * (ray.d * ray.d) * ((ray.o - c) * (ray.o - c) - r * r));
    double t1 = (-(ray.d * (ray.o - c) * 2) - (discrim))
    / (2 * (ray.d * ray.d));
    double t2 = (-(ray.d * (ray.o - c) * 2) + (discrim))
    / (2 * (ray.d * ray.d));

    if (t1 < kEpsilon && t2 < kEpsilon) {
       return false;
    }
    if (t1 >= kEpsilon && t2 >= kEpsilon) {
        tmin = std::min(t1, t2);
    } else {
        tmin = std::max(t1, t2);
    }
    return true;
}


Point3D Sphere::getCenter() const {
    return c;
}