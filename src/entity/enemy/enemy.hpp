#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../character.hpp"

class Enemy : public Character {
public:
  Enemy();
  void update();
};

#endif // !ENEMY_HPP
