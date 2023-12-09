#pragma once
#include "../world/World.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/Ray.hpp"
/**
   This file declares the Tracer class which is an abstract class for concrete
   tracers to inherit from. A camera views the world through a view plane.
   Courtesy Kevin Suffern.
*/

class World;
class RGBColor;
class Ray;

class Tracer {
 protected:
       World* world_ptr;
 public:
       // Set world_ptr to NULL
       Tracer();
       // Set world_ptr to w_ptr
       Tracer(World* w_ptr);
       // Deconstructor
       virtual ~Tracer() = default;
       // Trace Ray
       virtual RGBColor
       trace_ray(const Ray ray, const int depth) const = 0;
};


