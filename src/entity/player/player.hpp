#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../character.hpp"

class Player : public Character {
public:
  Player();
  void update() override;
};

#endif // !PLAYER_HPP
