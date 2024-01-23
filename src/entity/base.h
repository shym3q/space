#include <SFML/Graphics.hpp>

class Entity {
protected:
  int x, y;
public:
  sf::RectangleShape body;
  virtual void move() = 0;
};
