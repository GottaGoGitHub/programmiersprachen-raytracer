#include "sphere.hpp"
#include <iostream>
#include <math.h>

Sphere::Sphere():
    Shape{},
    center_{0,0,0},
    radius_{0}{}

Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float const& radius):
    name_{name},
    color_{color},
    center_{center},
    radius_{radius}{}

std::ostream& Sphere::print(std::ostream& os) const
{
    return os << "Name: " << name_ << " Center: " << center_.x << " " << center_.y << " " << center_.z 
    << " Radius: " << radius_ 
    << " Farbe: " << color_.r << " " << color_.g << " " << color_.b << std::endl;
}

HitPoint Sphere::intersect(Ray ray){

    HitPoint hitpoint;
    Ray norm;
    norm.direction = glm::normalize(ray.direction);
    float distance = 0.0f;

    hitpoint.gotHit = glm::intersectRaySphere(ray.origin, norm.direction, center_, radius_ * radius_, distance);
    hitpoint.name = name_;
    hitpoint.color = color_;
    hitpoint.distance = distance;

    return hitpoint;
}


float Sphere::volume(){
    float volume = 1.3333 * M_PI * pow(radius_, 3);
    return volume;
}

float Sphere::area(){
    float area = 4 * M_PI * pow(radius_, 2);
    return area;
}