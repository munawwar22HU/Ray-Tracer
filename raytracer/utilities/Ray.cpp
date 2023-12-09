#include <cmath>
#include <sstream>
#include <string>
#include "Ray.hpp"

// set origin and dir to (0, 0, 0), w to 1.
Ray::Ray() : o{0} , d{0} , w{1} {}
// set origin, dir; w is 1.
Ray::Ray(const Point3D &origin , const Vector3D&dir) : o{origin} ,
 d{dir} , w{1} {}
// String Representation
std::string Ray::to_string() const {
    std::stringstream ss;
    ss << "Origin : " << o.to_string() << " Direction : " << d.to_string();
    return ss.str();
}
