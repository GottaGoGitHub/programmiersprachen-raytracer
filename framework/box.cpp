#include <iostream>
#include <cmath>
#include <string>
#include "color.hpp"
#include "box.hpp"

Box::Box():
    Shape{},
    min_{0,0,0},
    max_{0,0,0}{}

Box::Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max):
    name_{name},
    color_{color},
    min_{min},
    max_{max}{}

std::ostream& Box::print(std::ostream& os) const
{
   return std::cout << "Name: " << name_ 
   << " Min: " << min_.x << " " << min_.y << " " << min_.z 
   << " Max: " << max_.x << " " << max_.y << " " << max_.z 
   << " Farbe: " << color_.r << " " << color_.g << " " << color_.b << std::endl;
}    


float Box::volume(){
    float a = (min_.x - max_.x) * -1;
    float b = (min_.y - max_.y) * -1;
    float c = (min_.z - max_.z) * -1;

    float volume = a * b * c;
    return volume;
}

float Box::area(){
    float a = (min_.x - max_.x) * -1;
    float b = (min_.y - max_.y) * -1;
    float c = (min_.z - max_.z) * -1;

    float area = 2 * (a * b) + 2 * (a * c) + 2 * (b * c);
    return area;
}