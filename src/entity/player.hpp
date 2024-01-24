#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "base.hpp"
#include "bullet.hpp"
#include <vector>

class Player : public Entity {
public:
  std::vector<Bullet> bullets;
  Player();
  void update();
  bool shot = false;
};

#endif // !PLAYER_HPP
