#include "Lambertian.hpp"

Lambertian::Lambertian() : kd(0.0) , cd(0.0) , exp(1.0) {}
Lambertian::Lambertian(const Lambertian& other) {
    kd = other.kd;
    cd = other.cd;
    exp = other.exp;
}
Lambertian* Lambertian::clone() const { return (new Lambertian(*this)); }
RGBColor Lambertian::f(const ShadeInfo& si,
const Vector3D& wo, const Vector3D& wi) const {
    return (kd * cd * invPI);
}
RGBColor
Lambertian::sample_f(const ShadeInfo& si, const Vector3D& wo,
Vector3D& wi, float& pdf) const {
    Vector3D w = si.normal;
    Vector3D v = Vector3D(0.0034, 1, 0.0071) ^ w;
    v.normalize();
    Vector3D u = v ^ w;
    Point3D sp =  BRDF::sample_hemisphere(exp);
    wi = sp.x * u + sp.y * v + sp.z * w;
    wi.normalize();
    pdf = si.normal * wi * invPI;
    return (kd * cd * invPI);
}
RGBColor Lambertian::sample_f(const ShadeInfo& si, const Vector3D& wo,
Vector3D& wi) const {
    return (kd * cd * invPI);
}
RGBColor Lambertian::rho(const ShadeInfo&si, const Vector3D&wo) const {
    return (kd * cd);
}
void Lambertian::set_ka(const float k) {
    ka = k;
}
void Lambertian::set_kd(const float k) {
    kd = k;
}

void Lambertian::set_cd(const float c) {
    cd  = RGBColor(c);
}

void Lambertian::set_cd(const float r, const float g, const float b) {
    cd  = RGBColor(r, g, b);
}

void Lambertian::set_cd(const RGBColor& c) {
    cd  = c;
}
