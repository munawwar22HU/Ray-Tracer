#include "ViewPlane.hpp"


//640 x 480 view plane at (-320, 240)
ViewPlane::ViewPlane() {
    hres = 640;
    vres = 480;
    top_left = Point3D(-320, 240, 0);
    bottom_right = Point3D(320,-240, 0);
    normal = Vector3D(0, 0, -1);
    max_depth = 0;

}

// Get/set resolution.
int ViewPlane::get_hres() const {
    return hres;
}
void ViewPlane::set_hres(int hresVal) {
    hres = hresVal;
}
int ViewPlane::get_vres() const {
    return vres;
}
void ViewPlane::set_vres(int vresVal) {
    vres = vresVal;
}
void ViewPlane::set_max_depth(int d) {
    max_depth = d;
}
