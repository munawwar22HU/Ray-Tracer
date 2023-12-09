#pragma once
#include "Light.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Point3D.hpp"
/**
   This file declares the Light class which is an abstract class for concrete
   lights to inherit from. A camera views the world through a view plane.

   Courtesy Kevin Suffern.
*/
class RGBColor;
class Point3D;
class Vector3D;
class ShadeInfo;
class Spotlight: public Light {
 private:
    Point3D Location; // Location
    Vector3D Direction; // Direction
    float theta; // theta
 public:
    // Set Light to (1,1,1)
    Spotlight();
    // Set Light to (c,c,c)
    Spotlight(float c);
    // Set Light to (r,g,b)
    Spotlight(float r , float g, float b);
    // Set Light to c
    Spotlight(const RGBColor& c);
    // Copy Constructor
    Spotlight(const Spotlight & rhs) =  default;
    // Assignment Operator
    Spotlight& operator=(const Spotlight & rhs) = default;
    // Desctructor
    virtual ~Spotlight() = default;
    // Set Location
    void set_location(float p);
    void set_location(float x, float y, float z);
    void set_location(const Point3D& p);
    // Set theta
    void set_theta(float t); 
    // Set Direction
    void set_direction(float c);                   
    void set_direction(float x, float y, float z); 
    void set_direction(const Vector3D& p);
    // Get Direction
    virtual Vector3D get_direction(const ShadeInfo& si) const override;
    // Get Shade 
    virtual RGBColor L() const override;
    // Is in shadow
    virtual bool in_shadow(const Ray& ray, const ShadeInfo& si) const override;
         

};
