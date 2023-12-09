#pragma once
#include "Light.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/RGBcolor.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/ShadeInfo.hpp"
/**
   This file declares the Directional class which inherits
   from the light class and represents Directional Light source.
   Courtesy Kevin Suffern.
*/
class Point3D;
class ShadeInfo;
class Vector3D;
class RGBColor;

class Directional : public Light {
 protected:
    Vector3D Direction;  // Direction Vector

 public:
    // Set Light to (1,1,1)
    Directional();
    // Set Light to (c,c,c)
    Directional(float c);
    // Set Light to (r,g,b)
    Directional(float r, float g, float b);
    // Set Light to c
    Directional(const RGBColor &c);
    // Copy Constructor
    Directional(const Directional& other) = default;
    // Assignment Operator
    Directional& operator=(const Directional& other) = default;
    // Destructor
    virtual ~Directional() = default;
    // Set Direction
    void set_direction(float p);
    void set_direction(float x, float y, float z);
    void set_direction(const Vector3D& p);
    // Get Direction
    Vector3D get_direction(const ShadeInfo& si) const;
    // Get Shade
    RGBColor L() const;
    // Is in shadow
    bool in_shadow(const Ray& ray, const ShadeInfo& si) const override;
};
