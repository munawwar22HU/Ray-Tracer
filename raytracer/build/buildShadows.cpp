#include "../cameras/Perspective.hpp"
#include "../cameras/Parallel.hpp"
#include "../geometry/Plane.hpp"
#include "../geometry/Sphere.hpp"
#include "../geometry/Triangle.hpp"
#include "../tracers/Basic.hpp"
#include "../tracers/Whitted.hpp"
#include "../lights/Ambient.hpp"
#include "../lights/Point.hpp"
#include "../materials/Cosine.hpp"
#include "../materials/Matte.hpp"
#include "../materials/Reflective.hpp"
#include "../materials/Phong.hpp"
#include "../samplers/Simple.hpp"
#include "../samplers/Regular.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Vector3D.hpp"
#include "../lights/Directional.hpp"
#include "../lights/Point.hpp"
#include "../lights/Spotlight.hpp"
#include "../lights/Light.hpp"
#include "../world/World.hpp"

void 												
World::build(void) {
     

    vplane.top_left.x = -10;
    vplane.top_left.y = 10;
    vplane.top_left.z = 10;
    vplane.bottom_right.x = 10;
    vplane.bottom_right.y = -10;
    vplane.bottom_right.z = 10;
    vplane.hres = 2000;
    vplane.vres = 2000;
	vplane.set_max_depth(1); 

    set_camera(new Perspective(0,0,30));
    set_tracer(new Whitted(this));
    sampler_ptr = new Simple(camera_ptr, &vplane);


	Directional* light_ptr1 = new Directional;
	light_ptr1->set_direction(200,150,125); 
	light_ptr1->set_shadows(true);
	add_light(light_ptr1);
		
	// Point* light_ptr2 = new Point();
	// light_ptr2->set_location(-12, 15, 30); 
	// light_ptr2->scale_radiance(4.0);
    // light_ptr2->set_shadows(true);			
	// add_light(light_ptr2);

	// Spotlight* light_ptr3 = new Spotlight();
    // light_ptr3->set_location(0,1,0);
    // light_ptr3->set_direction(0 ,1, 0);
    // light_ptr3->scale_radiance(3.0);
    // light_ptr3->set_shadows(true);
    // light_ptr3->set_theta(0.7825);
    // add_light(light_ptr3);


		
	// sphere
	Matte* matte_ptr1 = new Matte();			
	matte_ptr1->set_ka(0.3); 
	matte_ptr1->set_kd(0.3);
	matte_ptr1->set_cd(0.5, 0.6, 0); 
	
	//Sphere*	sphere_ptr = new Sphere(Point3D(0.0, 2.4, 0), 5); 
    Sphere* sphere_ptr = new Sphere(Point3D(-3, 2, 0), 5); 
	sphere_ptr->set_material(matte_ptr1);
	add_geometry(sphere_ptr);	
	

	// triangle
	
	Matte* matte_ptr3 = new Matte();			
	matte_ptr3->set_ka(0.35); 
	matte_ptr3->set_kd(0.50);
	matte_ptr3->set_cd(0, 0.5, 0.5);      // cyan
    Point3D a(2.5, -5, 1); 
    Point3D b(14, -1, 0); 
    Point3D c(8.5, 5, 0.5); 
    Triangle* triangle_ptr = new Triangle(a, b, c);							
	triangle_ptr->set_material(matte_ptr3);        
	add_geometry(triangle_ptr);
		

	// ground plane

	Matte* matte_ptr4 = new Matte();			
	matte_ptr4->set_ka(0.1); 
	matte_ptr4->set_kd(0.2);
	matte_ptr4->set_cd(white);

	

	
    //Plane* plane_ptr = new Plane(Point3D(0,5,0), Vector3D(0, 10, 2)); 
    Plane* plane_ptr = new Plane(Point3D(0,-5,0), Vector3D(0, 10, 2));
	plane_ptr->set_material(matte_ptr4);
	add_geometry(plane_ptr);
}


