#include "Spotlight.hpp"
#include "Light.hpp"
#include "../world/World.hpp"
#include <math.h>
// Set Light to (1,1,1)
Spotlight::Spotlight() : Light() {}
// Set Light to (c,c,c)
Spotlight::Spotlight(float c) : Light(c) {}
// Set Light to (r,g,b)
Spotlight::Spotlight(float r, float g, float b) : Light(r, g, b) {}
// Set Light to c
Spotlight::Spotlight(const RGBColor& c) : Light(c) {}
// Set Location
void Spotlight::set_location(float p) {
    Location = Point3D(p);
}
void Spotlight::set_location(float x, float y, float z) {
    Location = Point3D(x, y, z);
}
void Spotlight::set_location(const Point3D& p) {
    Location = p;
}
// Set theta
void Spotlight::set_theta(float t) {
    theta = t;
}
// Set Direction
void Spotlight::set_direction(float c) {
    Direction = Vector3D(c);
    Direction.normalize();
}
void Spotlight::set_direction(float x, float y, float z) {
    Direction = Vector3D(x, y, z);
    Direction.normalize();
}
void Spotlight::set_direction(const Vector3D& p) {
    Direction = p;
    Direction.normalize();
}
// Get Direction
Vector3D Spotlight::get_direction(const ShadeInfo& si) const {
    Vector3D dir = Direction -  si.hit_point;
    dir.normalize();
    float t = (acos(dir * Direction));
    // Light is bounded by theta
    if (t <= theta) {
        return dir;
    }
    return Direction;
}

// Get Shadow
RGBColor Spotlight::L() const {
    return (ls * color);
}
// Is in Shadow
bool Spotlight::in_shadow(const Ray& ray, const ShadeInfo& si) const {
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


