#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "hitpoint.hpp"
#include "color.hpp"
#include "box.hpp"

Box::Box():
    Shape{},
    min_{0,0,0},
    max_{0,0,0}{}

Box::Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max):
    name_{name},
    material_{mat},
    min_{min},
    max_{max}{}

Box::~Box(){
    std::cout << "Box destructor" << std::endl;    
}    

std::ostream& Box::print(std::ostream& os) const
{
   Shape::print(os);
   return std::cout 
   << " Min: " << min_.x << " " << min_.y << " " << min_.z 
   << " Max: " << max_.x << " " << max_.y << " " << max_.z << std::endl;
}    

std::ostream& operator<<(std::ostream& os, Box const& b){
    return b.print(os);
}

HitPoint Box::intersect(Ray r){
    Ray n{r};
    HitPoint hit{};
    bool gothit = false;

    float t = (min_.x-n.origin.x)/(glm::normalize(n.direction)).x;
    glm::vec3 p_x = n.origin + t*(glm::normalize(n.direction)); 
    
    if(p_x.y <= max_.y && p_x.y >= min_.y
    && p_x.z <= max_.z && p_x.z >= min_.z){
        gothit = true;
    }

    float t_max_x = (max_.x-n.origin.x)/(glm::normalize(n.direction)).x;
    glm::vec3 p_x2 = n.origin + t_max_x*(glm::normalize(n.direction)); 
    
    if(p_x2.y <= max_.y && p_x2.y >= min_.y
    && p_x2.z <= max_.z && p_x2.z >= min_.z){
        gothit = true;
    }

    float t_min_y = (min_.y-n.origin.y)/(glm::normalize(n.direction)).y;
    glm::vec3 p_y = n.origin + t_min_y*(glm::normalize(n.direction)); 
    
    if(p_y.x <= max_.x && p_y.x >= min_.x
    && p_y.z <= max_.z && p_y.z >= min_.z){
        gothit = true;
    }

    float t_max_y = (max_.y-n.origin.y)/(glm::normalize(n.direction)).y;
    glm::vec3 p_y2 = n.origin + t_max_y*(glm::normalize(n.direction)); 
    
    if(p_y2.x <= max_.x && p_y2.x >= min_.x
    && p_y2.z <= max_.z && p_y2.z >= min_.z){
        gothit = true;
    }
    
    float t_min_z = (min_.z-n.origin.z)/(glm::normalize(n.direction)).z;
    glm::vec3 p_z = n.origin + t_min_z*(glm::normalize(n.direction)); 
    
    if(p_z.y <= max_.y && p_z.y >= min_.y
    && p_z.x <= max_.x && p_z.x >= min_.x){
        gothit = true;
    }

    float t_max_z = (max_.z-n.origin.z)/(glm::normalize(n.direction)).z;
    glm::vec3 p_z2 = n.origin + t_max_z*(glm::normalize(n.direction)); 
    
    if(p_z2.y <= max_.y && p_z2.y >= min_.y
    && p_z2.x <= max_.x && p_z2.x >= min_.x){
        gothit = true;
    }
    

    if (gothit == true){
       hit.gotHit= true;
       hit.direction = n.direction;
       hit.distance = t;
       hit.name = name_;
       hit.hitpoint = p_x;
    }
return hit;
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