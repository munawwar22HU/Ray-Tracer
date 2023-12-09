#include "Triangle.hpp"
#include <sstream>
#include <string>

// Returns true if x is between 0 & 1
bool inRange(float x) {
    return (0 <= x && x <= 1);
}
// Triangle with vertices at origin.
Triangle::Triangle() : v0{} , v1{} , v2{}  {}
// set vertices.
Triangle::Triangle(const Point3D & _v0, const Point3D & _v1,
const Point3D & _v2) :
v0{_v0} , v1{_v1} , v2{_v2} {}
// Copy constructor.
Triangle::Triangle(const Triangle & _object) {
    v0 = _object.v0;
    v1 = _object.v1;
    v2 = _object.v2;
}
// Assignment operator.
Triangle& Triangle::operator=(const Triangle & _rhs) {
    v0 = _rhs.v0;
    v1 = _rhs.v1;
    v2 = _rhs.v2;
    return (*this);
}
// String representation.
std::string Triangle::to_string() const {
    std::stringstream ss;
    ss << "v0 : " << v0.to_string()
    << "v2 : " << v1.to_string()
    << "v3 : " << v2.to_string();
    return ss.str();
}
// Ray intersection. Set t and sinfo as per intersection with this object.
bool Triangle::hit(const Ray &ray, float &t, ShadeInfo &s) const {
    Vector3D norm = (v1 - v0) ^ (v2 - v0);
    // Dot products to calculate T;
    double a = (v0 - ray.o) * norm;
    double b = ray.d * norm;
    double T = a/b;
    Point3D hitpnt = ray.o + T*ray.d;
    if (T < kEpsilon) {
        return false;
    }
    float beta = ((hitpnt.x - v2.x)*(v0.y - v2.y) - (hitpnt.y - v2.y)
    *(v0.x - v2.x)) / ((v1.x - v2.x)*(v0.y - v2.y) - (v1.y - v2.y)
    *(v0.x - v2.x));
    float alpha = ((hitpnt.x - v2.x) - (beta) * (v1.x - v2.x)) / (v0.x - v2.x);

    if ( inRange(alpha) && inRange(beta) && inRange(alpha+beta) ) {
        t = T;
        s.normal = norm;
        s.normal.normalize();
        s.hit_point = hitpnt;
        s.ray = ray;
        s.t = t;
        s.material_ptr = material_ptr;
        s.hit = true;
        return true;
    } else {
        return false;
    }
    return false;
}
// Get bounding box.
BBox Triangle::getBBox() const {
    return BBox(min(v0, min(v1, v2)), max(v0, max(v1, v2)));
}


bool Triangle::shadow_hit(const Ray& ray, float& tmin) const {
    Vector3D norm = (v1 - v0) ^ (v2 - v0);
    // Dot products to calculate T;
    double a = (v0 - ray.o) * norm;
    double b = ray.d * norm;
    double T = a/b;
    Point3D hitpnt = ray.o + T*ray.d;
    if (T < kEpsilon) {
        return false;
    }
    float beta = ((hitpnt.x - v2.x)*(v0.y - v2.y) - (hitpnt.y - v2.y)
    *(v0.x - v2.x)) / ((v1.x - v2.x)*(v0.y - v2.y) - (v1.y - v2.y)
    *(v0.x - v2.x));
    float alpha = ((hitpnt.x - v2.x) - (beta) * (v1.x - v2.x)) / (v0.x - v2.x);

    if ( inRange(alpha) && inRange(beta) && inRange(alpha+beta) ) {
        tmin = T;
        return true;
    } else {
        return false;
    }
    return false;
}

Point3D Triangle::getCenter() const {
    Point3D centroid((v0.x + v1.x + v2.x)/3, (v0.y + v1.y + v2.y)/3, (v0.z + v1.z + v2.z)/3);
    return centroid;
}