#pragma once
#include "Sampler.hpp"
#include <vector>
/**
   This file declares the Regular class which inherits
   from the Sampler Class and represents a Regular Sampler
   Courtesy Kevin Suffern.
*/

class Regular : public Sampler {
 public:
  // Initializes members to NULL.
  Regular() = default;
  // set members.
  Regular(Camera *c_ptr, ViewPlane *v_ptr, int n);
  // Copy Constructor
  Regular(const Regular &camera);
  // Assingment Operator
  Regular &operator=(const Regular &other);
  // Desctructor.
  virtual ~Regular() = default;
  // Shoot n rays through each pixel
  std::vector<Ray> get_rays(int px, int py) const override;
};
