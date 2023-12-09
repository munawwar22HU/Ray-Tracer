#include "Tracer.hpp"
// Set world_ptr to NULL
Tracer::Tracer() : world_ptr{nullptr} {}
// Set world_ptr to w_ptr
Tracer::Tracer(World* w_ptr) : world_ptr{w_ptr} {}
