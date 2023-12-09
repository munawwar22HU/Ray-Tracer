#pragma once
/**
   This file declares the Lambertian class which inherits from the abstract class BRDF.

   Courtesy Kevin Suffern.
*/

#include "BRDF.hpp"

class Lambertian : public BRDF {
 private:
        float kd;
        float ka;
        float exp;
        RGBColor cd;

 public:
       // Constructor
        Lambertian();
       // Copy constructor
       Lambertian(const Lambertian& other);
       // Copy Lambertain
        virtual Lambertian* clone() const;
       // Destructor
        virtual ~Lambertian() = default;
       // Computer Color
       virtual RGBColor f(const ShadeInfo& si,
       const Vector3D& wo, const Vector3D& wi) const;

       virtual RGBColor sample_f(const ShadeInfo& si,
       const Vector3D& wo, Vector3D& wi) const;

       virtual RGBColor sample_f(const ShadeInfo& si,
       const Vector3D& wo, Vector3D& wi, float& pdf) const;

       virtual RGBColor rho(const ShadeInfo& si, const Vector3D& wo) const;
       // Setters
       void set_ka(const float k);
       void set_kd(const float k);
       void set_cd(const RGBColor& c);
       void set_cd(const float r, const float g, const float b);
       void set_cd(const float c);
};
