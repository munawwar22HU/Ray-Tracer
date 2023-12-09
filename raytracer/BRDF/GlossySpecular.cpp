#include "BRDF.hpp"
#include "GlossySpecular.hpp"

GlossySpecular::GlossySpecular() : ks(0.0) , cs(1.0) , exp(3.0) {}
GlossySpecular::GlossySpecular(const GlossySpecular& other) {
    ks = other.ks;
    cs = other.ks;
    exp = other.ks;
}
GlossySpecular* GlossySpecular::clone() const {
    return  (new GlossySpecular(*this));
}
// Direct Illumination
RGBColor GlossySpecular::f(const ShadeInfo& si, const Vector3D& wo,
const Vector3D& wi) const {
        RGBColor L;
        float ndotwi = si.normal * wi;
        // mirror reflection direction
        Vector3D r(-wi + 2.0 * si.normal * ndotwi);
        float rdotwo = r * wo;
        if (rdotwo > 0.0)
            L = ks * cs * pow(rdotwo, exp);
        return L;
}
// this is used for indirect illumination
RGBColor GlossySpecular::sample_f(const ShadeInfo& si,
const Vector3D& wo, Vector3D& wi, float& pdf) const {
    float ndotwo = si.normal * wo;
    // direction of mirror reflection
    Vector3D r = -wo + 2.0 * si.normal * ndotwo;
    Vector3D w = r;
    Vector3D u = Vector3D(0.00424, 1, 0.00764) ^ w;
    u.normalize();
    Vector3D v = u ^ w;
    Point3D sp = BRDF::sample_hemisphere(exp);
    // reflected ray direction
    wi = sp.x * u + sp.y * v + sp.z * w;
    // reflected ray is below tangent plane
    if (si.normal * wi < 0.0)
        wi = -sp.x * u - sp.y * v + sp.z * w;
    float phong_lobe = pow(r * wi, exp);
    pdf = phong_lobe * (si.normal * wi);
    return (ks * cs * phong_lobe);
}

RGBColor GlossySpecular::sample_f(const ShadeInfo& si,
const Vector3D& wo, Vector3D& wi) const {
    float ndotwo = si.normal * wo;
    // direction of mirror reflection
    Vector3D r = -wo + 2.0 * si.normal * ndotwo;
    Vector3D w = r;
    Vector3D u = Vector3D(0.00424, 1, 0.00764) ^ w;
    u.normalize();
    Vector3D v = u ^ w;
    Point3D sp = BRDF::sample_hemisphere(exp);
    // reflected ray direction
    wi = sp.x * u + sp.y * v + sp.z * w;
    // reflected ray is below tangent plane
    if (si.normal * wi < 0.0)
        wi = -sp.x * u - sp.y * v + sp.z * w;
    float phong_lobe = pow(r * wi, exp);
    return (ks * cs * phong_lobe * (si.normal * wi));
}

RGBColor GlossySpecular::rho(const ShadeInfo& si, const Vector3D& wo) const {
    return (black);
}

void GlossySpecular::set_ks(const float k) {
    ks = k;
}
void GlossySpecular::set_exp(const float e) {
    exp = e;
}
void GlossySpecular::set_cs(const RGBColor& c) {
    cs = c;
}
void GlossySpecular::set_cs(const float r, const float g, const float b) {
    cs = RGBColor(r, g, b);
}
void GlossySpecular::set_cs(const float c) {
    cs = RGBColor(c);
}