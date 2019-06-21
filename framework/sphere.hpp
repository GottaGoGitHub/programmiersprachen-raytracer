#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <string>
#include "shape.hpp"
#include "color.hpp"


class Sphere: public Shape{
    public:
    virtual float area() override;
    virtual float volume() override;

    Sphere();
    Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float const& radius);

    private:
    glm::vec3 center_;
    float radius_;
    Color color_;
    std::string name_;
};

#endif