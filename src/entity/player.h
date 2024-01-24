#ifndef PLAYER_H
#define PLAYER_H

#include "base.h"

class Player : public Entity {
public:
  Player();
  void init();
  void move();
};

#endif // !PLAYER_H
