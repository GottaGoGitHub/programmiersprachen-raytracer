#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <iostream>
#include <string>
#include "color.hpp"
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"

TEST_CASE("sphere"){
  glm::vec3 center{20, 20, 20};
  float radius = 3;
  Color color{0.2, 0.2, 0.8};
  Sphere sphere{"Karsten", color, center, radius};

  REQUIRE(sphere.area() == Approx(113.09734f));
  REQUIRE(sphere.volume() == Approx(113.09451f));
}

TEST_CASE("box"){
  glm::vec3 min{0,0,0};
  glm::vec3 max{5,5,5};
  Color color{0.2,0.2,0.8};
  Box box{"Horst", color, min, max};

  REQUIRE(box.area() == 150);
  REQUIRE(box.volume() == 125);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
