#pragma once
/**
   This file declares the BRDF class which is an abstract class for concrete
   BRDFs to inherit from.

   Courtesy Kevin Suffern.
*/

#include <cmath>
#include <random>
#include "../utilities/Constants.hpp"
#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"

class BRDF {
 public:
      // Constructor
      BRDF() = default;
      // Copy Constructor
      BRDF(const BRDF& brdf) = default;
      // Assignment Operator
      BRDF& operator=(const BRDF& rhs)= default;
      // Destructor
      virtual ~BRDF() = default;
      // Copy BRDF
      virtual BRDF* clone() const = 0;
      // Compute Colors
      virtual RGBColor f(const ShadeInfo& si,
      const Vector3D& wo, const Vector3D& wi) const = 0;

      virtual RGBColor sample_f(const ShadeInfo& si,
      const Vector3D& wo, Vector3D& wi) const = 0;

      virtual RGBColor sample_f(const ShadeInfo& si,
      const Vector3D& wo, Vector3D& wi, float& pdf) const = 0;

      virtual RGBColor rho(const ShadeInfo& si, const Vector3D& wo) const = 0;
      // Sampler
      Point3D sample_hemisphere(const float e) const;
};


