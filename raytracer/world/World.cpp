#include "World.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "../utilities/BBox.hpp"
#include "../geometry/Geometry.hpp"
#include "../geometry/Triangle.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../acceleration/Acceleration.hpp"
#include "../tracers/Tracer.hpp"
#include "../lights/Ambient.hpp"
#include "../samplers/Sampler.hpp"
#include "../cameras/Camera.hpp"
#include "../happly/happly.h"

using namespace std;

// initialize members.
World::World() : vplane{} , bg_color{}, camera_ptr{nullptr},
acceleration_ptr{nullptr} , sampler_ptr{nullptr}, tracer_ptr{nullptr},
ambient_ptr{new Ambient} {};

// Destructor.
World::~World() {
    delete camera_ptr;
    delete sampler_ptr;
    delete tracer_ptr;
    delete ambient_ptr;
    for (int i = 0; i < geometry.size(); i++) {
        delete geometry[i];
    }
    for (int i = 0; i < lights.size(); i++) {
        delete lights[i];
    }
}
// Add to the scene.
void World::add_geometry(Geometry *geom_ptr) {
    geometry.push_back(geom_ptr);
}
void World::add_light(Light* light_ptr) {
    lights.push_back(light_ptr);
}
void World::set_camera(Camera *c_ptr) {
    camera_ptr = c_ptr;
}

void World::set_tracer(Tracer *t_ptr) {
    tracer_ptr = t_ptr;
}
void World::set_acceleration(Acceleration* accel_ptr) {
    acceleration_ptr = accel_ptr;
}
void World::set_ambient_light(Ambient* amb_ptr) {
    if (ambient_ptr) {
        delete ambient_ptr;
    }
    ambient_ptr = amb_ptr->clone();
}
// Returns appropriate shading information corresponding to intersection of
// the ray with the scene geometry.
ShadeInfo World::hit_objects(const Ray &ray) {

    if (acceleration_ptr != NULL){
        return acceleration_ptr->hit(ray);
    }

    ShadeInfo s(*this);
    float t = kHugeValue;
    int num_objects = geometry.size();
    for (int i = 0; i < num_objects; i++) {
        float temp_t;
        ShadeInfo temp_s(*this);
        bool hit = geometry[i]->hit(ray, temp_t, temp_s);
        if (hit) {
            if (temp_t < t) {
                t = temp_t;
                s = temp_s;
            }
        }
    }
    return s;
}



void World::LoadMesh(std::string filename, Material* m_ptr, Point3D pmin, Point3D pmax) {

    // Read File
    happly::PLYData plyIn(filename);
    // Initialize Vertices
    std::vector<array<double, 3>> Vertics = plyIn.getVertexPositions();
    std::vector<vector<size_t>> Faces = plyIn.getFaceIndices<size_t>();
    std::vector<Point3D> Points;

    Point3D modelMin(Vertics[0][0], Vertics[0][1], Vertics[0][2]);
    Point3D modelMax(Vertics[0][0], Vertics[0][1], Vertics[0][2]);
   
    // Traverse Vertices
    for (const auto& i : Vertics) {
        Point3D obj(i[0], i[1], i[2]);
        Points.push_back(obj);
        modelMin = min(modelMin, obj);
        modelMax = max(modelMax, obj);
    }
    // Interpolate Points
    for (auto& p: Points) {
        p = Point3D::interpolate(modelMin, modelMax, p, pmin, pmax);
    }
    // Traverse Faces
    for (const auto& f : Faces) {
     
      Triangle* TriangleMesh = new Triangle(Points[f[0]], Points[f[1]], Points[f[2]]);
      TriangleMesh->set_material(m_ptr);
      add_geometry(TriangleMesh);
    }
    
}