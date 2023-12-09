#pragma once
/**
   This file declares the Reflective class which represents a simple reflective
   material.

   Courtesy Kevin Suffern.
*/

#include "Material.hpp"

class GlossySpecular;
class Lambertian;
class PerfectSpecular;

class Reflective : public Material {
 protected:
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;
    GlossySpecular*specular_brdf;
    PerfectSpecular* reflective_brdf;

 public:
    // Default Constructor
    Reflective();
    // Overloaded Constructor
    Reflective(const Reflective& other);
    // Assignment Operator
    Reflective& operator=(const Reflective& rhs);
    // Setters
    virtual ~Reflective();
    void set_ka(const float ka);
    void set_kd(const float kd);
    void set_ks(const float ks);
    void set_exp(const float exp);
    void set_cd(const RGBColor c);
    void set_cd(const float r, const float g, const float b);
    void set_cd(const float c);
    void set_kr(const float k);
    void set_cr(const RGBColor& c);
    void set_cr(const float r, const float g, const float b);
    void set_cr(const float c);

    // Compute Color Shade
    RGBColor shade(const ShadeInfo& si)const override;

    // Copy Reflective
    Reflective* clone() const override;
};
