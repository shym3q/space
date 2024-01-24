#include <SFML/Graphics.hpp>

class Entity {
protected:
  float x, y;
  float vel;
  float vel_x, vel_y;
  float vel_rotation;
public:
  sf::RectangleShape body;
  virtual void move() = 0;
};
