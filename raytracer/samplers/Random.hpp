#pragma once
#include "Sampler.hpp"
#include "../utilities/Constants.hpp"
#include <vector>
/**
   This file declares the Random class which inherits from the 
   Sampler class and represents Random sampler.
   Courtesy Kevin Suffern.
*/
class Random : public Sampler {
 public:
  // Initializes members to NULL.
  Random() = default;
  // Set members.
  Random(Camera *c_ptr, ViewPlane *v_ptr, int n);
  // Copy constuctor
  Random(const  Random &other);
  // Assingment Operator
  Random &operator=(const Random &other);
  // Desctructor.
  virtual ~Random() = default;
  // Shoot n rays through each pixel
  std::vector<Ray> get_rays(int px, int py) const override;
};
