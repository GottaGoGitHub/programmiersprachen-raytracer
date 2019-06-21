#include "sphere.hpp"
#include <iostream>
#include <math.h>

Sphere::Sphere():
    Shape{},
    center_{0,0,0},
    radius_{0}{}

Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float const& radius):
    Shape{name, color},
    center_{center},
    radius_{radius}{}


float Sphere::volume(){
    float volume = 1.3333 * M_PI * pow(radius_, 3);
    return volume;
}

float Sphere::area(){
    float area = 4 * M_PI * pow(radius_, 2);
    return area;
}