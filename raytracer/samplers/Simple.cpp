#include "Simple.hpp"
#include <vector>
// Set members.
Simple::Simple(Camera *c_ptr, ViewPlane *v_ptr) {
    camera_ptr = c_ptr;
    viewplane_ptr = v_ptr;
}
// Copy Constructor
Simple::Simple(const Simple &camera) {
    camera_ptr = camera.camera_ptr;
    viewplane_ptr = camera.viewplane_ptr;
    num_rays = camera.num_rays;
}
// Assignment operator
Simple & Simple::operator=(const Simple &other) {
    camera_ptr = other.camera_ptr;
    viewplane_ptr = other.viewplane_ptr;
    num_rays = other.num_rays;
    return (*this);
}
// Shoot a ray of weight 1 through the center of the pixel.
std::vector<Ray> Simple::get_rays(int px, int py) const {
    std::vector<Ray> RayVect;
    float t_px = px;
    float t_py = py;

    // Compute Center of the Pixel;
    t_px += 0.5;
    t_py += 0.5;
    // Compute Height & Width of the view plane
    float dW = viewplane_ptr->bottom_right.x - viewplane_ptr->top_left.x;
    float dH = viewplane_ptr->bottom_right.y - viewplane_ptr->top_left.y;
    // Compute Pixel Height & Width
    float pH = dH/ viewplane_ptr->vres;
    float pW = dW/ viewplane_ptr->hres;

    // Origin for the ray
    Point3D O;
    O.x = t_px * pW + viewplane_ptr->top_left.x;
    O.y = t_py * pH + viewplane_ptr->top_left.y;
    O.z = viewplane_ptr->top_left.z;

    // Direction for the Ray
    Vector3D d = camera_ptr->get_direction(O);

    // Intialize the Ray Object
    Ray r = Ray(O, d);

    RayVect.push_back(r);

    return RayVect;

}

