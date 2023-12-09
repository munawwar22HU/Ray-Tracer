#include "ShadeInfo.hpp"

// set the world.
ShadeInfo::ShadeInfo(const World& wr) : hit {false}, hit_point{},
normal{}, ray{}, depth{0}, t{kEpsilon}, w{&wr} {}




