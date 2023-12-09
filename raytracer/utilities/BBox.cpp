#include <sstream>
#include <cmath>
#include <string>
#include "BBox.hpp"

// set points.
BBox::BBox(const Point3D& min, const Point3D &max) : pmin{min}  , pmax{max} {}

// String representation.
std::string BBox::to_string() const {
    std::stringstream ss;
    ss << "Pmin : " << pmin.to_string() << " Pmax : " << pmax.to_string();
    return ss.str();
}

// Does ray hit bbox? If so, set entering and leaving t values for ray.
// Code adapted from Listing 19.1
bool BBox::hit(const Ray &ray, float &t_enter, float &t_exit) const {
    double ox = ray.o.x;
    double oy = ray.o.y;
    double oz = ray.o.z;
    double dx = ray.d.x;
    double dy = ray.d.y;
    double dz = ray.d.z;
    double tx_min, ty_min, tz_min;
    double tx_max, ty_max, tz_max;

    double a = 1.0 / dx;
    if (a >= 0) {
        tx_min = (pmin.x - ox) * a;
        tx_max = (pmax.x - ox) * a;
    } else {
        tx_min = (pmax.x - ox) * a;
        tx_max = (pmin.x - ox) * a;
    }

    double b = 1.0 / dy;
    if (b >= 0) {
        ty_min = (pmin.y - oy) * b;
        ty_max = (pmax.y - oy) * b;
    } else {
        ty_min = (pmax.y - oy) * b;
        ty_max = (pmin.y - oy) * b;
    }

    double c = 1.0 / dz;
    if (c >= 0) {
       tz_min = (pmin.z - oz) * c;
       tz_max = (pmax.z - oz) * c;
    } else {
       tz_min = (pmax.z - oz) * c;
       tz_max = (pmin.z - oz) * c;
    }

    t_enter = std::max(std::max(tx_min, ty_min), tz_min);
    t_exit = std::min(std::min(tx_max, ty_max), tz_max);

    return ((t_enter < t_exit) && (t_exit > kEpsilon));
}
// Extend this bbox, if necessary, to include g or b.
void BBox::extend(Geometry* g) {
    this->extend(g->getBBox());
}

void BBox::extend(const BBox &b) {
    this->pmin = min(b.pmin, pmin);
    this->pmax = max(b.pmax, pmax);
}

// Does this BBox contain p? True even when p lies on a boundary.
bool BBox::contains(const Point3D& p) {
    return ((p.x >= pmin.x && p.x <= pmax.x)
    && (p.y >= pmin.y && p.y <= pmax.y)
    && (p.z >= pmin.z && p.z <= pmax.z));
}
// Does this BBox overlap with g or b?
bool BBox::overlaps(Geometry *g) {
    return this->overlaps(g->getBBox());
}
bool BBox::overlaps(const BBox &b) {
    return ((pmax.x > b.pmin.x) && (pmax.y > b.pmin.y) && (pmax.z > b.pmin.z));
}

// For BVH
void BBox::extend(const Point3D& p) {
    this->pmin = min(pmin, p);
    this->pmax = max(pmax, p);
    this->delta = pmax - pmin;
}



int BBox::maxDimension() const {
    if (delta.x > delta.y) {
        if (delta.x > delta.z) return 0;
        return 2;
    }
    if (delta.y > delta.z) return 1;
    return 2;
}

Vector3D BBox::getExtent() const {
    return delta;
}