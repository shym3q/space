#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../base.hpp"

class Player : public Entity {
public:
  Player();
  void update() override;
};

#endif // !PLAYER_HPP
