#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../character.hpp"
#include "../player/player.hpp"

class Enemy : public Character {
  Player *player_reference;
public:
  Enemy(Player*, float, float);
  void update();
};

#endif // !ENEMY_HPP
