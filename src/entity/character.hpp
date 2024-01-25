#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "base.hpp"
#include "bullet/bullet.hpp"
#include <vector>

class Character : public Entity {
public:
  virtual void update() = 0;
  std::vector<Bullet> bullets;
  bool shot = false;
};

#endif // !CHARACTER_HPP
