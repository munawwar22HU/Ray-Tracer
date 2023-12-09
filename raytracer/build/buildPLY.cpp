// #include "../cameras/Perspective.hpp"
// #include "../tracers/Basic.hpp"
// #include "../materials/Cosine.hpp"
// #include "../samplers/Simple.hpp"
// #include "../utilities/Point3D.hpp"
// #include "../utilities/Constants.hpp"
// #include "../utilities/Vector3D.hpp"
// #include "../world/World.hpp"

#include "../cameras/Perspective.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "../tracers/Basic.hpp"

#include "../materials/Cosine.hpp"

#include "../samplers/Simple.hpp"

#include "../utilities/Point3D.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"

#include "../world/World.hpp"

#include "../materials/Matte.hpp"

// Render PLY Files

void World::build(void) {
  // view plane
    vplane.top_left = Point3D(-20, 20, 20);
  vplane.bottom_right = Point3D(20, -20, 20);
  vplane.hres = 1920;
  vplane.vres = 1080;

    
  // Background color.
  RGBColor grey(0.0, 0.0, 0.0);

  bg_color = grey;

  // camera and sampler.
  // set_camera(new Perspective(0, 0, 10));
  // set_tracer(new Basic(this));
  // sampler_ptr = new Simple(camera_ptr, &vplane);
      set_camera(new Perspective(0, 0, 50));
    set_tracer(new Basic(this));
    sampler_ptr = new Simple(camera_ptr, &vplane);

  //load mesh

	LoadMesh("PLYmodels/chair.ply", new Cosine(darkgrey), Point3D(10,-10,-20), Point3D(25,10,0));
	LoadMesh("PLYmodels/Metal_table.ply", new Cosine(red),Point3D (4,-10,-10), Point3D(17,-5,10));
	LoadMesh("PLYmodels/Wooden_chair.ply", new Cosine(brown), Point3D(-15,-10,-10), Point3D(-2,10,0));
	LoadMesh("PLYmodels/vase.ply", new Cosine(darkpurple),Point3D(-10,0,-8), Point3D(-5,3,-3));
	LoadMesh("PLYmodels/leaf.ply", new Cosine(green),Point3D(-10,1.8,-8),Point3D(-5,6.8,-3));
	LoadMesh("PLYmodels/lamp.ply", new Cosine(silver),Point3D(-22,-10,-10), Point3D(-7, 20, 5));
	//add_mesh("models/shelf.ply", new Cosine(green),a,a+b);

}