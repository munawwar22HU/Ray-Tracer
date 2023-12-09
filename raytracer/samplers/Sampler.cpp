#include "Sampler.hpp"
// Initializes members to NULL.
Sampler::Sampler() : camera_ptr{nullptr} ,  viewplane_ptr {nullptr} ,
num_rays{1} {}
// Set members.
Sampler::Sampler(Camera *c_ptr, ViewPlane *v_ptr) : camera_ptr{c_ptr} ,
viewplane_ptr {v_ptr} , num_rays{1} {}
// Get number of rays
int Sampler::get_num_rays() const {
    return num_rays;
}



