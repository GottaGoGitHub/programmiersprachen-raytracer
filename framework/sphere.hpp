#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <string>
#include "shape.hpp"
#include "color.hpp"
#include "hitpoint.hpp"
#include "ray.hpp"


class Sphere: public Shape{
    public:
    virtual float area() override;
    virtual float volume() override;
    virtual std::ostream& print(std::ostream& os)const override;

    HitPoint intersect(Ray ray);

    Sphere();
    Sphere(std::string const& name, Color const& color, glm::vec3 const& center, float const& radius);
    ~Sphere();

    private:
    glm::vec3 center_;
    float radius_;
    Color color_;
    std::string name_;
};



#endif