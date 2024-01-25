#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../character.hpp"

class Player : public Character {
public:
  Player();
  void update();
};

#endif // !PLAYER_HPP
