// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

// This builds the scene for Figure 22.17
// The images are all rendered with one sample per pixel
#include "../cameras/Perspective.hpp"
#include "../cameras/Parallel.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../tracers/Basic.hpp"
#include "../tracers/Whitted.hpp"
#include "../lights/Ambient.hpp"
#include "../lights/Point.hpp"
#include "../materials/Cosine.hpp"
#include "../materials/Matte.hpp"
#include "../materials/Reflective.hpp"
#include "../materials/Phong.hpp"
#include "../samplers/Simple.hpp"
#include "../samplers/Regular.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"
#include "../lights/Directional.hpp"
#include "../lights/Point.hpp"
#include "../lights/Spotlight.hpp"
#include "../lights/Light.hpp"
#include "../world/World.hpp"

void World::build(void) {
    vplane.top_left.x = -10;
    vplane.top_left.y = 10;
    vplane.top_left.z = 10;
    vplane.bottom_right.x = 10;
    vplane.bottom_right.y = -10;
    vplane.bottom_right.z = 10;
    vplane.hres = 800;
    vplane.vres = 800;

    set_camera(new Perspective(0, 0, 20));
    set_tracer(new Basic(this));
    sampler_ptr = new Simple(camera_ptr, &vplane);

    bg_color = RGBColor(0.15);
    int num_spheres = 1000;

    for (int i=0; i<num_spheres; i++) {
        RGBColor c(((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)), ((double) rand() / (RAND_MAX)));
        int randomX = (-10) + (rand() % static_cast<int>(10 - (-10) + 1));
        int randomY = (-10) + (rand() % static_cast<int>(10 - (-10) + 1));
    Sphere* sphere_ptr = new Sphere(Point3D(randomX, randomY, 0), 3);
    sphere_ptr->set_material(new Cosine(c));
    add_geometry(sphere_ptr);
  }
}


