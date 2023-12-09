#include "Matte.hpp"


Matte::Matte() : Material() , ambient_brdf(new Lambertian),
diffuse_brdf(new Lambertian) {}

Matte::Matte(const Matte& other) : Material(other) {
    if (other.ambient_brdf)
        ambient_brdf = other.ambient_brdf->clone();
    else
        ambient_brdf = nullptr;

    if (other.diffuse_brdf)
        diffuse_brdf = other.diffuse_brdf->clone();
    else
        diffuse_brdf = nullptr;
}


Matte& Matte::operator=(const Matte& other) {
    if (this == &other) {
        return (*this);
    }
    Material::operator=(other);
    if (ambient_brdf) {
        delete ambient_brdf;
        ambient_brdf = NULL;
    }
    if (other.ambient_brdf)
        ambient_brdf = other.ambient_brdf->clone();
    if (diffuse_brdf) {
        delete diffuse_brdf;
        diffuse_brdf = NULL;
    }
    if (other.diffuse_brdf)
        diffuse_brdf = other.diffuse_brdf->clone();
    return (*this);
}

Matte::~Matte() {
    if (ambient_brdf) {
        delete ambient_brdf;
        ambient_brdf = NULL;
    }
    if (diffuse_brdf) {
        delete diffuse_brdf;
        diffuse_brdf = NULL;
    }
}
void Matte::set_ka(const float ka) {
    ambient_brdf->set_kd(ka);
}

void Matte::set_kd(const float kd) {
    diffuse_brdf->set_kd(kd);
}


void Matte::set_cd(const RGBColor c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}
void Matte::set_cd(const float r, const float g, const float b) {
    ambient_brdf->set_cd(r, g, b);
    diffuse_brdf->set_cd(r, g, b);
}

void Matte::set_cd(const float c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}


RGBColor Matte::shade(const ShadeInfo& sinfo) const {
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
                 L += diffuse_brdf->f(sinfo, wo, wi) * sinfo.w->lights[j]->L() * ndotwi;
            }
        }
	}
    return (L);
}
Matte* Matte::clone() const {
    return (new Matte(*this));
}



