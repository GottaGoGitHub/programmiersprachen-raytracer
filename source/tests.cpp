#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <iostream>
#include <string>
#include "color.hpp"
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "material.hpp"

TEST_CASE("sphere"){
  glm::vec3 center{20, 20, 20};
  float radius = 3;
  Material mat{};
  Sphere sphere{"Karsten", mat, center, radius};

  REQUIRE(sphere.area() == Approx(113.09734f));
  REQUIRE(sphere.volume() == Approx(113.09451f));

  std::cout << sphere << std::endl;
}

TEST_CASE("box"){
  glm::vec3 min{0,0,0};
  glm::vec3 max{5,5,5};
  Material mat{};
  Box box{"Horst", mat, min, max};

  REQUIRE(box.area() == 150);
  REQUIRE(box.volume() == 125);

  std::cout << box << std::endl;
}

TEST_CASE("intersect_ray_sphere" , "[intersect]"){

  // Ray
  glm::vec3 ray_origin {0.0f, 0.0f, 0.0f};
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};

  // Sphere
  glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
  float sphere_radius{1.0f};
  float distance = 0.0f;
  auto result = glm::intersectRaySphere(ray_origin, ray_direction, sphere_center,
  sphere_radius * sphere_radius, distance);
  REQUIRE (distance == Approx (4.0f));
}

TEST_CASE("intersect_ray_box", "[intersect]"){
  Box box{"Kai_Uwe", Material{}, glm::vec3{2,2,2}, glm::vec3{10,10,10}};

  Ray ray1{glm::vec3{0.0f,0.0f,0.0f}, glm::vec3{1.0f, 1.0f, 1.0f}};
  Ray ray2{glm::vec3{0.0f,0.0f,0.0f}, glm::vec3{0.0f, -1.0f, 0.0f}};

  HitPoint hit = box.intersect(ray1);
  HitPoint nohit = box.intersect(ray2); 

  REQUIRE(hit.gotHit == true);
  REQUIRE(hit.name == "Kai_Uwe");
  REQUIRE(nohit.gotHit == false);
  REQUIRE(nohit.name == "");
}

TEST_CASE("custom_intersect_test", "[intersect]"){
  Material mat{};
  glm::vec3 center1{10, 3, 1};
  Ray ray;

  Sphere sphere{"Inge", mat, center1, 1.0f};
  HitPoint hitpoint1 = sphere.intersect(ray);

  if(hitpoint1.gotHit == true)
  {
    std::cout << "Ray schneidet die Kugel" << std::endl;
    std::cout << " Name: " << hitpoint1.name 
              //<< " Color: " << hitpoint1.color 
              << " Distanz: " << hitpoint1.distance << std::endl;
  }
  else{
    std::cout << "Ray schneidet nicht die Kugel" << std::endl;
  }

  glm::vec3 center2{5, 5 ,-5};

  Sphere sphere2{"Karl", mat, center2, 10.0f};
  HitPoint hitpoint2 = sphere2.intersect(ray);

  if(hitpoint2.gotHit == true)
  {
    std::cout << "Ray schneidet die Kugel" << std::endl;
    std::cout << " Name: " << hitpoint2.name 
              //<< " Color: " << hitpoint2.color 
              << " Distanz: " << hitpoint2.distance << std::endl;
  }
  else{
    std::cout << "Ray schneidet nicht die Kugel" << std::endl;
  }
}

TEST_CASE("Aufgabe 5.8", "Shape") {
    Material mat;;
    glm::vec3 position{0.0f, 3.4f, 0.0f};
    Sphere *s1 = new Sphere{"die1", mat, position, 1.2f};
    Shape *s2 = new Sphere{"die2", mat ,position, 1.2f};
    s1->print(std::cout);
    std::cout << "--------------------------" << std::endl;
    std::cout << *s1 << std::endl;
    std::cout << "--------------------------" << std::endl;
    s2->print(std::cout);
    std::cout << "--------------------------" << std::endl;
    delete s1;
    std::cout << "--------------------------" << std::endl;
    delete s2;
    std::cout << "--------------------------" << std::endl;
}

/* entfernt man das virtual von der basisklasse, wird beim zweiten aufruf nur der Shape
   Destruktor und nicht der Sphere Destruktor verwendet */

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

/*
Bei der statischen Typisierung wird im Gegensatz zur dynamischen Typisierung der Datentyp
von Variablen und anderen Programmbausteinen schon während der Kompilierung festgelegt.
Dies kann durch Typinferenz oder durch explizite Deklaration geschehen. 
Statische Typisierung kann durch starke Typisierung erweitert werden.

Bei der dynamischen Typisierung finden Typ-Prüfungen (etwa des Datentyps von Variablen) 
vorrangig zur Laufzeit eines Programms statt.
 */