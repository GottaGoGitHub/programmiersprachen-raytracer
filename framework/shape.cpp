#include "shape.hpp"

Shape::Shape():
    name_{"NULL"},
    color_{}{}

Shape::Shape(std::string const& name, Color const& color):
    name_{name},
    color_{color}{}

