#include "Point.hpp"
#include "../world/World.hpp"
// Set Light to (1,1,1)
Point::Point() : Light() {}
// Set Light to (c,c,c)
Point::Point(float c) : Light(c) {}
// Set Light to (r,g,b)
Point::Point(float r, float g, float b) : Light(r, g, b) {}
// Set Light to c
Point::Point(const RGBColor& c) : Light(c) {}
// Set Location
void Point::set_location(float p) {
    Location = Point3D(p);
}

void Point::set_location(float x, float y, float z) {
    Location = Point3D(x, y, z);
}
void Point::set_location(const Point3D& p) {
    Location = Point3D(p);
}
// Get Direction
Vector3D Point::get_direction(const ShadeInfo &si) const {
    Vector3D dir = Location - si.hit_point;
    dir.normalize();
    return dir;
}
// Get Shadow
RGBColor Point::L() const {
    return ls * color;
}
// Is in shadow
bool Point::in_shadow(const Ray& ray, const ShadeInfo& si) const {
    float t;
    int num_objects = si.w ->geometry.size();
    float d = Location.distance(ray.o);
    for (int i = 0 ;  i < num_objects; i++) {
        if (si.w->geometry[i]->shadow_hit(ray, t) && t < d) {
            return true;
        }
    }
    return false;
}

