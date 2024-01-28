#define TARGET_DEGREE(p, e) (RADIANS_TO_DEGREES(std::atan2(p.y-e.y, p.x-e.x)))

#include <iostream>
#include "enemy.hpp"
#include "../bullet/bullet.hpp"

Enemy::Enemy(Player *p, float x, float y, float vel) : playerReference(p) {
  body.setSize(sf::Vector2f(CHARACTER_WIDTH, CHARACTER_HEIGHT));   
  body.setFillColor(sf::Color::Red);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
  body.setOrigin(CHARACTER_X_CENTER, CHARACTER_Y_CENTER);
  body.setPosition(sf::Vector2f(x, y));
  velocity = vel;
}

void Enemy::update() {
  float enemyDegree = body.getRotation();
  auto playerPosition = playerReference->body.getPosition();
  auto enemyPosition = body.getPosition();
  auto targetDegree = TARGET_DEGREE(playerPosition, enemyPosition);
  targetDegree = (targetDegree < 0.0) ? 360.0 + targetDegree : targetDegree;
  auto diff = targetDegree - enemyDegree;
  if(diff > 180.0 || diff < -180.0)
    body.rotate(-diff * 0.0084);
  else
    body.rotate(diff * 0.0084);

  body.move(sf::Vector2f(X(velocity, enemyDegree), Y(velocity, enemyDegree)));
  edgeCheck();
}

const bool Enemy::collision() {
  isAlive = false;
  return true;
}
