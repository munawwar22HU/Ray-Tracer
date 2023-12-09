#pragma once
#include <vector>
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"
#include "../cameras/Camera.hpp"
/**
  This file declares the Sampler class which is an abstract class for concrete
  samplers to inherit from.
  Courtesy Kevin Suffern.
*/
class Camera;
class Ray;
class ViewPlane;

class Sampler {
protected:
  Camera *camera_ptr;         // Camera_ptr
  ViewPlane *viewplane_ptr;   // Viewplane_ptr
  int num_rays;     // The number of rays shot through each pixel
public:
  // Initializes members to NULL.
  Sampler();
  // Set Members
  Sampler(Camera *c_ptr, ViewPlane *v_ptr);
  // Copy constuctor
  Sampler(const Sampler &camera) = default;
  // Assignment Operator
  Sampler &operator=(const Sampler &other) = default;
  // Desctructor.
  virtual ~Sampler() = default;
  // Get number of rays
  int get_num_rays() const;
  // Get rays corresponding to a pixel in the view plane. px and py are 0-based
  // indexes of the pixel in the view plane, with the origin at the top left of
  // the view plane.
  virtual std::vector<Ray> get_rays(int px, int py) const = 0;
};
