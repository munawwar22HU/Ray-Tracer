#include "Geometry.hpp"
// sets material_ptr to NULL.
Geometry::Geometry() : material_ptr {nullptr} {}

// Get/set material.
Material* Geometry::get_material() const {
    return material_ptr;
}
void Geometry::set_material(Material *mPtr) {
    material_ptr = mPtr;
}
