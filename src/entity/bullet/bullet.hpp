#ifndef BULLET_HPP
#define BULLET_HPP

#include "../base.hpp"

class Bullet : public Entity {
  sf::Clock timer;
public:
  Bullet(float, sf::Vector2f, std::vector<Entity*>*);
  std::vector<Entity*> *objects;
  void update() override;
  const bool collision() override;
};

#endif // !BULLET_HPP
