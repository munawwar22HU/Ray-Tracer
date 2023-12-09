#include "Parallel.hpp"
// set dir parallel to -z (negative z) axis.
Parallel::Parallel() : dir {0.0, 0.0 , -1.0} {}
// set dir parallel to (c, c, c).
Parallel::Parallel(float c) :  dir{c, c, c} {}
// set dir parallel to (x, y, z)
Parallel::Parallel(float x, float y, float z):  dir{x, y, z} {}
// set dir parallel to d.
Parallel::Parallel(const Vector3D &d) : dir{d} {}
// Copy constuctor
Parallel::Parallel(const Parallel &camera) {
    dir = camera.dir;
}
// Assigment Operator Overload
Parallel& Parallel::operator=(const Parallel &other) {
    dir = other.dir;
    return (*this);
}
// Get direction of projection for a point.
Vector3D Parallel::get_direction(const Point3D &p) const {
    // The direction remains same irrespective of the position of the point.
    return dir;
}
