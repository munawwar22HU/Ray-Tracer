# pragma once
# include "Tracer.hpp"
/**
   This file declares the Whitted class which inherits from the ray tracer 
   class and represents the Whitted Ray Tracer.
   Courtesy Kevin Suffern.
*/
class Whitted : public Tracer {
 public:
    // Set world_ptr to NULL
    Whitted();
    // Set world_ptr to w_ptr
    Whitted (World* w_ptr);
    // Deconstructor
    virtual ~
    Whitted() = default;
    // Trace Ray
    virtual RGBColor
    trace_ray(const Ray ray, const int depth) const;
};


