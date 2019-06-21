#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape{
    public:
    Shape();
    
    virtual float area() = 0;
    virtual float volume() = 0;
};

#endif