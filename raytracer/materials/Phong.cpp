#include "Phong.hpp"
#include "../BRDF/GlossySpecular.hpp"
#include "../BRDF/Lambertian.hpp"
#include "../lights/Light.hpp"
#include "../world/World.hpp"

// Default Constuctor
Phong::Phong() : Material(), ambient_brdf(new Lambertian),
diffuse_brdf(new Lambertian), specular_brdf(new GlossySpecular) {}
// Overload Constructor
Phong::Phong(const Phong& other) : Material() {
    if (other.ambient_brdf)
        ambient_brdf = other.ambient_brdf->clone();
    else
        ambient_brdf = NULL;
    if (other.diffuse_brdf)
        diffuse_brdf = other.diffuse_brdf->clone();
    else
        diffuse_brdf = NULL;

    if (other.specular_brdf)
        specular_brdf = other.specular_brdf->clone();
    else
        specular_brdf = NULL;
}
// Assigmnet Operator
Phong& Phong::operator=(const Phong& rhs) {
    if (this == &rhs) {
        return *this;
    }
    if (ambient_brdf) {
        delete ambient_brdf;
        ambient_brdf = NULL;
    }
    if (diffuse_brdf) {
        delete diffuse_brdf;
        diffuse_brdf = NULL;
    }
    if (specular_brdf) {
        delete specular_brdf;
        specular_brdf = NULL;
    }

    if (rhs.ambient_brdf)
        ambient_brdf = rhs.ambient_brdf->clone();
    if (rhs.diffuse_brdf)
        diffuse_brdf = rhs.diffuse_brdf->clone();
    if (rhs.specular_brdf)
        specular_brdf = rhs.specular_brdf->clone();

    return *this;
}
// Destructor
Phong::~Phong() {
    if (ambient_brdf) {
        delete ambient_brdf;
        ambient_brdf = NULL;
    }
    if (diffuse_brdf) {
        delete diffuse_brdf;
        diffuse_brdf = NULL;
    }
    if (specular_brdf) {
        delete specular_brdf;
        specular_brdf = NULL;
    }
}
// Setters
void Phong::set_ka(const float ka) {
    ambient_brdf->set_kd(ka);
}

void Phong::set_kd(const float kd) {
    diffuse_brdf->set_kd(kd);
}

void Phong::set_ks(const float ks) {
    specular_brdf->set_ks(ks);
}

void Phong::set_exp(const float exp) {
    specular_brdf->set_exp(exp);
}

void Phong::set_cd(const RGBColor c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}

void Phong::set_cd(const float r, const float g, const float b) {
    ambient_brdf->set_cd(r, g, b);
    diffuse_brdf->set_cd(r, g, b);
}

void Phong::set_cd(const float c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}
// Compute Color Shade

RGBColor Phong::shade(const ShadeInfo& sinfo) const {
    Vector3D wo = -sinfo.ray.d;
    RGBColor L = ambient_brdf->rho(sinfo, wo);
    int num_lights	= sinfo.w ->lights.size();
	
	for (int j = 0; j < num_lights; j++) {
		Vector3D wi = sinfo.w ->lights[j]->get_direction(sinfo);    
		float ndotwi = sinfo.normal * wi;
	
		if (ndotwi > 0.0) {
            bool in_shadow = false;

            if (sinfo.w->lights[j]->casts_shadow()) {
                Ray shadowRay(sinfo.hit_point, wi);
                in_shadow = sinfo.w->lights[j]->in_shadow(shadowRay, sinfo);
            }
            if (!in_shadow) {
                 L += (diffuse_brdf->f(sinfo, wo, wi) + specular_brdf->f(sinfo, wo, wi)) * sinfo.w->lights[j]->L() * ndotwi;
            }
        }
	}
    return (L);
}

// Clone Phong
Phong* Phong::clone() const {
    return (new Phong(*this));
}