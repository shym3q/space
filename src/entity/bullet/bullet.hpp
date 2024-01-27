#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/System/Clock.hpp>
#include "../base.hpp"

class Bullet : public Entity {
  sf::Clock timer;
public:
  Bullet(float, sf::Vector2f);
  void update() override;
};

#endif // !BULLET_HPP
