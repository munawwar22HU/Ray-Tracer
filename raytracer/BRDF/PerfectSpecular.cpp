#include "PerfectSpecular.hpp"

PerfectSpecular::PerfectSpecular() : kr(0.0), cr(1.0) {}

PerfectSpecular::PerfectSpecular(const PerfectSpecular& other) {
   
    kr  = other.kr;
    cr = other.cr;
}

PerfectSpecular* PerfectSpecular::clone() const {
    return (new PerfectSpecular(*this));
}

RGBColor PerfectSpecular::f(const ShadeInfo&,
const Vector3D& wi, const Vector3D& wo) const {
    return black;
}

RGBColor PerfectSpecular::sample_f(const ShadeInfo& si,
const Vector3D& wo, Vector3D& wi, float& pdf) const {
    float ndotwo = si.normal * wo;
    wi = -wo + 2.0 * si.normal * ndotwo;
    pdf = fabs(si.normal * wi);
    return (kr * cr);
}
RGBColor PerfectSpecular::sample_f(const ShadeInfo& si,
const Vector3D& wo, Vector3D& wi) const {
    float ndotwo = si.normal * wo;
    wi = -wo + 2.0 * si.normal * ndotwo;
    return (kr * cr / fabs(si.normal * wi));
}

RGBColor PerfectSpecular::rho(const ShadeInfo&, const Vector3D&) const {
    return black;
}

void PerfectSpecular::set_kr(const float k) {
    kr = k;
}
void PerfectSpecular::set_cr(const RGBColor& c) {
    cr = c;
}

void PerfectSpecular::set_cr(const float r, const float g, const float b) {
    cr = RGBColor(r, g, b);
}

void PerfectSpecular::set_cr(const float c) {
    cr = RGBColor(c);
}
