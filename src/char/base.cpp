#include <SFML/Graphics.hpp>

class Character {
protected:
  int x, y;
  sf::RectangleShape body;
public:
  virtual void move() = 0;
};
