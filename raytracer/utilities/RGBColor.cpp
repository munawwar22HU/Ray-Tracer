#include <cmath>
#include <sstream>
#include "RGBColor.hpp"

// set color to (0, 0, 0).
RGBColor::RGBColor() : r{0}, g{0}, b{0} {}
// set color to (c, c, c).
RGBColor::RGBColor(float c) : r{c}, g{c}, b{c} {}
// set color to (_r, _g, _b).
RGBColor::RGBColor(float _r, float _g, float _b) : r{_r} , g{_g} , b{_b} {}
// String representation.
std::string RGBColor::to_string() const {
    std::stringstream ss;
    ss << "(" << r << "," << g << "," << b << ")";
    return ss.str();
}
// addition.
RGBColor RGBColor::operator+(const RGBColor &c) const {
    return RGBColor(r+c.r, g+c.g, b+c.b);
}
// compound addition.
RGBColor& RGBColor::operator+=(const RGBColor &c) {
    r+=c.r;
    g+=c.g;
    b+=c.b;
    return (*this);
}
// multiplication by a float.
RGBColor RGBColor::operator*(const float a) const {
    return RGBColor(r*a, g*a, b*a);
}
// compound multiplication by a float.
RGBColor& RGBColor::operator*=(const float a) {
    r *=a;
    g *=a;
    b *=a;
    return (*this);
}
// division by a float.
RGBColor RGBColor::operator/(const float a) const {
    return this->operator*(1/a);
}
// compound division by a float.
RGBColor& RGBColor::operator/=(const float a) {
    r /=a;
    g /=a;
    b /=a;
    return (*this);
}
// component-wise multiplication.
RGBColor RGBColor::operator*(const RGBColor &c) const {
    return RGBColor(r*c.r, g*c.g , b*c.b);
}
// equality.
bool RGBColor::operator==(const RGBColor &c) const {
    return (r == c.r && g == c.g && b == c.b);
}
// raise components to a power.
RGBColor RGBColor::powc(float p) const {
    return RGBColor(pow(r, p), pow(r, g), pow(r, b));
}
// the average of the components.
float RGBColor::average() const {
    return (r+g+b)/3;
}
// Multiplication by a float.
RGBColor operator*(const float a, const RGBColor &c) {
    return c*a;
}


