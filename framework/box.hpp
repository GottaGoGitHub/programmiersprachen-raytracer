#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"
#include <string>
#include "color.hpp"

class Box: public Shape{
    public:
    virtual float area() override;
    virtual float volume() override;
    virtual std::ostream& print(std::ostream& os)const override;

    Box();
    Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max);
    ~Box();

    private:
    glm::vec3 min_;
    glm::vec3 max_;
    std::string name_;
    Color color_;
};

#endif