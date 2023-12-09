#include "Perspective.hpp"
// set pos to origin.
Perspective::Perspective() : pos {0.0, 0.0, 0.0} {}
// set pos to (c, c, c).
Perspective::Perspective(float c) : pos{c, c, c} {}
// set pos to (x, y, z)
Perspective::Perspective(float x, float y, float z) : pos {x, y, z} {}
// set pos parallel to pt.
Perspective::Perspective(const Point3D &pt): pos{pt} {}
// Copy Constructor
Perspective::Perspective(const Perspective &camera) {
    pos = camera.pos;
}
// Assigment Operator Overload
Perspective& Perspective::operator=(const Perspective &other) {
    pos = other.pos;
    return (*this);
}
// Get direction of projection for a point.
Vector3D Perspective::get_direction(const Point3D &p) const {
    // Vector from the pos(origin) of the camera to the point P.
    Vector3D projVec = p - pos;
    return projVec;
}
