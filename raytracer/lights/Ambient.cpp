#include "Ambient.hpp"
#include "../utilities/Vector3D.hpp"
#include "../world/World.hpp"
// Set Light to (1,1,1)
Ambient::Ambient() : Light() {}
// Set Light to (c,c,c)
Ambient::Ambient(float c) : Light(c) {}
// Set Light to (r,g,b)
Ambient::Ambient(float r, float g, float b) : Light(r, g, b) {}
// Set Light to c
Ambient::Ambient(const RGBColor& c) : Light(c) {}
// Clone Ambeint
Ambient* Ambient::clone() const {
    return (new Ambient(*this));
}
// Get Direction
Vector3D Ambient::get_direction(const ShadeInfo& si) const {
    return Vector3D(0);
}
// Get Shade
RGBColor Ambient::L() const {
    return (ls*color);
}
// Is in Shadow
bool Ambient::in_shadow(const Ray& ray, const ShadeInfo &si) const {
    return false;
}
