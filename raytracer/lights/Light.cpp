#include "Light.hpp"
// Set Light to (1,1,1)
Light::Light() : color(RGBColor(1, 1, 1)), ls(1.0), shadows(false)
{}
// Set Light to (c,c,c)
Light::Light(float c) : color(RGBColor(c, c, c)), ls(1.0), shadows(false)
{}
// Set Light to (r,g,b)
Light::Light(float r, float g, float b) : color(RGBColor(r, g, b)), ls(1.0)
, shadows(false) {}
// Set Light to c
Light::Light(const RGBColor& c) : color(c), ls(1.0)
{}
// Set Color
void Light::set_color(float c) {
    color = RGBColor(c, c, c);
}
void Light::set_color(float r, float g, float b) {
    color = RGBColor(r, g, b);
}
void Light::set_color(const RGBColor& c) {
    color = c;
}
// Scale Radiance
void Light::scale_radiance(const float b) {
    ls = b;
}
// Set Shadows
void Light::set_shadows(bool s) {
    shadows = s;
}
// Get Shadows
bool Light::casts_shadow() const {
    return shadows;
}




