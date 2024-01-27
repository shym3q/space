#define TARGET_DEGREE(p, e) (RADIANS_TO_DEGREES(std::atan2(p.y-e.y, p.x-e.x)))

#include "enemy.hpp"

Enemy::Enemy(Player *p, float x, float y) : player_reference(p) {
  body.setSize(sf::Vector2f(CHARACTER_WIDTH, CHARACTER_HEIGHT));   
  body.setFillColor(sf::Color::Red);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
  body.setOrigin(CHARACTER_X_CENTER, CHARACTER_Y_CENTER);
  body.setPosition(sf::Vector2f(x, y));
  vel = MAX_SPEED - 1.7;
}

void Enemy::update() {
  float enemy_degree = body.getRotation();

  auto player_position = player_reference->body.getPosition();
  auto enemy_position = body.getPosition();
  auto target_degree = TARGET_DEGREE(player_position, enemy_position);
  target_degree = (target_degree < 0.0) ? 360.0 + target_degree : target_degree;
  auto diff = target_degree - enemy_degree;
  if(diff > 180.0 || diff < -180.0)
    body.rotate(-diff * 0.0084);
  else
    body.rotate(diff * 0.0084);

  body.move(sf::Vector2f(X(vel, enemy_degree), Y(vel, enemy_degree)));
  edge_check();
}

