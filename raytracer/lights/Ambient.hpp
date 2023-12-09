#pragma once
#include "Light.hpp"
/**
   This file declares the Ambient class which inherits
   from the light class and represents Ambient Light.
   Courtesy Kevin Suffern.
*/
class Ambient : public Light {
 public:
    // Set Light to (1,1,1)
    Ambient();
    // Set Light to (c,c,c)
    Ambient(float c);
    // Set Light to (r,g,b)
    Ambient(float r, float g, float b);
    // Set Light to c
    Ambient(const RGBColor& c);
    // Destructor
    virtual ~Ambient() = default;
    // Clone Ambeint
    Ambient* clone() const;
    // Get Direction
    Vector3D get_direction(const ShadeInfo& si) const override;
    // Get Shade
    RGBColor L() const override;
    // Is in Shadow
    bool in_shadow(const Ray& ray, const ShadeInfo& si) const override;
};
