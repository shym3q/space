#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../base.hpp"

class Player : public Entity {
public:
  Player();
  void update() override;
  const bool collision() override;
  int health = 3;
};

#endif // !PLAYER_HPP
