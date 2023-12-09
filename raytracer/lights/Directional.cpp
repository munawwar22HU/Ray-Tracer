#include "Directional.hpp"
#include "../world/World.hpp"
// Set Light to (1,1,1)
Directional::Directional() : Light() {}
// Set Light to (c,c,c)
Directional::Directional(float c) : Light(c) {}
// Set Light to (r,g,b)
Directional::Directional(float r, float g, float b) : Light(r, g, b) {}
// Set Light to c
Directional::Directional(const RGBColor& c) : Light(c) {}
// Set Direction
void Directional::set_direction(float p) {
    Direction = Vector3D(p);
    Direction.normalize();
}
void Directional::set_direction(float x, float y, float z) {
    Direction = Vector3D(x, y, z);
    Direction.normalize();
}
void Directional::set_direction(const Vector3D& p) {
    Direction = p;
    Direction.normalize();
}
// Get Direction
Vector3D Directional::get_direction(const ShadeInfo& si) const {
    return Direction;
    
}
// Get Shade
RGBColor Directional::L() const {
    return ls * color;
}
// Is in Shadow
bool Directional::in_shadow(const Ray &ray, const ShadeInfo &si) const {
    float t;
    int num_objects = si.w->geometry.size();

    for (int j = 0; j < num_objects; j++) {
        if (si.w->geometry[j]->shadow_hit(ray, t) && t > 0) {
            return true;
        }
    }
    return false;
}
