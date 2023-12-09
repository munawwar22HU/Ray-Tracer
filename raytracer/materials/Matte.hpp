#pragma once
/**
   This file declares the Matte class which represents a simple materia;
   material.

   Courtesy Kevin Suffern.
*/

#include "Material.hpp"
#include "../BRDF/Lambertian.hpp"
#include "../world/World.hpp"
#include "../lights/Light.hpp"
#include "../utilities/ShadeInfo.hpp"


class Lambertian;
class RGBColor;
class ShadeInfo;

class Matte : public Material {
 private:
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;

 public:
    // Default Constructor
    Matte();
    // Overloaded Constructor
    Matte(const Matte& m);
    // Assignment Operator
    Matte& operator=(const Matte& other);

    // Destructor
    ~Matte();
    // Setters
    void set_ka(const float ka);
    void set_kd(const float kd);
    void set_cd(const RGBColor c);
    void set_cd(const float r, const float g, const float b);
    void set_cd(const float c);

    // Compute direct diffuse illumination
    virtual RGBColor shade(const ShadeInfo& sinfo) const override;

    // Copy Matte
    virtual Matte* clone() const override;
};
