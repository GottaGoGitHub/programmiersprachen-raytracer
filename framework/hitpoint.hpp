#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <string>
#include <glm/vec3.hpp>
#include <iostream>
#include "color.hpp"

struct HitPoint{

    bool gotHit;
    float distance;
    std::string name;
    Color color;

};

#endif