#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../character.hpp"
#include "../player/player.hpp"

class Enemy : public Character {
  Player *playerReference;
public:
  Enemy(Player*, float, float, float);
  void update() override;
};

#endif // !ENEMY_HPP
