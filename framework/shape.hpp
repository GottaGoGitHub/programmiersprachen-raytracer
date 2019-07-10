#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "color.hpp"
#include "material.hpp"
#include "hitpoint.hpp"
#include "ray.hpp"
class Shape{
    public:
    Shape();
    Shape(std::string const& name, Material const& mat);
    
    virtual float area(void) = 0;
    virtual float volume(void) = 0;
    virtual HitPoint intersect(Ray ray) = 0;
    virtual std::ostream& print(std::ostream& os) const;

    virtual ~Shape();

    protected:
    std::string name_;
    Material material_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif