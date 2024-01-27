#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../character.hpp"
#include "../player/player.hpp"

class Enemy : public Character {
  Player *player_reference;
public:
  Enemy(Player*, float, float);
  void update();
  bool player_changed_axis = false;
  sf::Vector2f last_player_postion;
};

#endif // !ENEMY_HPP
