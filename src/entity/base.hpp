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
  float velocity = 0;
  float rotationSpeed = 0;
public:
  sf::RectangleShape body;
  bool isAlive = true;

  virtual void update() = 0;

  virtual void draw(sf::RenderWindow* window) {
    window->draw(body); 
  }

  virtual void edgeCheck() {
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
