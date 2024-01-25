#ifndef BASE_HPP
#define BASE_HPP

#define DEGREES_TO_RADIANS(x) (x * M_PI / 180.0)
#define X(v, deg) (v * std::cos(DEGREES_TO_RADIANS(deg)))
#define Y(v, deg) (v * std::sin(DEGREES_TO_RADIANS(deg)))

#include <math.h>
#include <SFML/Graphics.hpp>

class Entity {
protected:
  float vel = 0;
  float vel_rotation = 0;
public:
  sf::RectangleShape body;
  virtual void update() = 0;
};

#endif // !BASE_HPP
