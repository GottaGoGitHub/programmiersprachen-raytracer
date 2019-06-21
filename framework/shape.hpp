#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "color.hpp"

class Shape{
    public:
    Shape();
    Shape(std::string const& name, Color const& color);
    
    virtual float area(void) = 0;
    virtual float volume(void) = 0;

    protected:
    std::string name_;
    Color color_;
};

#endif