#include "Regular.hpp"
#include <cmath>
// Set members.
Regular::Regular(Camera *c_ptr, ViewPlane *v_ptr, int n) :
Sampler(c_ptr , v_ptr) {
    num_rays = n;
}
//  Copy constructor
Regular::Regular(const Regular &camera) :
Sampler(camera.camera_ptr , camera.viewplane_ptr) {
}
// Assingment operator
Regular& Regular::operator=(const Regular &other) {
    camera_ptr = other.camera_ptr;
    viewplane_ptr = other.viewplane_ptr;
    num_rays = other.num_rays;
    return (*this);
}
// Shoot n rays through each pixel.
std::vector<Ray> Regular::get_rays(int px, int py) const {
    std::vector<Ray> RayVect;
    int n  = (int)sqrt((float)num_rays);
    float dW = viewplane_ptr->bottom_right.x - viewplane_ptr->top_left.x;
    float dH = viewplane_ptr->bottom_right.y - viewplane_ptr->top_left.y;
    float pH = dH / viewplane_ptr->vres;
    float pW = dW / viewplane_ptr->hres;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < n; j++) {
            Point3D O;
            O.x = ((j+0.5)/n + px) * pW + viewplane_ptr->top_left.x;
            O.y = ((i+0.5)/n + py) * pH + viewplane_ptr->top_left.y;
            O.z = viewplane_ptr->top_left.z;
            Vector3D d = camera_ptr->get_direction(O);
            Ray r = Ray(O, d);
            RayVect.push_back(r);
        }
    }
    return RayVect;
}
