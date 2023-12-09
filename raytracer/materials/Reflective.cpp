#include "Reflective.hpp"
#include <iostream>
#include "../BRDF/PerfectSpecular.hpp"
#include "../BRDF/GlossySpecular.hpp"
#include "../BRDF/Lambertian.hpp"
#include "../lights/Light.hpp"
#include "../tracers/Tracer.hpp"
#include "../world/World.hpp"

Reflective::Reflective(void) : Material(), reflective_brdf(new PerfectSpecular) ,
ambient_brdf(new Lambertian), diffuse_brdf(new Lambertian), specular_brdf(new GlossySpecular) {}


Reflective::Reflective(const Reflective& other) : Material() {
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
    if (other.reflective_brdf)
        reflective_brdf = other.reflective_brdf->clone();
    else
        reflective_brdf = NULL;
}

Reflective& Reflective::operator=(const Reflective& rhs) {
    if (this == &rhs)
		return (*this);

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
    if (reflective_brdf) {
        delete reflective_brdf;
        reflective_brdf = NULL;
    }
    if (rhs.reflective_brdf)
        reflective_brdf = rhs.reflective_brdf->clone();
    if (rhs.ambient_brdf)
        ambient_brdf = rhs.ambient_brdf->clone();
    if (rhs.diffuse_brdf)
        diffuse_brdf = rhs.diffuse_brdf->clone();
    if (rhs.specular_brdf)
        specular_brdf = rhs.specular_brdf->clone();
    return (*this);
}
Reflective* Reflective::clone () const {
    return new Reflective(*this);
}

Reflective::~Reflective(void) {
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
    if (reflective_brdf) {
        delete reflective_brdf;
        reflective_brdf = NULL;
    }
}

void Reflective::set_kr(const float k) {
    reflective_brdf->set_kr(k);
}

void Reflective::set_cr(const RGBColor& c) {
    reflective_brdf->set_cr(c);
}

void Reflective::set_cr(const float r, const float g, const float b) {
    reflective_brdf->set_cr(r, g, b);
}

void Reflective::set_cr(const float c) {
    reflective_brdf->set_cr(c);
}
void Reflective::set_ka(const float ka) {
    ambient_brdf->set_kd(ka);
}

void Reflective::set_kd(const float kd) {
    diffuse_brdf->set_kd(kd);
}

void Reflective::set_ks(const float ks) {
    specular_brdf->set_ks(ks);
}

void Reflective::set_exp(const float exp) {
    specular_brdf->set_exp(exp);
}

void Reflective::set_cd(const RGBColor c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}

void Reflective::set_cd(const float r, const float g, const float b) {
    ambient_brdf->set_cd(r, g, b);
    diffuse_brdf->set_cd(r, g, b);
}

void Reflective::set_cd(const float c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}
RGBColor Reflective::shade(const ShadeInfo& sinfo) const {
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
    Vector3D wi;
    RGBColor fr = reflective_brdf->sample_f(sinfo, wo, wi);
    Ray reflected_ray(sinfo.hit_point, wi);
    reflected_ray.w = sinfo.depth + 1;
    L += fr * sinfo.w->tracer_ptr->trace_ray(reflected_ray, sinfo.depth + 1) * (sinfo.normal * wi);

    return L;
}