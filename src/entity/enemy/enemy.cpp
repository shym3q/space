#define TARGET_DEGREE(p, e) (RADIANS_TO_DEGREES(std::atan2(p.y-e.y, p.x-e.x)))

#include "enemy.hpp"

float target_degree(sf::Vector2f, sf::Vector2f);

Enemy::Enemy(Player *p, float x, float y) : player_reference(p) {
  body.setSize(sf::Vector2f(CHARACTER_WIDTH, CHARACTER_HEIGHT));   
  body.setFillColor(sf::Color::Red);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
  body.setOrigin(CHARACTER_X_CENTER, CHARACTER_Y_CENTER);
  body.setPosition(sf::Vector2f(x, y));
  vel = MAX_SPEED - 1.8;
  vel_rotation = 0;
}

float target_degree(sf::Vector2f p, sf::Vector2f e) {
  float x = p.x - e.x;
  float y = p.y - e.y;
  return std::atan2(y, x) * 180.0 / M_PI;
}

void Enemy::update() {
  float degree = body.getRotation();

  auto player_position = player_reference->body.getPosition();
  auto enemy_position = body.getPosition();
  auto t = TARGET_DEGREE(player_position, enemy_position);
  t = (t < 0.0) ? 360.0-t : t;
  body.rotate((t-degree) * 0.006);

  body.move(sf::Vector2f(X(vel, body.getRotation()), Y(vel, body.getRotation())));
  edge_check();
}

