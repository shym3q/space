#ifndef BULLET_HPP
#define BULLET_HPP

#include "base.hpp"

class Bullet : public Entity {
public:
  Bullet(float, sf::Vector2f);
  void update();
};

#endif // !BULLET_HPP
