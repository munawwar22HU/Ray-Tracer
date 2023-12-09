# pragma once
# include "Tracer.hpp"
/**
   This file declares the Basic class which inherits from the ray tracer 
   class and represents the Basic Ray Tracer.
   Courtesy Kevin Suffern.
*/

class Basic : public Tracer {
 public:
    // Set world_ptr to NULL
    Basic();
    // Set world_ptr to w_ptr
    Basic (World* w_ptr);
    // Deconstructor
    virtual ~Basic() = default;
    // Trace Ray
    RGBColor trace_ray(const Ray ray, const int depth) const override;
};


