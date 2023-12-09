#pragma once
#include "../utilities/RGBColor.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Ray.hpp"
/**
   This file declares the Light class which is an abstract class for concrete
   lights to inherit from. A camera views the world through a view plane.
   Courtesy Kevin Suffern.
*/
class Vector3D;
class ShadeInfo;
class Ray;
class RGBColor;

class Light {
 protected:
    RGBColor color;   //  Color of the Light
    float ls;         // Intensity
    bool shadows;     // Does this cast shadow

 public:
    // Set Light to (1,1,1)
    Light();
    // Set Light to (c,c,c)
    Light(float c);
    // Set Light to (r,g,b)
    Light(float r, float g, float b);
    // Set Light to c
    Light(const RGBColor& c);
    // Copy Constructor
    Light(const Light& other) = default;
    // Assignment Operator
    Light& operator=(const Light& other) = default;
    // Destructor
    virtual ~Light() = default;
    // Set Color
    void set_color(float c); 
    void set_color(float r, float g, float b);
    void set_color(const RGBColor& c);
    // Scale Radiance
    void scale_radiance(const float b);
    // Set Shadows
    void set_shadows (bool s);
    // Get Shadows
    bool casts_shadow() const;
    // Get Direction
    virtual Vector3D get_direction(const ShadeInfo& si) const = 0;
    // Get Shade
    virtual RGBColor L() const = 0;
    // Is in Shadow
    virtual bool in_shadow(const Ray& ray, const ShadeInfo& si) const = 0;
};
