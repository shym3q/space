#ifndef BULLET_HPP
#define BULLET_HPP

#include "../base.hpp"
#include <SFML/System/Clock.hpp>

class Bullet : public Entity {
  sf::Clock timer;
public:
  Bullet(float, sf::Vector2f);
  void update() override;
  bool isAlive = true;
};

#endif // !BULLET_HPP
