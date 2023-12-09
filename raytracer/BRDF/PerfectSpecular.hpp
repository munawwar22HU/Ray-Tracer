#pragma once

/**
   This file declares the Perfect Specular class which inherits from the abstract class BRDF.

   Courtesy Kevin Suffern.
*/

#include "BRDF.hpp"

class PerfectSpecular : public BRDF {
    private:
        float kr;
        RGBColor cr;

    public:
        // Constructor
        PerfectSpecular();
        // Copy Constructor
        PerfectSpecular(const PerfectSpecular& other);
        // Copy Perfect Specular
        virtual PerfectSpecular* clone() const;
        // Destructor
        virtual ~PerfectSpecular() = default;
        // Compute Color
        virtual RGBColor f(const ShadeInfo& si,
        const Vector3D& wo, const Vector3D& wi) const;

        virtual RGBColor sample_f(const ShadeInfo& si,
        const Vector3D& wo, Vector3D& wi) const;

        virtual RGBColor sample_f(const ShadeInfo& si,
        const Vector3D& wo, Vector3D& wi, float& pdf) const;

        virtual RGBColor rho(const ShadeInfo& sinfo, const Vector3D& wo) const;
        // Setters
        void set_kr(const float k);
        void set_cr(const RGBColor& c);
        void set_cr(const float r, const float g, const float b);
        void set_cr(const float c);
};
