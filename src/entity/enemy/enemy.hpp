#ifndef ENEMY_HPP
#define ENEMY_HPP

// #include "../base.hpp"
#include "../player/player.hpp"

class Enemy : public Entity {
  Player *playerReference;
public:
  Enemy(Player*, float, float, float);
  void update() override;
  const bool collision() override;
};

#endif // !ENEMY_HPP
