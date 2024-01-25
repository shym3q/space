#include <iostream>
#include "enemy.hpp"
#include "../../const.hpp"

Enemy::Enemy(Player *p) : player_reference(p) {
  body.setSize(sf::Vector2f(CHARACTER_WIDTH, CHARACTER_HEIGHT));   
  body.setFillColor(sf::Color::Red);
  body.setOutlineColor(sf::Color::Green);
  body.setOutlineThickness(1.f);
  body.setOrigin(CHARACTER_X_CENTER, CHARACTER_Y_CENTER);
  body.setPosition(sf::Vector2f(400, 400));
  vel = MAX_SPEED;
}

float deg(sf::Vector2f p, sf::Vector2f e) {
  float y = p.y - e.y;
  float x = p.x - e.x;
  return std::atan(y/x) * 180.0 / M_PI;
}

void Enemy::update() {
  int degree = body.getRotation();
  body.move(sf::Vector2f(X(vel, degree), Y(vel, degree)));
  body.rotate(vel_rotation);

  if(body.getPosition().x < LEFT_LIMIT)
    body.move(sf::Vector2f(RIGHT_LIMIT+CHARACTER_WIDTH, 0));
  if(body.getPosition().x > RIGHT_LIMIT)
    body.move(sf::Vector2f(-(RIGHT_LIMIT+CHARACTER_WIDTH), 0));
  if(body.getPosition().y < UPPER_LIMIT)
    body.move(sf::Vector2f(0, LOWER_LIMIT+CHARACTER_WIDTH));
  if(body.getPosition().y > LOWER_LIMIT)
    body.move(sf::Vector2f(0, -(LOWER_LIMIT+CHARACTER_WIDTH)));
  auto d = deg(player_reference->body.getPosition(), body.getPosition());
  body.setRotation(d);
}

