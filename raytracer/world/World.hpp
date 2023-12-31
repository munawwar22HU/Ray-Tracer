#pragma once

/**
   This file declares the World class which contains all the information about
   the scene - geometry and materials, lights, viewplane, camera, samplers, and
   acceleration structures.

   It also traces rays through the scene.

   Courtesy Kevin Suffern.
*/

#include <vector>
#include <iostream>
#include "../utilities/RGBColor.hpp"
#include "../geometry/Geometry.hpp"
#include "../samplers/Sampler.hpp"
#include "../tracers/Tracer.hpp"
#include "../lights/Light.hpp"
#include "../lights/Ambient.hpp"
#include "../acceleration/Acceleration.hpp"
#include "../happly/happly.h"
#include "../geometry/Triangle.hpp"
#include "ViewPlane.hpp"

class Camera;
class Geometry;
class Ray;
class Sampler;
class ShadeInfo;
class Tracer;


class World {
public:
  ViewPlane vplane;
  RGBColor bg_color;
  std::vector<Geometry *> geometry;
  std::vector<Light *> lights;
  Camera *camera_ptr;
  Sampler *sampler_ptr;
  Tracer *tracer_ptr;
  Ambient *ambient_ptr;
  Acceleration *acceleration_ptr;

public:
  // Constructors.
  World(); // initialize members.

  // Destructor.
  ~World(); // free memory.

  // Add to the scene.
  void add_geometry(Geometry *geom_ptr);
  void add_light(Light *light_ptr);
  void set_camera(Camera *c_ptr);
  void set_tracer(Tracer *t_ptr);
  void set_ambient_light(Ambient* amb_ptr);
  void set_acceleration(Acceleration* accel_ptr);

  // Build scene - add all geometry, materials, lights, viewplane, camera,
  // samplers, and acceleration structures
  void build();
  // Load Ply File into Triangles
  void LoadMesh (std::string filename, Material* m_ptr, Point3D pmin, Point3D pmax);
 

  // Returns appropriate shading information corresponding to intersection of
  // the ray with the scene geometry.
  ShadeInfo hit_objects(const Ray &ray);
};





