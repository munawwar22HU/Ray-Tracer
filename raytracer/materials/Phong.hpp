#pragma once
/**
   This file declares the Phong class which represents a phong materia;
   material.

   Courtesy Kevin Suffern.
*/

#include "Material.hpp"

class GlossySpecular;
class Lambertian;

class Phong : public Material {
 protected:
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;
    GlossySpecular*specular_brdf;

 public:
    // Default Constructor
    Phong();
    // Overloaded Constructor
    Phong(const Phong& other);
    // Assignment Operator
    Phong& operator=(const Phong& rhs);
    // Setters
    virtual ~Phong();
    void set_ka(const float ka);
    void set_kd(const float kd);
    void set_ks(const float ks);
    void set_exp(const float exp);
    void set_cd(const RGBColor c);
    void set_cd(const float r, const float g, const float b);
    void set_cd(const float c);

    // Compute Color Shade
    RGBColor shade(const ShadeInfo& sinfo)const override;

    // Copy Phong
    Phong* clone() const override;
};