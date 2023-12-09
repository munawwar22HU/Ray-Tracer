#pragma once
/**
 * This file declares the abstract class Acceleration which is
 * then inherited by all concrete acceleration structures.
 */

#include <vector>
class Ray;
class ShadeInfo;
class World;

class Acceleration {
 protected:
    World* world_ptr;
 public:
    // Default Constructor
    Acceleration() = default;
    // Compute intersection with ray
    virtual ShadeInfo hit(const Ray& ray) = 0;
    // Destructor
    virtual ~Acceleration() = default;
};
