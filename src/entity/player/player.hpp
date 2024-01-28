#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../base.hpp"

class Player : public Entity {
public:
  Player();
  void update() override;
  const bool collision() const override;
  bool canShoot = true;
private:
};

#endif // !PLAYER_HPP
