#ifndef BASE_HPP
#define BASE_HPP

#define DEGREES_TO_RADIANS(x) (x * M_PI / 180.0)
#define RADIANS_TO_DEGREES(x) (x / M_PI * 180.0)
#define X(v, deg) (v * std::cos(DEGREES_TO_RADIANS(deg)))
#define Y(v, deg) (v * std::sin(DEGREES_TO_RADIANS(deg)))

#include <math.h>
#include <SFML/Graphics.hpp>
#include "../lib/const.hpp"

class Entity {
protected:
  float vel = 0;
  float vel_rotation = 0;
public:
  sf::RectangleShape body;
  virtual void update() = 0;
  virtual void edge_check() {
    auto position = body.getPosition();
    if(position.x < LEFT_LIMIT)
      body.move(sf::Vector2f(RIGHT_LIMIT+CHARACTER_WIDTH, 0));
    if(position.x > RIGHT_LIMIT)
      body.move(sf::Vector2f(-(RIGHT_LIMIT+CHARACTER_WIDTH), 0));
    if(position.y < UPPER_LIMIT)
      body.move(sf::Vector2f(0, LOWER_LIMIT+CHARACTER_WIDTH));
    if(position.y > LOWER_LIMIT)
      body.move(sf::Vector2f(0, -(LOWER_LIMIT+CHARACTER_WIDTH)));
  }
};

#endif // !BASE_HPP
