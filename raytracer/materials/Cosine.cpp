#include "Cosine.hpp"
#include <cmath>

// set color to (0, 0, 0).
Cosine::Cosine() : color {} {};
// set color to (c, c, c).
Cosine::Cosine(float c) : color {c} {};
// set color to (r, g, b).
Cosine::Cosine(float r, float g, float b) : color{r, g, b} {}
// set color to c.
Cosine::Cosine(const RGBColor &c): color {c} {}
// Copy constuctor.
Cosine::Cosine(const Cosine &other) {
    color = other.color;
}
// Assignment operator.
Cosine& Cosine::operator=(const Cosine &other) {
    color = other.color;
    return (*this);
}
/* Returned shade is: color * cos \theta.
 \theta is the angle between the normal at the hit pont and the ray.
 Assuming unit vectors, cos \theta = dot product of normal and -ray.dir.
*/
RGBColor Cosine::shade(const ShadeInfo &sinfo)const {
    // - ray.dir
    Vector3D d = -sinfo.ray.d;
    // normalize
    d.normalize();
    // Normal at the hight point
    Vector3D n = sinfo.normal;
    // normalize
    n.normalize();
    // color * cos \theta.
    return color * (d * n);
}

Cosine*	Cosine::clone() const {
	return (new Cosine(*this));
}

