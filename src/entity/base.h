#define MAX_SPEED 3

#include <SFML/Graphics.hpp>

class Entity {
protected:
  float x, y;
  float vel_x, vel_y;
public:
  sf::RectangleShape body;
  virtual void move() = 0;
};
