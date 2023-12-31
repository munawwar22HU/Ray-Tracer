#pragma once

/**
    This file caches common values and constants.

    Courtesy Kevin Suffern.
*/

#include <cstdlib>

#include "RGBColor.hpp"

// Precompute commonly used values.
const float PI = 3.1415926535897932384;
const float TWO_PI = 6.2831853071795864769;
const float PI_ON_180 = 0.0174532925199432957;
const float invPI = 0.3183098861837906715;
const float invTWO_PI = 0.1591549430918953358;

// Small and large values.
const float kEpsilon = 0.0001;
const float kHugeValue = 1.0E10;

// Some standard colors.
const RGBColor black(0.0);
const RGBColor white(1.0);
const RGBColor red(1.0, 0.0, 0.0);
const RGBColor brown(0.71, 0.40, 0.16); 
const RGBColor darkbrown(0.20, 0.13, 0.06); 
const RGBColor green(0.0, 1.0, 0.0);
const RGBColor blue(0.0, 0.0, 1.0);
const RGBColor darkgrey (0.1,0.1,0.1);
const RGBColor silver (0.458,0.458,0.458);
const RGBColor darkpurple (0.2,0.0,0.4);

// Useful for scaling the output of rand() to [0,1].
const float invRAND_MAX = 1.0 / (float)RAND_MAX;
