#include "Whitted.hpp"
// Set world_ptr to NULL
Whitted::Whitted() {
    world_ptr = nullptr;
}
// Set world_ptr to w_ptr
Whitted::Whitted(World* w_ptr) {
    world_ptr = w_ptr;
}
// Trace Ray
RGBColor Whitted::trace_ray(const Ray ray, const int depth) const {
    if (depth > world_ptr->vplane.max_depth) {
        return black;
    } else {
        ShadeInfo sinfo(world_ptr->hit_objects(ray));
        if (sinfo.hit) {
            sinfo.depth = depth;
            sinfo.ray = ray;
            return (sinfo.material_ptr->shade(sinfo));
        } else {
            return (world_ptr->bg_color);
        }
    }
}
