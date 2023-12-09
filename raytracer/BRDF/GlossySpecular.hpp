#pragma once
/**
   This file declares the Glossy Specular class which inherits from the abstract class BRDF.

   Courtesy Kevin Suffern.
*/

#include "BRDF.hpp"
#include "../utilities/Point3D.hpp"

class GlossySpecular : public BRDF {
    private:
        float ks;
        float exp;
        RGBColor cs;
    public:
        // Constructor
        GlossySpecular();
        // Copy constructor
        GlossySpecular(const GlossySpecular& other);
        // Copy GlossSpecular
        virtual GlossySpecular* clone() const;
        // Destructor
        virtual ~GlossySpecular() = default;
        // Compute Colors
        virtual RGBColor f(const ShadeInfo& si,
        const Vector3D& wo, const Vector3D& wi) const;

        virtual RGBColor sample_f(const ShadeInfo& si,
        const Vector3D& wo, Vector3D& wi) const;

        virtual RGBColor sample_f(const ShadeInfo& si,
        const Vector3D& wo, Vector3D& wi, float& pdf) const;

        virtual RGBColor rho(const ShadeInfo& si, const Vector3D& wo) const;

        // Members Getters & Setters.
        void set_ks(const float k);
        void set_exp(const float e);
        void set_cs(const RGBColor& c);
        void set_cs(const float r, const float g, const float b);
        void set_cs(const float c);
};
