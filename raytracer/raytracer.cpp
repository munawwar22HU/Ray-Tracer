#include <iostream>
#include <omp.h>
#include <chrono>
using namespace std::chrono;
#include "materials/Cosine.hpp"

#include "samplers/Sampler.hpp"

#include "utilities/Image.hpp"
#include "utilities/RGBColor.hpp"
#include "utilities/Ray.hpp"
#include "utilities/ShadeInfo.hpp"
#include "tracers/Tracer.hpp"
#include "world/World.hpp"
#include "world/ViewPlane.hpp"
#include "acceleration/BVH.hpp"

int main(int argc, char **argv) {
  auto start = high_resolution_clock::now();
  World world;
  world.build();
  //world.set_acceleration(new BVH(&world));
  Tracer* tracer = world.tracer_ptr;
  Sampler *sampler = world.sampler_ptr;
  ViewPlane &viewplane = world.vplane;
  Image image(viewplane);


  #pragma omp parellel for schedule(dynamic)
  for (int x = 0; x < viewplane.hres; x++) {   // across.
    for (int y = 0; y < viewplane.vres; y++) { // down.
      // Get rays for the pixel from the sampler. The pixel color is the
      // weighted sum of the shades for each ray.
      RGBColor pixel_color(0);
      std::vector<Ray> rays = sampler->get_rays(x, y);
      for (const auto &ray : rays) {
        pixel_color += tracer->trace_ray(ray, 0);
      }
      pixel_color/=sampler->get_num_rays();
      // Save color to image.
      image.set_pixel(x, y, pixel_color);
      // std::cout << pixel_color << "\n";
    }
  }
  // Write image to file.
  image.write_ppm("scene.ppm");
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(stop - start);
  std::cout << "Wrote image.\n";
  std::cout << "Duration " << duration.count() << std::endl;
  
  return 0;
}
