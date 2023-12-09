#include "Basic.hpp"
// Set world_ptr to NULL
Basic::Basic() {
    world_ptr = nullptr;
}
// Set world_ptr to w_ptr
Basic::Basic(World* w_ptr) {
    world_ptr = w_ptr;
}
// Trace Ray
RGBColor Basic::trace_ray(const Ray ray, const int depth) const {
    ShadeInfo sinfo = world_ptr->hit_objects(ray);
    if (sinfo.hit) {
        return  ray.w * sinfo.material_ptr->shade(sinfo);
    } else {
        return ray.w * world_ptr->bg_color;
    }
}
