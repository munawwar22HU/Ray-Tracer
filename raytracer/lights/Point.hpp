#pragma once
#include "Light.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/RGBcolor.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/ShadeInfo.hpp"
/**
   This file declares the Point class which inherits
   from the light class and represents Point Light source.
   Courtesy Kevin Suffern.
*/
class Point3D;
class ShadeInfo;
class Vector3D;
class ShadeInfo;
class Point : public Light {
 protected:
    Point3D Location; // Location

 public:
    // Set Light to (1,1,1)
    Point();
    // Set Light to (c,c,c)
    Point(float c);
    // Set Light to (r,g,b)
    Point(float r, float g, float b);
    // Set Light to c
    Point(const RGBColor &c);
    // Copy Constructor
    Point(const Point& other) = default;
    // Assignment Operator
    Point& operator=(const Point& other) = default;
    // Destructor
    virtual ~Point() = default;
    // Set Location
    void set_location(float p);
    void set_location(float x, float y, float z);
    void set_location(const Point3D& p);
    // Get Direction    
    Vector3D get_direction(const ShadeInfo& si) const override;
    // Get Shade
    RGBColor L() const override;
    // Is in Shadow
    bool in_shadow(const Ray& ray, const ShadeInfo& si) const override;
};
