#ifndef BASE_HPP
#define BASE_HPP

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
